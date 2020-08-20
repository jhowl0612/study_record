package com.auction.service.logic;

import com.auction.entity.Item;
import com.auction.entity.User;
import com.auction.entity.UserRole;
import com.auction.service.ItemService;
import com.auction.store.ItemStore;
import com.auction.store.UserStore;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ItemServiceLogic implements ItemService {

    private ItemStore itemStore;
    private UserStore userStore;

    // 생성자 작성. 판매자 확인 위해 두 개 필요.
    public ItemServiceLogic(ItemStore itemStore, UserStore userStore){
        this.itemStore = itemStore;
        this.userStore = userStore;
    }

    @Override
    public String registerItem(Item item) {
        User user = userStore.retrieveUserById(item.getSeller().getId());
        if(user.hasRole(UserRole.Seller)){
            // throw new HasNotRoleException
        }
        this. itemStore.create(item);
        return item.getId();
    }

    @Override
    public Item findItem(String id) {
        return itemStore.retrieve(id);
    }

    @Override
    public List<Item> findItemsBySeller(String sellerId) {
        return itemStore.retrieveAllBySeller(sellerId);
    }

    @Override
    public String updateItem(Item item) {
        return itemStore.update(item);
    }

    @Override
    public boolean deleteItem(String id) {
        return itemStore.delete(id);
    }

}
