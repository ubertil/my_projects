package com.area.webserver.model;

import com.fasterxml.jackson.annotation.JsonView;
import com.area.webserver.web.Views;

import javax.persistence.*;

/**
 * Database representation of web Task entity
 */
@Entity
@Table(name = "task")
public class Task {
    @JsonView(Views.Public.class)
    private Long id;

    /**
     * The id of the user that created the task
     */
    @JsonView(Views.Public.class)
    private Long user;

    /**
     * User description of the task
     */
    @JsonView(Views.Public.class)
    private String description;

    /**
     * The name of the action
     */
    @JsonView(Views.Public.class)
    private String action_name;

    /**
     * Specification of the user on the action
     */
    @JsonView(Views.Public.class)
    private String action_field;

    /**
     * The name of the reaction
     */
    @JsonView(Views.Public.class)
    private String reaction_name;

    /**
     * Specification of the user on the reaction
     */
    @JsonView(Views.Public.class)
    private String reaction_field;

    /**
     * Boolean to tell if task should be active
     */
    @JsonView(Views.Public.class)
    private Boolean activated;

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Long getUser() {
        return user;
    }

    public void setUser(Long user) {
        this.user = user;
    }

    public String getAction_name() { return this.action_name; }

    public String getDescription() { return description; }

    public void setDescription(String description) { this.description = description; }

    public void setAction_name(String action_name) { this.action_name = action_name; }

    public String getAction_field() { return this.action_field; }

    public void setAction_field(String action_field) { this.action_field = action_field; }

    public String getReaction_name() { return this.reaction_name; }

    public void setReaction_name(String reaction_name) { this.reaction_name = reaction_name; }

    public String getReaction_field() { return this.reaction_field; }

    public void setReaction_field(String reaction_field) { this.reaction_field = reaction_field; }

    public Boolean getActivated() { return activated; }

    public void setActivated(Boolean activated) { this.activated = activated; }
}
