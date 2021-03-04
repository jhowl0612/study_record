package hello.hellospring.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {

    // MVC와 템플릿 엔진
    @GetMapping("hello") // 사이트메인/hello 주소
    public String hello(Model model) {   // 모델 - MVC의 M
        model.addAttribute("data", "hello!!"); // 모델에 키:값 형태 속성 담기

        return "hello"; // resources/templates 가서 hello를 렌더링하며, 전술한 model을 함께 넘김
    }

    // MVC와 템플릿 엔진 - 파라미터 반영
    @GetMapping("hello-mvc") // RequestParam - 외부에서 url 파라미터 받기
    public String helloMvc(@RequestParam("name") String name, Model model) {
        // helloMvc(@RequestParam(value = "name", required = false)
        // required = false 값이 필수가 아님 설정
        // RequestParam 괄호 안에서 Ctrl+P 누르면 들어갈수 있는 인자와 인자없을때의 기본값을 표시함

        model.addAttribute("name",name);
        return "hello-template";
    }

    // API ? - 단순 문자열 반환
    @GetMapping("hello-string")
    @ResponseBody // http response의 body에 데이터를 직접 넣겠다는 뜻
    public String helloString(@RequestParam("name") String name) {
        return "hello " + name; // hello spring. html이 아니라 문자열을 그대로 반환
    }

    // API - json 반환
    @GetMapping("hello-api")
    @ResponseBody
    public Hello helloApi(@RequestParam("name") String name) {
        Hello hello = new Hello(); // 객체 생성
        hello.setName(name);    // 객체에 값 담기
        return hello;   // 객체 반환 - hello(name:spring)
    }
    // @ResponseBody 상태에서 객체가 반환될 때, 기본적으로 json으로 바꾸어서 보내어짐

    // 자바 빈? 게터 세터? 프로퍼티 접근방식??
    static class Hello { // 클래스 안의 클래스. HelloController.Hello 방식으로 사용 가능
        private String name;

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }
    }

}
