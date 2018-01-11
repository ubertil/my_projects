/**
 * \file        ModuleManager.cs
 * \author      WTF Corp
 * \version     1.0
 * \date        26 Novembre 2017
 * \brief       Classe de gestion de modules
 *
 * \details     Cette classe permet de gérer les modules
 * dans un thread indépendant.
 * 
 */
 
 using System;
using System.Collections.Generic;
using System.Threading;
using Modules.action.bourse;
using Modules.action.dealabs;
using Modules.action.twitch;
using Modules.action.twitter;
using Modules.action.gmail;
using Modules.reaction.gmail;
using Modules.reaction.system;
using Webserver.Models;
using Webserver.Models.Account;
using Newtonsoft.Json;

namespace Modules
{
    public class ModuleManager
    {
        private static Dictionary<string, string> actions = new Dictionary<string, string>
        {
            {"CheckBourse", "Verifier les evolutions d'une action en bourse"},
            {"CheckNews", "Verifier les nouveaux produits dealabs"},
            {"CheckMail", "Verifier la reception des emails Gmail"},
            {"CheckOnline", "Verifier si un Twitch est connecte"},
            {"CheckTweet", "Verifier si une personne a tweete"}
        };
        private static Dictionary<string, string> reactions = new Dictionary<string, string>
        {
            {"SendEmail", "Envoyer un mail"},
            {"PrintLine", "Dev mode verbose"}
        };
        private static Dictionary<string, Module> moduleInfo = new Dictionary<string, Module>
        {
            {"CheckBourse", new CheckBourse() },
            {"CheckNews", new CheckNews() },
            {"CheckMail", new CheckMail() },
            {"CheckOnline", new CheckOnline() },
            {"CheckTweet", new CheckTweet() },
            {"SendEmail", new SendEmail() },
            {"PrintLine", new PrintLine() }
        };
        private static Dictionary<string, string> moduleWarning = new Dictionary<string, string>
        {
            // {"CheckEmail", "Assurez vous d'avoir activé l'option ici : https://myaccount.google.com/lesssecureapps"}
        };

        private static int TIMER = 1000;

        private Dictionary<long, Action> tasks = new Dictionary<long, Action>();
        private Thread thread;
        private bool running = false;

        public ModuleManager()
        {
            this.thread = new Thread(this.run);
        }

        public static Dictionary<string, string> getActions()
        {
            return ModuleManager.actions;
        }

        public static Dictionary<string, string> getReactions()
        {
            return ModuleManager.reactions;
        }

        public static List<string> getFields(string moduleName)
        {
            if (ModuleManager.moduleInfo.ContainsKey(moduleName))
                return ModuleManager.moduleInfo[moduleName].getFields();
            return null;
        }

        public static string getWarning(string moduleName)
        {
            if (ModuleManager.moduleWarning.ContainsKey(moduleName))
                return ModuleManager.moduleWarning[moduleName];
            return null;
        }

        public void start()
        {
            this.thread.Start();
        }

        /**
        * \brief   Lance le Module Manager
        * \details Lance une boucle qui met à jour la liste d'action et
        *          vérifie si des actions ont été faites.
        *          Si oui éxecute les réactions correspondantes.
        * \return   \e void
        */
        public void run()
        {
            this.running = true;
            while (this.running)
            {
                Thread.Sleep(ModuleManager.TIMER);
                Console.WriteLine("New Turn");
                TaskRepository repo = new TaskRepository(AccountContext.Instance());
                List<Webserver.Models.Account.TaskModel> tasks = repo.GetTasksActivated();
                this.updateTaskList(tasks);
                this.removingDeadTask(tasks);
                foreach (Action a in this.tasks.Values)
                {
                    a.update();
                }
                Console.WriteLine("");
            }
        }

        public bool isRunning()
        {
            return this.running;
        }

        public void endManager()
        {
            this.running = false;
        }

        public void join()
        {
            this.thread.Join();
        }

        /**
        * \brief   Crée une instance d'action
        * \details Crée une instance d'action en fonction du nom passé en paramètre.
        * \param    action      le nom de l'action à créer
        * \return   \e Action
        */
        private Action getActionFromName(string action)
        {
            switch (action)
            {
                case "CheckBourse":
                    return new CheckBourse();
                case "CheckNews":
                    return new CheckNews();
                case "CheckMail":
                    return new CheckMail();
                case "CheckOnline":
                    return new CheckOnline();
                case "CheckTweet":
                    return new CheckTweet();
            }
            return null;
        }

        /**
        * \brief   Crée une instance de reaction
        * \details Crée une instance de reaction en fonction du nom passé en paramètre.
        * \param    action      le nom de la reaction à créer
        * \return   \e Reaction
        */
        private Reaction getReactionFromName(string reaction)
        {
            switch (reaction)
            {
                case "SendEmail":
                    return new SendEmail();
                case "PrintLine":
                    return new PrintLine();
            }
            return null;
        }

        /**
        * \brief   Met à jour la liste d'action
        * \details regarde si des nouvelles actions on été créée et les ajoutes en conséquence
        * \param    taskList      la liste d'action en bdd
        * \return   \e void
        */
        private void updateTaskList(List<TaskModel> taskList)
        {

            foreach (TaskModel task in taskList)
            {
                if (!this.tasks.ContainsKey(task.Id))
                {
                    this.addTask(task);
                }
            }
        }

        /**
        * \brief   Ajoute une action à la liste d'action
        * \details Récupère une instance d'action, initialise ses champs et l'ajoute
        *          à la liste d'action du Module Manager
        * \param    task      l'action en bdd à créer
        * \return   \e void
        */
        private void addTask(TaskModel task)
        {
            Action action = this.getActionFromName(task.ActionName);
            Reaction reaction = this.getReactionFromName(task.ReactionName);
            this.setModuleFields(action, task.ActionFields);
            this.setModuleFields(reaction, task.ReactionFields);
            action.addReaction(reaction);
            this.tasks.Add(task.Id, action);
        }

        /**
        * \brief   Initialise les champs d'un module
        * \details Récupère les champs en json et les formates pour le module
        * \param    module      le module à initaliser
        * \param    fields      le json des champs
        * \return   \e void
        */
        private void setModuleFields(Module module, string fields)
        {
            module.setField(JsonConvert.DeserializeObject<Dictionary<string, string>>(fields));
        }

        /**
        * \brief   Supprime une action
        * \details Parcours la liste d'action en bdd et vérifie si une action n'a pas 
        *          disparue. Si oui la supprime
        * \param    taskList      La liste d'action en bdd
        * \return   \e void
        */
        private void removingDeadTask(List<TaskModel> taskList)
        {
            List<long> to_delete = new List<long>();
            foreach (long taskid in this.tasks.Keys)
            {
                if (!this.taskExist(taskid, taskList))
                {
                    to_delete.Add(taskid);
                }
            }
            foreach (long a in to_delete)
                this.tasks.Remove(a);
        }

        /**
        * \brief   Vérifie si une action existe
        * \details Parcours la liste d'action de la bdd et vérifie si une action existe
        * \param    id      l'id de l'action à vérifier
        * \param    tasks    la liste d'action en bdd
        * \return   \e void
        */
        private bool taskExist(long id, List<TaskModel> tasks)
        {
            foreach (TaskModel task in tasks)
            {
                if (task.Id == id)
                    return true;
            }
            return false;
        }
    }
}
