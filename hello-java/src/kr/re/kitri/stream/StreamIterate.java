package kr.re.kitri.stream;

import java.util.stream.Stream;

public class StreamIterate {
    public static void main(String[] args) {
        // infinite stream
        Stream.iterate(0, e -> e + 2) // 2를 더해 가며 수 추가
                .limit(10) // 10개
                .forEach(System.out::println);

    }
}
