public class Casting {

    public static void main(String[] args) {

        double a = 1.1;
        double b = 1; // 정수이나 값 손실이 없으므로 실수 1.0 으로 자동 캐스팅(형번환)
        double b2 = (double) 1; // 위를 명시적으로 작성한 것
        System.out.println(b);
        System.out.println(b2);

//        int c = 1.1; // 오류
        double d = 1.1; // 인텔리센스로 변수 타입 변경

        // add casting - Double이어도 '강제'로 Integer로 바꾸는 코드. 손실을 감안하고 강행함
        // 손실이 있으므로 '명시'해야만 실행함
        int e = (int) 1.1;
        System.out.println(e);

        // 1 to String. 정수 -> 문자열 캐스팅
        String f = Integer.toString(1);
        System.out.println(f + " : " + f.getClass()); // .getClass() - 타입 출력

    }

}
