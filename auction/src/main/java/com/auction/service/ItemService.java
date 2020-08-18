package com.auction.service;

import com.auction.entity.Item;

import java.util.List;

public interface ItemService {
    //
    String registerItem(Item item);
    Item findItem(String id);
    List<Item> findItemsBySeller(String sellerId);
}
