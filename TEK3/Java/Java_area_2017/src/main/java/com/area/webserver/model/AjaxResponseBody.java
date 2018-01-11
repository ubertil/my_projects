package com.area.webserver.model;

import java.util.List;
import java.util.Map;

import com.fasterxml.jackson.annotation.JsonView;
import com.area.webserver.web.Views;

/**
 * Reprensents an AJAX response from our server to the front-side client
 */
public class AjaxResponseBody {
    @JsonView(Views.Public.class)
    String msg;

    @JsonView(Views.Public.class)
    String code;

    @JsonView(Views.Public.class)
    User user;

    @JsonView(Views.Public.class)
    List<Task> tasks;

    @JsonView(Views.Public.class)
    Map<String, String> reactions;

    @JsonView(Views.Public.class)
    Map<String, String> actions;

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User result) { this.user = result; }

    public List<Task> getTasks() { return this.tasks; }

    public void setTasks(List<Task> result) { this.tasks = result; }

    public Map<String, String> getReactions() { return reactions; }

    public void setReactions(Map<String, String> reactions) { this.reactions = reactions; }

    public Map<String, String> getActions() { return actions; }

    public void setActions(Map<String, String> actions) { this.actions = actions; }

    @Override
    public String toString() {
        return "AjaxResponseResult [msg=" + msg + ", code=" + code + ", user=" + user + "]";
    }
}