package com.exam.oauth2.controller;

import com.exam.oauth2.entity.UserEntity;
import com.exam.oauth2.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/users")
public class UserController {

    @Autowired
    private UserService userService;

    @GetMapping("/user")
    public List<UserEntity> listUser(){
        return userService.findAll();
    }

}

