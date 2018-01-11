package com.area.webserver.service;

import com.area.webserver.model.Task;

import java.util.List;

public interface TaskService {
    void save(Task task);
    void delete(Long id);
    List<Task> findAll();
    List<Task> findByUserId(Long user);
    void updateActivated(Long id);
}
