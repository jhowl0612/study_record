package hello.hellospring.repository;

import hello.hellospring.domain.Member;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface SpringDataJpaMemberRepository extends JpaRepository<Member, Long>, MemberRepository {
    // 인터페이스가 인터페이스를 받을 때는 implements가 아니라 extends
    // <타겟이름, PK자료형식>

    // 스프링데이터JPA가 JpaRepository(JPA에서 제공)를 받을 경우 구현체 자동생성, 스프링빈등록

    @Override
    Optional<Member> findByName(String name);
    // select m from Member m where m.name = ?
    // 자동으로 쿼리 짜 줌. 여기서 m은 name
}
