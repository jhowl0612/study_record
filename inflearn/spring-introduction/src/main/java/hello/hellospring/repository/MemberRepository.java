package hello.hellospring.repository;

import hello.hellospring.domain.Member;

import java.util.List;
import java.util.Optional;

public interface MemberRepository {
    Member save(Member member); // 회원을 저장. 저장된 회원을 반환받을 수 있게 된다
    Optional<Member> findById(Long id); // id로 회원 찾기
    Optional<Member> findByName(String name);   // null 반환을 대비한 optional
    List<Member> findAll(); // 저장된 모든 회원 리스트 반환
}
