package hello.hellospring.repository;

import hello.hellospring.domain.Member;
import org.springframework.stereotype.Repository;

import java.util.*;

public class MemoryMemberRepository implements MemberRepository{

    // 메모리 저장 키가 id이기 때문에 long
    // 실무에서는 동시성 문제 방지를 위해 ConcurrentHashMap을 쓴다
    private static Map<Long, Member> store = new HashMap<>();
    // 마찬가지로 동시성 문제를 위해서는 atomiclong
    private static long sequence = 0L;

    @Override
    public Member save(Member member) {
        member.setId(++sequence); // 이름은 넘어온 상태에서, id 세팅
        store.put(member.getId(), member); // 스토어(맵) 저장
        return member; // 저장 결과 반환
    }

    @Override
    public Optional<Member> findById(Long id) {
        return Optional.ofNullable(store.get(id));
    }

    @Override
    public Optional<Member> findByName(String name) {
        return store.values().stream()
                .filter(member -> member.getName().equals(name))
                .findAny();
    }

    @Override
    public List<Member> findAll() {
        // map을 list로
        // 실무에서는 List형 많이 씀
        return new ArrayList<>(store.values());
    }

    public void clearStore() {
        store.clear();
    }

}
