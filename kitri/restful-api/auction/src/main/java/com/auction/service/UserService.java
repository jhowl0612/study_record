package com.auction.service;

import com.auction.entity.User;

import java.util.List;

public interface UserService {
    //
    String registerUser(User user);
    List<User> findAllUsers();
    User findUser(String id);
    String updateUser(User user);
    boolean deleteUser(String id);

}
