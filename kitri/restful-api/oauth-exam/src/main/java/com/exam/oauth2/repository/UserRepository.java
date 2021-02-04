package com.exam.oauth2.repository;

import com.exam.oauth2.entity.UserEntity;
import org.springframework.data.jpa.repository.JpaRepository;

// JPO를 따로 만들지 않고 UserEntity 바로 연결. 레이어에 유저를 저장하기 위한 인터페이스
public interface UserRepository extends JpaRepository<UserEntity, Long> {
    
    UserEntity findByUsername(String username);
}
