package hello.hellospring.controller;

import hello.hellospring.service.MemberService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;

@Controller
public class MemberController {
    // [컨포넌트 스캔과 자동 의존관계 설정]
    // 멤버컨트롤러가 멤버서비스를 통해 회원 서비스를 통제 - 컨트롤러가 서비스를 의존
    // 스프링은 @Controller, Service, Repository 어노테이션이 붙은 클래스를 관리하므로 이 안에서 스프링 기능이 마음껏 동작
    // 컨트롤러가 외부 요청을 받고, 서비스가 비즈니스 로직을 만들고, 리파지토리가 저장

    private final MemberService memberService;

    // 의존관계 주입 (스프링이 자동으로)
    // @Autowired는 스프링이 관리하는 객체여야만 연결해준다
    @Autowired
    public MemberController(MemberService memberService) {
        this.memberService = memberService;
    }
}
