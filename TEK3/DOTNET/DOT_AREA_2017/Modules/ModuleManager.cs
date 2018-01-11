using System;
using System.Collections.Generic;
using System.Threading;
using Modules.action.bourse;
using Modules.action.dealabs;
using Modules.action.twitch;
using Modules.action.twitter;
using Modules.reaction.gmail;
using Modules.reaction.system;

namespace Modules
{
    public class ModuleManager
    {
        private static Dictionary<string, string> actions = new Dictionary<string, string>
        {
            {"CheckBourse", "Verifier les evolutions d'une action en bourse"},
            {"CheckNews", "Verifier les nouveaux produits dealabs"},
            {"CheckCommit", "Verifier un commit Git"},
            {"CheckNewBranch", "Verifier une nouvelle branche Git"},
            {"CheckEmail", "Verifier la reception des emails Gmail"},
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
            //{"CheckCommit", new CheckCommit() },
            //{"CheckNewBranch", new CheckNewBranch() },
            //{"CheckEmail", new CheckEmail() },
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
                return ModuleManager.moduleInfo[moduleName].getFields(); // METTRE getFields DU MODULE EN PUBLIC
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

        public void run()
        {
            this.running = true;
            while (this.running)
            {
                // ICI ON RETRIEVE LA TASKLIST DE LA BDD
                this.updateTaskList(taskList);
                this.removingDeadTask(taskList);
                foreach (Action a in this.tasks.Values)
                {
                    a.update();
                }
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

        private Action getActionFromName(string action)
        {
            switch (action) // AJOUTER LES MODULES MANQANT
            {
                case "CheckBourse":
                    return new CheckBourse();
                case "CheckNews":
                    return new CheckNews();
                /*case "CheckCommit":
                    return new CheckCommit();
                case "CheckNewBranch":
                    return new CheckNewBranch();
                case "CheckEmail":
                    return new CheckEmail();*/
                case "CheckOnline":
                    return new CheckOnline();
                case "CheckTweet":
                    return new CheckTweet();
            }
            return null;
        }

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

        private void updateTaskList(List<Task> taskList) // j'ai repris le nom de la classe en java mais si vous changez
                                                         // oubliez pas de le faire ici
        {

            foreach (Task task in taskList)
            {
                if (!this.tasks.ContainsKey(task.getId())) // id de la bdd
                {
                    this.addTask(task);
                }
            }
        }

        private void addTask(Task task)
        {
            Action action = this.getActionFromName(task.getActionName());
            Reaction reaction = this.getReactionFromName(task.getReactionName());
            this.setModuleFields(action, task.getAction_field());
            this.setModuleFields(reaction, task.getReaction_field());
            action.addReaction(reaction);
            this.tasks.Add(task.getId(), action);
        }

        private void setModuleFields(Module module, string fields)
        {
            // ICI on set les fields des modules
            // string fields contient tous les fields en json mais
            // si l'archi des classes changent faudra pas oublier de changer ça
        }

        private void removingDeadTask(List<Task> taskList)
        {
            foreach (long taskid in this.tasks.Keys) // en gros on parcours toutes nos tasks locales
            {
                if (!this.taskDoesntExist(taskid, taskList)) // on les check individuellement par rapport a la
                                                             // tasklist de la bdd et si elle existe plus en bdd ou elle est desactivee
                                                             // on la delete
                {
                    this.tasks.Remove(taskid);
                }
            }
        } // mais en vrai pour gérer les tasks desactivees faudra faire autrement parce que la c'est deg

        private bool taskDoesntExist(long id, List<Task> tasks)
        {
            foreach (Task task in tasks)
            {
                if (task.getId() == id)
                    return (task.getActivated()) ? true : false; // task activee ou non mais si l'archi change changez ici aussi
            }
            return false;
        }
    }
}
