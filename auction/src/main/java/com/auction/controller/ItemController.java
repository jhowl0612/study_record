package com.auction.controller;

import com.auction.entity.Item;
import com.auction.entity.User;
import com.auction.service.ItemService;
import com.auction.store.ItemStore;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.List;

@RestController
@RequestMapping("/item")
public class ItemController {

    private ItemService service;

    public ItemController(ItemService service){
        this.service = service;
    }

    // 아이템서비스로직 호출
    @PostMapping(value={"","/"})
    public String registerItem(@Valid @RequestBody Item item){
        return service.registerItem(item);
    }

    // item/nnnnnn
    @GetMapping(value={"/{itemId}"})
    public Item findItem(@PathVariable(value="itemId") String id){
        return service.findItem(id);
    }

    // item/seller/nnnnnn
    @GetMapping(value={"/seller/{sellerId}"})
    public List<Item> findItemsBySeller(@PathVariable(value="sellerId") String sellerId){
        return service.findItemsBySeller(sellerId);
    }

    @PutMapping(value={"", "/"})        // body에 바꿀 정보 담아보내면 바꿔줌. uri는 기본 uri
    public String update(@RequestBody Item item){
        return service.updateItem(item);
    }

    @DeleteMapping(value={"/{userId}"})    // 패스의 가변적인 부분. 실제 호출시엔 중괄호 생략
    public boolean deleteById(@PathVariable(value="userId") String id){  // userId를 String id로서 받는다.
        return service.deleteItem(id);
    }



}
