package com.auction.controller;

import com.auction.entity.User;
import com.auction.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

// 디스패쳐 서블릿에서 위임받을 컨트롤러. 임플리먼트 안 씀. 빈(bean) 클래스. 스프링 빈
@RestController  // 빈 등록. + json 형태로 데이터를 바꿔주는 컨트롤러.중요!
public class UserController {

//    @Autowired
    private UserService service;

    public UserController(UserService service){ // 스프링컨테이너를 통하여 유저스토어서비스 인식
        this.service = service;     // 생성자를 통한 주입
    }

    // 유저서비스로직 호출
    @PostMapping(value= {"", "/"}) // localhost:8080 후, 'user/' or 'user' 어느 쪽이든 동일하게 호출되도록
    public String register(@RequestBody User user){ // 받은! 데이터를 가져오도록 리퀘스트바디. + user라는 객체로서 받아옴
        return service.registerUser(user);
    }   // 아직은 메모리에 저장하므로 서버 재실행하면 지워짐

    @GetMapping(value={"", "/"})    // url은 동일하며, 메소드 방식에 따라서 결과가 달라짐.
    public List<User> findAll(){    // 자바 오브젝트(객체)
        return service.findAllUsers();
    }

    @GetMapping(value={"/{userId}"})    // 패스의 가변적인 부분. 실제 호출시엔 중괄호 생략
    public User findUserById(@PathVariable(value="userId") String id){  // userId를 String id로서 받는다.
        return service.findUser(id);
    }

    @PutMapping(value={"", "/"})        // body에 바꿀 정보 담아보내면 바꿔줌. uri는 기본 uri
    public String update(@RequestBody User user){
        return service.updateUser(user);
    }

    @DeleteMapping(value={"/{userId}"})    // 패스의 가변적인 부분. 실제 호출시엔 중괄호 생략
    public boolean deleteById(@PathVariable(value="userId") String id){  // userId를 String id로서 받는다.
        return service.deleteUser(id);
    }
}
