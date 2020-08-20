package com.auction.store.jpa.repository;

import com.auction.store.jpa.jpo.ItemJpo;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

// 기본적인 메소드 자동 구현됨 save, findAll 등
public interface ItemRepository extends JpaRepository<ItemJpo, String> {
    // 특수한 메소드는 여기 작성
    // 메소드 이름을 기준으로 JPA가 쿼리를 만들어 줌
    List<ItemJpo> findAllBySellerId(String sellerId);
}
