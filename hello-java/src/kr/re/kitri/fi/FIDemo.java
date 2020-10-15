package kr.re.kitri.fi;

public class FIDemo {

    public static int calc(NewInterface ni, int a, int b){
        return ni.add(a,b);
    }

    public static void main(String[] args) {
        int result = calc((a, b) -> a + b, 3, 4);
        System.out.println(result);
    }

    // 어나니머스. 2.
//    public static void main(String[] args) {
//        int result = calc(new NewInterface() {
//            @Override
//            public int add(int a, int b) {
//                return a + b;
//            }
//        }, 3, 4);
//        System.out.println(result);
//    }

    // 제일 구식. 1. 따로 클래스 만글기
//    static class MyNewInterface implements NewInterface {
//
//        @Override
//        public int add(int a, int b) {
//            return a + b;
//        }
//    }
}
