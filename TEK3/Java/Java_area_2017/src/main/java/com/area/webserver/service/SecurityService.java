package com.area.webserver.service;

public interface SecurityService {
    String findLoggedInUsername();
    void autologin(String username, String password);
}
