package com.area.modules;

import com.area.modules.action.bourse.CheckBourse;
import com.area.modules.action.dealabs.CheckNews;
import com.area.modules.action.git.CheckCommit;
import com.area.modules.action.git.CheckNewBranch;
import com.area.modules.action.gmail.CheckEmail;
import com.area.modules.action.twitch.CheckOnline;
import com.area.modules.action.twitter.CheckTweet;
import com.area.modules.reaction.gmail.SendEmail;
import com.area.modules.reaction.system.PrintLine;
import com.area.webserver.model.Task;
import com.area.webserver.service.TaskService;
import org.json.JSONException;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.*;

public class ModuleManager extends Thread {
    private static final Map<String, String> actions = new HashMap<String, String>() {{
        put("CheckBourse", "Verifier les evolutions d'une action en bourse");
        put("CheckNews", "Verifier les nouveaux produits dealabs");
        put("CheckCommit", "Verifier un commit Git");
        put("CheckNewBranch", "Verifier une nouvelle branche Git");
        put("CheckEmail", "Verifier la reception des emails Gmail");
        put("CheckOnline", "Verifier si un Twitch est connecte");
        put("CheckTweet", "Verifier si une personne a tweete");
    }};
    private static final Map<String, String> reactions = new HashMap<String, String>(){{
        put("SendEmail", "Envoyer un mail");
        put("PrintLine", "Dev mode verbose");
    }} ;
    private static final Map<String, Module> moduleInfo = new HashMap<String, Module>() {{
        put("CheckBourse", new CheckBourse());
        put("CheckNews", new CheckNews());
        put("CheckCommit", new CheckCommit());
        put("CheckNewBranch", new CheckNewBranch());
        put("CheckEmail", new CheckEmail());
        put("CheckOnline", new CheckOnline());
        put("CheckTweet", new CheckTweet());
        put("SendEmail", new SendEmail());
        put("PrintLine", new PrintLine());
    }};

    private static final Map<String, String> moduleWarning = new HashMap<String, String>() {{
        put("CheckEmail", "Assurez vous d'avoir activé l'option ici : https://myaccount.google.com/lesssecureapps");
        put("SendEmail", "Assurez vous d'avoir activé l'option ici : https://myaccount.google.com/lesssecureapps");
    }};

    private static final int TIMER = 1000;
    private boolean running = false;
    private Map<Long, Action> tasks = new HashMap<Long, Action>();
    @Autowired
    private TaskService taskService;

    public static Map<String, String> getActions() {
        return ModuleManager.actions;
    }

    public static Map<String, String> getReactions() {
        return ModuleManager.reactions;
    }

    public static List<String> getFields(String moduleName) {
        if (ModuleManager.moduleInfo.get(moduleName) != null)
            return ModuleManager.moduleInfo.get(moduleName).getFields();
        return null;
    }

    public static String getWarning(String moduleName) {
        if (ModuleManager.moduleWarning.get(moduleName) != null)
            return ModuleManager.moduleWarning.get(moduleName);
        return null;
    }


    @Override
    public void run() {
        this.running = true;
        List<Task> taskList;

        while (this.running) {
            taskList = this.retrieveTaskList();
            this.updateActionList(taskList);
            this.removingDeadTask(taskList);
            for (Action a : this.tasks.values()) {
                a.update();
            }
            try {
                Thread.sleep(ModuleManager.TIMER);
            }
            catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return ;
            }
        }
    }

    public boolean isRunning() {
        return this.running;
    }

    public void endManager() {
        this.running = false;
    }

    private boolean taskAlreadyExist(long id) {
        for (long taskId : this.tasks.keySet())
            if (taskId == id)
                return true;
        return false;
    }

    private void updateActionList(List<Task> taskList) {

        for (Task task : taskList) {
            if (!this.taskAlreadyExist(task.getId())) {
                this.addTask(task);
            }
        }
    }

    private void addTask(Task task) {
        Action action = this.getActionFromName(task.getAction_name());
        Reaction reaction = this.getReactionFromName(task.getAction_name());
        this.setModuleFields(action, task.getAction_field());
        this.setModuleFields(reaction, task.getReaction_field());
        action.addReaction(reaction);
        this.tasks.put(task.getId(), action);
    }

    private Action getActionFromName(String action) {
        switch (action) {
            case "CheckBourse":
                return new CheckBourse();
            case "CheckNews":
                return new CheckNews();
            case "CheckCommit":
                return new CheckCommit();
            case "CheckNewBranch":
                return new CheckNewBranch();
            case "CheckEmail":
                return new CheckEmail();
            case "CheckOnline":
                return new CheckOnline();
            case "CheckTweet":
                return new CheckTweet();
        }
        return null;
    }

    private Reaction getReactionFromName(String reaction) {
        switch (reaction) {
            case "SendEmail":
                return new SendEmail();
            case "PrintLine":
                return new PrintLine();
        }
        return null;
    }

    private void setModuleFields(Module module, String fields) {
        Map<String, String> f = new HashMap<String, String>();
        String param;
        try {
            JSONObject jsonFields = new JSONObject(fields);
            Iterator<String> keys = jsonFields.keys();

            while (keys.hasNext()) {
                param = keys.next();
                param.replace("action_", "");
                param.replace("reaction_", "");
                f.put(param, jsonFields.getString(param));
            }
            module.setField(f);
        }
        catch (JSONException e) {

        }
    }

    private void removingDeadTask(List<Task> taskList) {
        for (long taskid : this.tasks.keySet()) {
            if (!this.taskDoesntExist(taskid, taskList)) {
                this.tasks.remove(taskid);
            }
        }
    }

    private boolean taskDoesntExist(long id, List<Task> tasks) {
        for (Task task : tasks) {
            if (task.getId() == id)
                return (task.getActivated()) ? true : false;
        }
        return false;
    }

    private List<Task> retrieveTaskList() {
        return null;
    }

}
