package hello.hellospring.controller;

public class MemberForm {
    private String name;
    // form의 name=name인 input 값이 여기 옴

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
