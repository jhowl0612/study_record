package com.auction.store.jpa.jpo;

import com.auction.entity.IdName;
import com.auction.entity.Item;
import com.auction.entity.PricePolicy;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import javax.persistence.Entity;
import javax.persistence.Id;

@Entity
@Getter
@Setter
@NoArgsConstructor
public class ItemJpo {

    @Id
    private String id;
    private String name;
    private String description;
    private String pricePolicyJson;
    private int currentPrice;
    private String sellerId;
    private String sellerJson;

    // 생성자 작성
    public ItemJpo(Item item){
        this.id = item.getId();
        this.name = item.getName();
        this.description = item.getDescription();
        this.pricePolicyJson = item.getPricePolicy().toJson();  // PricePolicy.java에 만들어둔 tojason()
        this.currentPrice = item.getCurrentPrice();
        this.sellerId = item.getSeller().getId();
        this.sellerJson = item.getSeller().toJson();
    }

    // JPO를 도메인 객체로 변환
    public Item toDomain(){
        Item item = new Item(this.id); // 생성시에 아이디 생성하므로 setId 필요없음
        item.setName(this.name);
        item.setDescription(this.description);
        item.setPricePolicy(PricePolicy.fromJson(this.pricePolicyJson));
        item.setCurrentPrice(this.currentPrice);
        item.setSeller(IdName.fromJson(this.sellerJson));

        return item;
    }
}
