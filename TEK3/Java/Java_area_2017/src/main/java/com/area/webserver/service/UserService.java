package com.area.webserver.service;

import com.area.webserver.model.User;

/**
 * Interface to represent all the services associated to the USER entity
 */
public interface UserService {
    void save(User user);
    User findByUsername(String username);
}
