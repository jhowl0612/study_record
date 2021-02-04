package com.auction.store.jpa.jpo;

import com.auction.entity.User;
import com.auction.entity.UserRole;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import javax.persistence.Entity;
import javax.persistence.Id;
import java.lang.reflect.Type;
import java.util.List;

@Entity
@Getter
@Setter
@NoArgsConstructor
public class UserJpo {

    //필드 정의
    @Id // id를 기본키로 지정
    private String id;
    private String name;
    private String rolesJson;

    // 생성자. JPO로 변환. 변환한 것이 테이블에 insert
    public UserJpo(User user){
        this.id = user.getId();
        this.name = user.getName();
        this.rolesJson = (new Gson().toJson(user.getRoles()));

    }

    // JPO를 user로 변환
    public User toDomain(){
        // 타입을 명시. 변환 결과가 될 타입
        Type type = new TypeToken<List<UserRole>>(){}.getType();

        User user = new User(this.id, this.name);

        // rolesJson을 아까 저장해 둔 type 형태로 변환
        user.setRoles((new Gson()).fromJson(rolesJson,type));

        return user;
    }

}
