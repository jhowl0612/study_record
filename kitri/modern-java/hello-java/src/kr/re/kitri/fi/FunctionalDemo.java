package kr.re.kitri.fi;

public class FunctionalDemo {
    public static void main(String[] args) {
        System.out.println("Main Thread start...");

        // 3. 람다식
        Thread t = new Thread(() -> {
                System.out.println("MyThread running");
        });

//    // new thread 안에 바로 선언 (2)
//        Thread t = new Thread(new Runnable(){
//            //Runnable : 추상 메소드가 하나만 있는 인터페이스, Functional 인터페이스
//            //위는 람다식으로 쓸 수 있음
//            @Override
//            public void run() {
//                System.out.println("MyThread running");
//            }
//        });

        t.start();

        System.out.println("Main Thread end...");
    }
//    // 바깥에 클래스 따로 준비 (1. 제일 구식)
//    static class MyThread implements Runnable {
//        @Override
//        public void run() {
//            System.out.println("MyThread running");
//        }
//    }
}
