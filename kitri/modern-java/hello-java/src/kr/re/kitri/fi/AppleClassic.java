package kr.re.kitri.fi;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class AppleClassic {

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

    public static List<Apple> filterApplesByColor(List<Apple> apples, String color){
        List<Apple> result = new ArrayList<>();
        for (Apple apple: apples) {
            if (apple.getColor().equals(color)) {
                result.add(apple);
            }
        }
        return result;
    }

    public static List<Apple> filterApplesByWeight(List<Apple> apples, int weight){
        List<Apple> result = new ArrayList<>();
        for (Apple apple: apples){
            if (apple.getWeight() > weight){
                result.add(apple);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(filterApplesByWeight(apples, 150));
    }
}
