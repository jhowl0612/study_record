package com.auction.store.jpa;

import com.auction.entity.Item;
import com.auction.exception.NoSuchUserException;
import com.auction.store.ItemStore;
import com.auction.store.jpa.jpo.ItemJpo;
import com.auction.store.jpa.jpo.UserJpo;
import com.auction.store.jpa.repository.ItemRepository;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.NoSuchElementException;
import java.util.Optional;
import java.util.stream.Collectors;

@Repository
public class ItemJpaStoreLogic implements ItemStore {

    private ItemRepository repository;
    
    // 주입을 위해 생성자 정의
    public ItemJpaStoreLogic(ItemRepository repository){
        this.repository = repository;
    }
    
    // ItemStore.java의 메소드 호출
    @Override
    public String create(Item item) {
        return repository.save(new ItemJpo(item)).getId();
    }

    @Override
    public Item retrieve(String id) {
        Optional<ItemJpo> itemJpo = repository.findById(id);
        if(!itemJpo.isPresent()){
            // 기본제공되는 예외처리
            throw new NoSuchElementException(String.format("Item(%s) is not found", id));
        }
        return itemJpo.get().toDomain();
    }

    @Override
    public List<Item> retrieveAllBySeller(String sellerId) {

        List<ItemJpo> itemJpos = repository.findAllBySellerId(sellerId);
        // 람다와 stream
        return itemJpos.stream().map(ItemJpo::toDomain).collect(Collectors.toList());
    }

    @Override
    public String update(Item item) {
        return repository.save(new ItemJpo(item)).getId();
    }

    @Override
    public boolean delete(String itemId) {
        // 있으면, 삭제 후 결과 반환
        // 없으면, 예외 처리
        Optional<ItemJpo> itemJpo = repository.findById(itemId);
        if( !itemJpo.isPresent() ){ // findById 결과가 null일때 예외처리
            throw new NoSuchElementException(String.format("Item(%s) is not found", itemId));
        }
        repository.deleteById(itemId);
        return true;
    }
}
