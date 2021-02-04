package kr.re.kitri.stream;

import java.util.stream.LongStream;

public class StreamRange {
    public static void main(String[] args) {
        LongStream.rangeClosed(1, 100) // range는 99까지, rangeClosed는 100까지
                .forEach(System.out::println);


    }
}
