package com.exam.oauth2.service;

import com.exam.oauth2.entity.UserEntity;
import com.exam.oauth2.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import javax.annotation.PostConstruct;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;

@Service
public class UserService implements UserDetailsService {

    // 필드 선언
    @Autowired
    private UserRepository userRepository;

    @Autowired
    private PasswordEncoder passwordEncoder;


    //생성자가 호출되기 전에 초기화 작업, 테스트유저없으면 생성
    @PostConstruct
    public void init(){
        UserEntity testUser = userRepository.findByUsername("testUser");
        if(testUser == null){
            UserEntity user = new UserEntity();
            user.setUsername("testUser");
            user.setPassword("testPass");
            this.save(user);
        }
    }

    public List<UserEntity> findAll(){
        return userRepository.findAll();
    }

    public UserEntity save(UserEntity user){
        user.setPassword(passwordEncoder.encode(user.getPassword()));
        return userRepository.save(user);
    }

    private Collection<? extends GrantedAuthority> getAuthorities(){
        return Arrays.asList(new SimpleGrantedAuthority("ROLE_USER"));
    }

    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        UserEntity user = userRepository.findByUsername(username);
        return new User(user.getUsername(), user.getPassword(), getAuthorities());
    }
}
