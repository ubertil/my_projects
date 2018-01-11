package com.area.webserver.model;

import com.area.webserver.service.TaskService;
import org.junit.Test;
import org.springframework.beans.factory.annotation.Autowired;

import static org.junit.Assert.*;

public class TaskTest {
    @Test
    public void testGetActivated() {
        Task t = new Task();
        t.setActivated(true);
        assertTrue("check la fonction getActivated", t.getActivated());
    }

    @Test
    public void testGetAction_name() {
        Task t = new Task();
        t.setAction_name("CheckBourse");
        assertEquals("check la fonction getAction_name", "CheckBourse", t.getAction_name());
    }

    @Test
    public void testGetReaction_name() {
        Task t = new Task();
        t.setReaction_name("SendEmail");
        assertEquals("check la fonction getReaction_name", "SendEmail", t.getReaction_name());
    }
}
