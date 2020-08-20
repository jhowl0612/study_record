package com.auction.store.jpa;

import com.auction.entity.User;
import com.auction.exception.NoSuchUserException;
import com.auction.store.UserStore;
import com.auction.store.jpa.jpo.UserJpo;
import com.auction.store.jpa.repository.UserRepository;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

// 유저스토어로직과 같은 기능이나, JPA를 통해 DB저장
@Repository
public class UserJpaStoreLogic implements UserStore {

    private UserRepository repository;

    public UserJpaStoreLogic(UserRepository repository){
        this.repository = repository;
    }

    @Override
    public String createUser(User user) {
        // UserRepository 인터페이스에서 구현된 기능 save
        return repository.save(new UserJpo(user)).getId();
    }

    @Override
    public List<User> retrieveAllUsers() {
        List<UserJpo> users = repository.findAll();

//        List<User> userList = new ArrayList<>();
//        for(UserJpo jpo : users){
//            userList.add(jpo.toDomain());
//        }
//        return userList;

//        return users.stream().map( user -> user.getId() ).collect(Collectors.toList());

        return users.stream().map(UserJpo::toDomain).collect(Collectors.toList());
        // users.stream().map(user -> user.getId()).collect(Collectors.toList()); 위와같음
    }

    @Override
    public User retrieveUserById(String id) {
        // 널체크 문제. 옵셔널이란 접두사로 캡슐화
        Optional<UserJpo> userJpo = repository.findById(id);

        // .isPresent() - 값이 있는가? 불린값으로 결과도출
        if(!userJpo.isPresent()){ // findById 값이 있지 않다면 = null일 상황의 예외처리
            throw new NoSuchUserException(String.format("User(%s) is not found", id));
        }

        return userJpo.get().toDomain();
    }

    @Override
    public boolean existsUserByName(String name) {
        return repository.existsByName(name);
    }

    @Override
    public String modifyUser(User user) {
        return repository.save(new UserJpo(user)).getId();
    }

    @Override
    public boolean removeUser(String id) {
        // user 검색
        // 있으면, 삭제 후 결과 반환
        // 없으면, 예외 처리
        Optional<UserJpo> userJpo = repository.findById(id);
        if( !userJpo.isPresent() ){ // findById 결과가 null일때 예외처리
            throw new NoSuchUserException(String.format("User(%s) is not found", id));
        }
        repository.deleteById(id);
        return true;
    }
}
