package kr.re.kitri.stream;

import java.awt.desktop.AboutEvent;
import java.util.Arrays;
import java.util.stream.DoubleStream;
import java.util.stream.IntStream;

public class StreamArray {
    public static void main(String[] args) {
        // list가 아니라 array를 사용하여 프리미티브 타입을 넣음
        // list에 넣으려면 boxing해야 하므로
        int[] numbers = {1, 2, 3, 4, 5};
        double[] doubles = {1.0, 2.0, 3.0};
        
        
        // 프리미티브 타입 특화 스트림이 만들어짐. 처리 속도 상승
        //IntStream
        //.boxed() // 특화 스트림을 일반 스트림으로 변경
        // .sum(), average() 등 집계 연산 바로 가능
        long count = Arrays.stream(numbers).count();
        System.out.println(count);

        DoubleStream stream1 = Arrays.stream(doubles);
    }
}

