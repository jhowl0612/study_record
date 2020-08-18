package com.auction.store;

import com.auction.entity.User;

import java.util.List;

public interface UserStore {
    //
    String createUser(User user);   // 유저 가입
    List<User> retrieveAllUsers();  // 유저 전체 조사
    User retrieveUserById(String id);   // 이름으로 특정유저 검색
    boolean existsUserByName(String name);  // 동명이인 조사

    String modifyUser(User user);   // 유저 변경
    boolean removeUser(String id);  // 유저 탈퇴
}
