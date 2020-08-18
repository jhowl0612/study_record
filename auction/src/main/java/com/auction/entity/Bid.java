package com.auction.entity;

import com.google.gson.Gson;
import lombok.Getter;
import lombok.Setter;

import java.util.UUID;

@Getter
@Setter
public class Bid {
    //
    private String id;
    private IdName item;
    private IdName bidder;
    private int price;
    private long time;

    public Bid() {
        //
        this.id = UUID.randomUUID().toString();
        this.time = System.currentTimeMillis();
    }

    public Bid(String id) {
        //
        this();
        this.id = id;
    }

    public static Bid sample() {
        //
        Item item = Item.sample();
        User bidder = User.sampleBidder();

        Bid sample = new Bid();
        sample.setBidder(new IdName(bidder.getId(), bidder.getName()));
        sample.setItem(new IdName(item.getId(), item.getName()));
        sample.setPrice(item.getPricePolicy().getStartPrice());
        return sample;
    }

    public static void main(String[] args) {
        //
        System.out.println((new Gson()).toJson(Bid.sample()));
    }
}
