package kr.re.kitri.stream;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class DishHandlerModern {
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
    // 칼로리 400 이하, 칼로리 내림차순 정렬, 상위 3개 이름 출력

    public static void main(String[] args) {
        List<String> result = dishes.stream()
                .filter(dish -> dish.getCalrories() <= 400)
                .sorted((a, b) -> b.getCalrories() - a.getCalrories()) // 내림차순은 b-a
                .map(Dish::getName) // .map(dish -> dish.getName()) // dish 객체를 요리이름 Strint
                .collect(Collectors.toList());

        System.out.println(result.subList(0,3)); // 0부터 3까지만 출력
    }
}
