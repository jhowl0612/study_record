package kr.re.kitri.fi;

@FunctionalInterface
public interface NewInterface {

    // 인터페이스에서 선언된 변수는 마킹하지 않더라도 public static final
    // 보통 상수를 정의 한다
    public static final int A = 3;

    // abstract 메소드가 단 하나이기 때문에 펑셔널 인터페이스!
    public abstract int add(int a, int b);

    // 인터페이스 메소드는 바디를 가질 수 없지만, default를 붙이면 가능
    // default 는 인터페이스 메서드가 구현을 할 수 있게 하며, 여러 개 존재하면 오류 발생 가능
    default public int sub(int a, int b) {
        int result = div(a,b);
        return a-b;
    }

    static int mul(int a, int b){
        return a*b;
    }

    // private도 가능. 내부 호출도 가능.
    private int div(int a, int b){
        return a / b;
    }
}
