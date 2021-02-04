package com.auction.store.jpa.repository;

import com.auction.store.jpa.jpo.UserJpo;
import org.springframework.data.jpa.repository.JpaRepository;

// 아무것도 안 적었지만 선언한 것만으로 DB와 연결되는 기능 구현
public interface UserRepository extends JpaRepository<UserJpo, String> {

    // save 같은 일반적인 메소드 말고 특수한 메소드가 필요할 때 여기 작성
    boolean existsByName(String name);
    
}
