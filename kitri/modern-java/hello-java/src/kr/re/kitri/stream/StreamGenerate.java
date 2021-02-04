package kr.re.kitri.stream;

import java.util.stream.Stream;

public class StreamGenerate {
    public static void main(String[] args) {

        // 무한 스트림
        // 제너레이터는 서플라이어 요구. 값 입력 없음, 값 출력 있음
        Stream.generate(Math::random)
                .limit(10)
                .forEach(System.out::println);
    }
}

