package com.auction.store.jpa.jpo;

import com.auction.entity.Bid;
import com.auction.entity.IdName;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import javax.persistence.Entity;
import javax.persistence.Id;

@Entity
@Getter
@Setter
@NoArgsConstructor  // JPO 만들 때는 무조건 필요. 디폴트 생성자
public class BidJpo {

    @Id
    private String id;
    private String itemId;  // 검색용
    private String itemJson;
    private String bidderId;    // 검색용
    private String bidderJson;
    private int price;
    private long time;

    public BidJpo(Bid bid){
        this.id = bid.getId();
        this.itemId = bid.getItem().getId();
        this.itemJson = bid.getItem().toJson();
        this.bidderId = bid.getBidder().getId();
        this.bidderJson = bid.getBidder().toJson();
        this.price = bid.getPrice();
        this.time = bid.getTime();
    }

    public Bid toDomain(){
        Bid bid = new Bid(this.id);
        bid.setItem(IdName.fromJson(this.itemJson));
        bid.setBidder(IdName.fromJson(this.bidderJson));
        bid.setPrice(this.price);
        bid.setTime(this.time);

        return bid;
    }


}
