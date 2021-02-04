package com.auction.store;

import com.auction.entity.Item;

import java.util.List;

public interface ItemStore {
    //
    String create(Item item);
    Item retrieve(String id);
    List<Item> retrieveAllBySeller(String sellerId);
    String update(Item item);  // 아이템 변경

    boolean delete(String id);  // 아이템 삭제
}
