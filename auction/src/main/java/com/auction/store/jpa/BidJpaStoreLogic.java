package com.auction.store.jpa;

import com.auction.entity.Bid;
import com.auction.store.BidStore;
import com.auction.store.jpa.jpo.BidJpo;
import com.auction.store.jpa.repository.BidRepository;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.NoSuchElementException;
import java.util.Optional;
import java.util.stream.Collectors;


@Repository
public class BidJpaStoreLogic implements BidStore {

    private BidRepository repository;

    public BidJpaStoreLogic(BidRepository repository){
        this.repository = repository;
    }


    @Override
    public void create(Bid bid) {
        this.repository.save(new BidJpo(bid));
    }

    @Override
    public Bid retrieveById(String id) {
        Optional<BidJpo> bidJpo = this.repository.findById(id);
        if(!bidJpo.isPresent()){
            throw new NoSuchElementException(String.format("Bid($s) is not found.", id));
        }
        return bidJpo.get().toDomain();
    }

    @Override
    public List<Bid> retrieveAllByItem(String itemId) {

        List<BidJpo> bidJpos = this.repository.findAllByItemIdOrderByTimeDesc(itemId);
        return bidJpos.stream().map(BidJpo::toDomain).collect(Collectors.toList());
    }


    @Override
    public List<Bid> retrieveAllByBidder(String bidderId) {
        List<BidJpo> bidJpos = this.repository.findAllByBidderIdOrderByTimeDesc(bidderId);
        return bidJpos.stream().map(BidJpo::toDomain).collect(Collectors.toList());
    }
}
