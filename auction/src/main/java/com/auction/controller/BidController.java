package com.auction.controller;

import com.auction.entity.Bid;
import com.auction.service.BidService;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/bid")
public class BidController {

    private BidService service;

    public BidController(BidService service){
        this.service = service;
    }

    @PostMapping(value={"", "/"})
    public void bid(@RequestBody Bid bid){
        this.service.bid(bid);
    }

    @GetMapping(value="/{bidId}")
    public Bid findBidById(@PathVariable(value="bidId") String id){
        return this.service.findBidById(id);
    }

    @GetMapping(value="/item/{itemId}")
    public List<Bid> findBidsByItem(@PathVariable(value="itemId") String itemId){
        return this.service.findBidsByItem(itemId);
    }

    @GetMapping(value="/bidder/{bidderId}")
    public List<Bid> findBidsByBidder(@PathVariable(value="bidderId") String bidderId){
        return this.service.findBidsByBidder(bidderId);
    }



}
