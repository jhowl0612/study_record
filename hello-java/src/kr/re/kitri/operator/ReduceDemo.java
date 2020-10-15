package kr.re.kitri.operator;

import kr.re.kitri.stream.Dish;

import java.util.Arrays;
import java.util.List;
import java.util.OptionalInt;

public class ReduceDemo {
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
        // meat 타입 요리 칼로리 합
        OptionalInt meat = dishes.stream()
                .filter(e -> e.getType().equals("MEAT"))
                .mapToInt(Dish::getCalrories)
                .reduce((a, b) -> a + b);

        meat.ifPresent(System.out::println);
        // ifPresent - 앞에 온 변수의 값이 있으면 실행
        meat.ifPresentOrElse(System.out::println, () -> System.out.println(0));
        // ifPresentOrElse - 앞에 온 변수의 값이 있으면 전자, 없으면 후자 실행

        // reduce에 seed값을 주지 않으면, 빈 스트림일 경우(최종값이 null)를 대비해
        // 옵셔널인트를 리턴함
        // 시드값 주면 그냥 인트
        // introduce variable 했을 때 옵셔널이 아닌 값이 나오면, null일 확률이 없는 것
        // 되도록 변수를 줄이고 모호함을 줄이도록, null이 나올 가능성을 줄이는 것이 좋음
        // null은 값이 없다, 모르겠다, 아직 계산이 안 됐다 다양한 가능성을 포함하기 때문
//        System.out.println(meat);

    }
}
