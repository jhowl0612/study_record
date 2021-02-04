package kr.re.kitri.collect;

import kr.re.kitri.stream.Dish;

import java.util.Arrays;
import java.util.IntSummaryStatistics;
import java.util.List;
import java.util.Map;

import static java.util.stream.Collectors.*;
// 이렇게 적어두면 groupingBy 앞에 Collectors 안 붙여도 됨

public class CollectDemo02 {
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
        // 타입으로 그룹화한 후 각 칼로리 평균 도출
        Map<String, IntSummaryStatistics> collect = dishes.stream()
                .collect(groupingBy(e -> e.getType(), summarizingInt(e -> e.getCalrories())));

        collect.forEach((key, value) -> {
            System.out.print("Type : " + key);
            System.out.println(" | Calrories : " + value.getAverage());
        });
    }
}
