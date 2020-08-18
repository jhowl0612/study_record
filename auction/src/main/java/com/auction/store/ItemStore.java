package com.auction.store;

import com.auction.entity.Item;

import java.util.List;

public interface ItemStore {
    //
    public abstract void create(Item item);
    public abstract Item retrieve(String id);
    public abstract List<Item> retrieveAllBySeller(String sellerId);
    public abstract void update(Item item);
}
