package com.auction.store.logic;

import com.auction.entity.Bid;
import com.auction.entity.Item;
import com.auction.entity.User;
import com.auction.entity.UserRole;
import com.auction.service.BidService;
import com.auction.store.BidStore;
import com.auction.store.ItemStore;
import com.auction.store.UserStore;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BidServiceLogic implements BidService {
    
    private BidStore bidStore;
    private ItemStore itemStore;
    private UserStore userStore;    // bidder 롤을 갖고있는지

    public BidServiceLogic(BidStore bidStore, ItemStore itemStore, UserStore userStore){
        this.bidStore = bidStore;
        this.itemStore = itemStore;
        this.userStore = userStore;
    }


    @Override
    public void bid(Bid bid) {
        User user = userStore.retrieveUserById(bid.getBidder().getId());
        if(user.hasRole(UserRole.Bidder)){
            // throw new HasNotRoleException("");
        }
        Item item = itemStore.retrieve(bid.getItem().getId());
        if(item.isBiddablePrice(bid.getPrice())){
            // throw new NotProperBidPriceException("입찰 금액은 %d 단위입니다",
            // item.getPricePolicy().getPriceStep())
        }

        item.setCurrentPrice(bid.getPrice());
        this.bidStore.create(bid);
        this.itemStore.update(item);

    }

    @Override
    public Bid findBidById(String id) {
        return bidStore.retrieveById(id);
    }

    @Override
    public List<Bid> findBidsByItem(String itemId) {
        return bidStore.retrieveAllByItem(itemId);
    }

    @Override
    public List<Bid> findBidsByBidder(String bidderId) {
        return bidStore.retrieveAllByBidder(bidderId);
    }
}
