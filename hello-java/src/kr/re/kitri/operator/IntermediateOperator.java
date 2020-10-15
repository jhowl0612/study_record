package kr.re.kitri.operator;

import kr.re.kitri.stream.Dish;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class IntermediateOperator {
    static List<Dish> dishes = Arrays.asList(
            new Dish("pork", false, 800, "MEAT"),
            new Dish("beef", false, 700, "MEAT"),
            new Dish("chicken", false, 450, "MEAT"),
            new Dish("french fires", true, 530, "OTHER"),
            new Dish("rice", true, 300, "OTHER"),
            new Dish("spagetti", true, 400, "NOODLE"),
            new Dish("apple", true, 300, "FRUIT"),
            new Dish("melon", true, 320, "FRUIT"),
            new Dish("salmon", true, 420, "FISH"),
            new Dish("prawn", true, 420, "FISH")
    );

    public static void main(String[] args) {

        int sum = dishes.stream()
                .distinct()   // 중복 삭제
                .peek(e -> System.out.println(e))   // 모델에 tostring 메서드 만들어둬서 출력가능
                .filter(Dish::isVegeterian)   // 프레딕트를 인자로 받음 // 메소드레퍼런스 축약
                .mapToInt(e -> e.getCalrories())  // 펑션 인자, 해당 특화스트림으로 형식변경!
                .sorted() // 특화 인트스트림의 소팅은 인자 필요없이 오름차순 정렬
                .peek(e -> System.out.println(e))     // 컨슈머 인자 // 데이터를 손상시키지 않으면서 중간 상태를 로깅
                //.boxed();// 일반 스트림 Stream<Integer> 로 변경
                .sum();

        System.out.println("sesult : " + sum);

    }

}
