package com.auction.store.logic;

import com.auction.entity.User;
import com.auction.store.UserStore;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@Repository     // 빈 등록
public class UserStoreLogic implements UserStore {  // 유저스토어라는 인터페이스를 임플리먼츠하는 유일한 클래스가 유저스토어로직
    // "키는 스트링, 객체는 유저" 데이터 저장
    private Map<String, User> userMap;

    public UserStoreLogic(){    // 생성자로 맵 생성
        this.userMap = new HashMap<>();
    }

    // 유저 가입(생성)
    @Override
    public String createUser(User user) {
        userMap.put(user.getId(), user);
        return user.getId();
    }

    // 유저 전수조사
    @Override
    public List<User> retrieveAllUsers() {

        // 방법 1. JDK 7
//        List<User> users = new ArrayList<>();
//        for(User user : userMap.values()){    // 이터레이터로 해도 됨
//            users.add(user);
//        }
//        return users;

        // 방법 2. JDK 8 이후. 람다와 스트림 이용
        return userMap.values().stream().collect(Collectors.toList());
    }

    // id로써 유저 검색
    @Override
    public User retrieveUserById(String id) {
        return userMap.get(id);
    }

    // 동명이인이 있는지
    @Override
    public boolean existsUserByName(String name) {

        // JDK 7
//        for(User user : userMap.values()){
//            if(user.getName().equals(name)){
//                return true;
//            }
//        }
//        return false;

        // JDK 8 ~ . 위 주석 구문과 같은 기능. 람다식
        return userMap.values().stream().anyMatch(user -> user.getName().equals(name));
    }

    @Override
    public String modifyUser(User user) {
        if(retrieveUserById(user.getId()) != null){
            userMap.put(user.getId(), user);
            return user.getId();
        }
        return null;
    }

    @Override
    public boolean removeUser(String id) {
        if(userMap.remove(id) != null){
            return true;
        }
        return false;
    }
}
