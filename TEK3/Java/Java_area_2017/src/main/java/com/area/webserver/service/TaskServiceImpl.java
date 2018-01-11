package com.area.webserver.service;

import com.area.webserver.model.Task;
import com.area.webserver.repository.TaskRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class TaskServiceImpl implements TaskService {
    @Autowired
    private TaskRepository taskRepository;

    @Override
    public void save(Task task) {
        taskRepository.save(task);
    }

    @Override
    public void delete(Long id) {
        taskRepository.delete(id);
    }

    @Override
    public List<Task> findAll() {
        return taskRepository.findAll();
    }

    @Override
    public List<Task> findByUserId(Long user) {
        List<Task> tasks = taskRepository.findAll();
        List<Task> toReturn = new ArrayList<>();
        for (Task t : tasks) {
            if (t.getUser().equals(user))
                toReturn.add(t);
        }
        return (toReturn);
    }

    @Override
    public void updateActivated(Long id) {
        Task t = taskRepository.findOne(id);
        t.setActivated(!t.getActivated());
        taskRepository.save(t);
    }
}
