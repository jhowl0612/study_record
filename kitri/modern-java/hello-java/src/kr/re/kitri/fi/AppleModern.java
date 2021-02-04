package kr.re.kitri.fi;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class AppleModern {

    public static List<Apple> apples = Arrays.asList(
            new Apple("red", 100),
            new Apple("red", 150),
            new Apple("green", 200),
            new Apple("red", 300),
            new Apple("green", 120),
            new Apple("red", 100),
            new Apple("red", 110),
            new Apple("green", 400),
            new Apple("red", 200)
    );

    public static List<Apple> filterApples(List<Apple> apples, ApplePredicate p) {
        List<Apple> result = new ArrayList<>();

        for (Apple apple: apples) {
            if (p.test(apple)) {
                result.add(apple);
            }
        }
        return result;
    }

    public static void main(String[] args) {

        // 빨간 사과 필터링
        List<Apple> result1 = filterApples( apples, apple -> apple.getColor().equals("red") );
        // 녹색 사과 필터링
        List<Apple> result2 = filterApples( apples, apple -> apple.getColor().equals("green") );
        // 100그램 이상 사과 필터링
        List<Apple> result3 = filterApples( apples, apple -> apple.getWeight() >= 100 );
        // 250 미만 사과 필터링
        List<Apple> result4 = filterApples( apples, apple -> apple.getWeight() < 250 );

//        // 빨간 사과 필터링
//         List<Apple> result = filterApples(apples, new ApplePredicate() {
//             @Override
//             public boolean test(Apple apple) {
//                 return apple.getColor().equals("red");
//             }
//         });
        System.out.println(result4);
    }
}

@FunctionalInterface
interface ApplePredicate {
    boolean test(Apple apple);
}