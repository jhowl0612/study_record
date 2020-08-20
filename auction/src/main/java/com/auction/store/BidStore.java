package com.auction.store;

import com.auction.entity.Bid;

import java.util.List;

public interface BidStore {
    //
    void create(Bid bid);
    Bid retrieveById(String id);
    List<Bid> retrieveAllByItem(String itemId);
    List<Bid> retrieveAllByBidder(String bidderId);
}
