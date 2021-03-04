package hello.hellospring.repository;

import hello.hellospring.domain.Member;
//import org.junit.jupiter.api.Assertions;
import org.assertj.core.api.Assertions;
import org.assertj.core.api.ObjectAssert;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Test;

import java.util.List;
import java.util.Optional;

import static org.assertj.core.api.Assertions.*;

class MemoryMemberRepositoryTest {

    // MemberRepository - 인터페이스
    // MemoryMemberRepository - 구현체
    MemoryMemberRepository repository = new MemoryMemberRepository();

    @AfterEach  // 테스트 하나하나 끝날때마다 한번씩 실행
    public void afterEach() {
        repository.clearStore(); // 테스트끼리 서로를 방해하지 않도록 repo 초기화
    }

    @Test
    public void save() {
        Member member = new Member();
        member.setName("spring");

        repository.save(member);

        // optional은 get으로 값을 꺼낼수있지만 orElseGet이 좀더 추천됨. null일 때 else 구문 실행.
        Member result = repository.findById(member.getId()).get();
        //System.out.println("result = " + (result == member) );
        //Assertions.assertEquals(member, result);
        //Assertions.assertThat(member).isEqualTo(result);
        assertThat(result).isEqualTo(member);
    }

    @Test
    public void findByName() {
        Member member1 = new Member();
        member1.setName("spring1");
        repository.save(member1);

        Member member2 = new Member();
        member2.setName("spring2");
        repository.save(member2);

        Member result = repository.findByName("spring1").get();

        assertThat(result).isEqualTo(member1);
    }

    @Test
    public void findAll() {
        Member member1 = new Member();
        member1.setName("spring1");
        repository.save(member1);

        Member member2 = new Member();
        member2.setName("spring2");
        repository.save(member2);

        List<Member> result = repository.findAll();

        assertThat(result.size()).isEqualTo(2);
    }

}
