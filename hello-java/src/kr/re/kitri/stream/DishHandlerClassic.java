package kr.re.kitri.stream;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class DishHandlerClassic {
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

    public static List<Dish> filterDishByCalrories (List<Dish> dishes, int colrories) {
        List<Dish> result = new ArrayList<>();

        for (Dish dish : dishes) {
            if (dish.getCalrories() <= colrories) {
                result.add(dish);
            }
        }
        return result;
    }

    public static List<Dish> sortDishByCalrories (List<Dish> dishes) {
        dishes.sort(new Comparator<Dish>() {
            @Override
            public int compare(Dish o1, Dish o2) {
                return o2.getCalrories() - o1.getCalrories();
            }
        });
        return dishes;
    }

    public static List<String> getDishName (List<Dish> dishes) {
        List<String> result = new ArrayList<>();
        for (Dish dish : dishes) {
            result.add(dish.getName());
        }
        return result;
    }

    public static void main(String[] args) {
        List<Dish> result1 = filterDishByCalrories(dishes, 400);
        List<Dish> result2 = sortDishByCalrories(result1);
        List<String> result3 = getDishName(result2);

        System.out.println(result3.subList(0,3));
    }

}
