package com.auction.service;

import com.auction.entity.Item;
import com.auction.entity.User;

import java.util.List;

public interface ItemService {
    //
    String registerItem(Item item);
    Item findItem(String id);
    List<Item> findItemsBySeller(String sellerId);
    String updateItem(Item item);   // 아이템 변경
    boolean deleteItem(String id);  // 아이템 삭제
}
