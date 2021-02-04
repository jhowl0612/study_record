package com.auction.service.logic;

import com.auction.entity.User;
import com.auction.service.UserService;
import com.auction.store.UserStore;
import org.springframework.stereotype.Service;

import java.util.List;

@Service    // 스프링 빈 등록
public class UserServiceLogic implements UserService {

//    @Autowired    // 생성자 주입 방식 대신 써도 됨
    private UserStore store;    // 인터페이스 참조

    public UserServiceLogic(UserStore store){   // 스프링컨테이너를 통하여 유저스토어로직 인식
        this.store = store; // UserStoreLogic 클래스. 생성자를 통한 주입 방식
    }

    // 유저스토어로직의 메소드 호출, 호출 후 받은 데이터를 유저컨트롤러에 전달
    @Override
    public String registerUser(User user) {
        return store.createUser(user);
    }

    @Override
    public List<User> findAllUsers() {
        return store.retrieveAllUsers();
    }

    @Override
    public User findUser(String id) {
        return store.retrieveUserById(id);
    }

    @Override
    public String updateUser(User user) {
        return store.modifyUser(user);
    }

    @Override
    public boolean deleteUser(String id) {
        return store.removeUser(id);
    }
}
