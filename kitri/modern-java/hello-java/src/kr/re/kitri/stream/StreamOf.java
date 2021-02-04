package kr.re.kitri.stream;

import java.util.stream.Stream;

public class StreamOf {

    public static void main(String[] args) {
        Stream<String> hello = Stream.of("hello", "world", "a", "B", "kim");

        Stream<Integer> integerStream = Stream.of(1, 2, 3, 4, 5);

        Stream<Double> doubleStream = Stream.of(1.0, 2.0, 3.0);





    }
    
}
