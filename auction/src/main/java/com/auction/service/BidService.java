package com.auction.service;

import com.auction.entity.Bid;

import java.util.List;

public interface BidService {
    //
    void bid(Bid bid);
    Bid findBidById(String id);
    List<Bid> findBidsByItem(String itemId);
    List<Bid> findBidsByBidder(String bidderId);
}
