package com.area.webserver.web;

import com.area.modules.ModuleManager;
import com.area.webserver.model.Task;
import com.area.webserver.repository.UserRepository;
import com.area.webserver.service.TaskService;
import com.fasterxml.jackson.annotation.JsonView;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import com.area.webserver.model.AjaxResponseBody;
import com.area.webserver.model.SearchCriteria;
import com.area.webserver.model.User;

import java.util.Map;

/**
 * Class handling all of the AJAX request and their lives
 *
 * Each new entrypoint should be mapped to /api/... for better management
 */
@RestController
public class AjaxController {

    /**
     * List of users
     */
    @Autowired
    private UserRepository users;

    /**
     * List of all the users task
     */
    @Autowired
    private TaskService tasks;

    /**
     * Add a task associated to a user
     *
     * Explanation :
     * @ResponseBody, not necessary, since class is annotated with @RestController
     * @RequestBody - Convert the json data into object (SearchCriteria) mapped by field name.
     * @JsonView(Views.Public.class) - Optional, limited the json data display to client.
     *
     * @param search
     * @return json payload telling if the operation was a failure or not
     */
    @JsonView(Views.Public.class)
    @RequestMapping(value = "/api/addTask", method = RequestMethod.POST)
    public AjaxResponseBody addTaskViaAjax(@RequestBody SearchCriteria search) {
        AjaxResponseBody result = new AjaxResponseBody();
        User user = users.findByUsername(search.getUsername());
        if (user != null /*&& checkTaskCreation(search)*/) {
            result.setCode("200");
            result.setMsg("NOK");
            if (ModuleManager.getFields(search.getAction()) == null ||
                    ModuleManager.getFields(search.getReaction()) == null)
                return (result);
            for (String field : ModuleManager.getFields(search.getAction())) {
                if (!search.getActionFields().contains("action_"+field+"\""))
                    return (result);
                if (search.getActionFields().contains("action_"+field+"\":\"\""))
                    return (result);
            }
            for (String field : ModuleManager.getFields(search.getReaction())) {
                if (!search.getReactionFields().contains("reaction_"+field+"\""))
                    return (result);
                if (search.getReactionFields().contains("reaction_"+field+"\":\"\""))
                    return (result);
            }
            Task task = new Task();
            task.setUser(user.getId());
            task.setAction_name(search.getAction());
            task.setAction_field(search.getActionFields());
            task.setReaction_name(search.getReaction());
            task.setReaction_field(search.getReactionFields());
            task.setActivated(true);
            tasks.save(task);
            result.setMsg("Tâche ajouté avec succès");
        } else {
            result.setCode("204");
            result.setMsg("Erreur lors de l'ajout de votre tâche");
        }
        //AjaxResponseBody will be converted into json format and send back to client.
        return result;
    }


    @JsonView(Views.Public.class)
    @RequestMapping(value = "/api/activateTask", method = RequestMethod.POST)
    public AjaxResponseBody activateTaskViaAjax(@RequestBody SearchCriteria search) {
        AjaxResponseBody result = new AjaxResponseBody();
        User user = users.findByUsername(search.getUsername());
        if (user != null) {
            result.setCode("200");
            tasks.updateActivated(search.getTaskID());
            result.setMsg("Tâche ajoutée avec succès");
        } else {
            result.setCode("204");
            result.setMsg("Erreur lors de l'ajout de votre tâche");
        }
        return result;
    }

    /**
     * Delete a task associated to a user
     *
     * @param search
     * @return json payload telling if the operation was a failure or not
     */
    @JsonView(Views.Public.class)
    @RequestMapping(value = "/api/deleteTask", method = RequestMethod.POST)
    public AjaxResponseBody deleteTaskViaAjax(@RequestBody SearchCriteria search) {
        AjaxResponseBody result = new AjaxResponseBody();
        User user = users.findByUsername(search.getUsername());
        if (user != null && search.getTaskID() != null) {
            result.setCode("200");
            tasks.delete(search.getTaskID());
            result.setMsg("Tâche supprimé avec succès");
        } else {
            result.setCode("204");
            result.setMsg("Erreur lors de la suppression de votre tâche");
        }
        return result;
    }

    /**
     * Returns all the tasks associated to a specific user
     *
     * @param username User' username
     * @return json payload
     */
    @JsonView(Views.Public.class)
    @RequestMapping(value = "/api/getTasks", params = "username", method = RequestMethod.GET)
    public AjaxResponseBody getTasksViaAjax(@RequestParam("username") String username) {
        AjaxResponseBody result = new AjaxResponseBody();
        User user = users.findByUsername(username);
        if (user != null) {
            result.setTasks(tasks.findByUserId(user.getId()));
            result.setCode("200");
            result.setUser(user);
        } else {
            result.setCode("204");
            result.setMsg("Erreur lors de la récupération des tâches" + username);
        }
        return result;
    }

    /**
     * This method should return all the Modules available for the user
     * Module information should be formated using the AjaxResponseBody()
     *
     * @return json payload
     */
    @JsonView(Views.Public.class)
    @RequestMapping(value = "/api/getActions", method = RequestMethod.GET)
    public AjaxResponseBody getActionsViaAjax() {
        AjaxResponseBody result = new AjaxResponseBody();
        result.setCode("200");
        result.setActions(ModuleManager.getActions());
        return result;
    }

    /**
     * This method returns all the available "reactions"
     *
     * @return json payload
     */
    @JsonView(Views.Public.class)
    @RequestMapping(value = "/api/getReactions", method = RequestMethod.GET)
    public AjaxResponseBody getReactionsViaAjax() {
        AjaxResponseBody result = new AjaxResponseBody();
        result.setCode("200");
        result.setReactions(ModuleManager.getReactions());
        return result;
    }



    @JsonView(Views.Public.class)
    @RequestMapping(value = "/api/getActionFields", params = "action", method = RequestMethod.GET)
    public AjaxResponseBody getActionFieldsViaAjax(@RequestParam("action") String action) {
        AjaxResponseBody result = new AjaxResponseBody();
        result.setCode("200");
        String s = "<br /><hr /><h2>Détails de l'action:</h2>";
        if (ModuleManager.getWarning(action) != null) {
            s += "<b>Attention : " + ModuleManager.getWarning(action) + "</b><br /><br />";
        }
        for (String field : ModuleManager.getFields(action)) {
            s += "<input type=\"text\" name=\"action_"+field+"\" placeholder=\""+field+"\"> ";
        }
        result.setMsg(s);
        return result;
    }

    @JsonView(Views.Public.class)
    @RequestMapping(value = "/api/getReactionFields", params = "reaction", method = RequestMethod.GET)
    public AjaxResponseBody getReactionFieldsViaAjax(@RequestParam("reaction") String reaction) {
        AjaxResponseBody result = new AjaxResponseBody();
        result.setCode("200");
        String s = "<br /><hr /><h2>Détails de la reaction:</h2>";
        if (ModuleManager.getWarning(reaction) != null) {
            s += "<b>Attention : " + ModuleManager.getWarning(reaction) + "</b><br /><br />";
        }
        for (String field : ModuleManager.getFields(reaction)) {
            s += "<input type=\"text\" name=\"reaction_"+field+"\" placeholder=\""+field+"\"> ";
        }
        result.setMsg(s);
        return result;
    }


    /**
     * Check if sent data is valid to create a Task
     * TODO : Check if module name exists and action / reaction
     *
     * @param search The user search
     * @return Boolean
     */
    private Boolean checkTaskCreation(SearchCriteria search) {
        return (!search.getTaskDescription().equals("") && !search.getFromModuleName().equals("") &&
                !search.getToModuleName().equals("") && !search.getAction().equals("") && !search.getReaction().equals(""));
    }

    /**
     * Check if sent data is valid to delete a task
     * TODO : Check if module name exists and action / reaction
     *
     * @param search The user search
     * @return Boolean
     */
    private Boolean checkTaskDeletion(SearchCriteria search) {
        return (search.getTaskID() == 123);
    }
}