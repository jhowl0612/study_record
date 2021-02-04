package com.auction.store.jpa.repository;


import com.auction.store.jpa.jpo.BidJpo;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface BidRepository extends JpaRepository<BidJpo, String> {

    List<BidJpo> findAllByItemIdOrderByTimeDesc(String itemId);
    List<BidJpo> findAllByBidderIdOrderByTimeDesc(String bidderId);


}
