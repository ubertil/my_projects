package com.area.webserver.model;

/**
 * Class to format web JSON Search into web usable and serialized class
 * TODO : Do whatever you want with this
 */
public class SearchCriteria {
    private String  username;
    private Long    taskID;
    private String  taskDescription;
    private String  fromModuleName;
    private String  toModuleName;
    private String  action;
    private String  reaction;
    private String  actionFields;
    private String  reactionFields;

    public String getReactionFields() { return this.reactionFields; }

    public void setReactionFields(String reactionFields) { this.reactionFields = reactionFields; }

    public String getActionFields() { return this.actionFields; }

    public void setActionFields(String actionFields) { this.actionFields = actionFields; }

    public String getTaskDescription() { return taskDescription; }

    public void setTaskDescription(String taskDescription) { this.taskDescription = taskDescription; }

    public Long getTaskID() { return taskID; }

    public void setTaskID(Long taskID) { this.taskID = taskID; }

    public String getFromModuleName() { return fromModuleName; }

    public void setFromModuleName(String fromModuleName) { this.fromModuleName = fromModuleName; }

    public String getToModuleName() { return toModuleName; }

    public void setToModuleName(String toModuleName) { this.toModuleName = toModuleName; }

    public String getAction() { return action; }

    public void setAction(String action) { this.action = action; }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getReaction() { return reaction; }

    public void setReaction(String reaction) { this.reaction = reaction; }

    @Override
    public String toString() {
        return "SearchCriteria [username=" + username + "]";
    }

}