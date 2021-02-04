package kr.re.kitri.fi;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class SortDemo {

    public static void main(String[] args) {

        List<String> favoriteColors = Arrays.asList("red", "yellow", "blue", "orange", "pink");

        favoriteColors.sort( (o1, o2) -> o1.length() - o2.length());

//        favoriteColors.sort(new Comparator<String>() {
//            @Override
//            public int compare(String o1, String o2) {
//                return o1.length() - o2.length();
//            }
//        });

        System.out.println(favoriteColors);
    }

//    static class MyComparator implements Comparator<String> {
//        @Override
//        public int compare(String o1, String o2) {
//            return o1.length() - o2.length();
//        }
//    }



//    처음 필사
//    public static void main(String[] args) {
//
//        List<String> favoriteColors = Arrays.asList("red", "yellow", "blue", "orange", "pink");
//
//        // 람다식
//        favoriteColors.sort( (o1, o2) -> o1.length() - o2.length() );
//
//
//
////        // 어나니머스 이너클래스
////        favoriteColors.sort(new Comparator<String>() {
////            @Override
////            public int compare(String o1, String o2) {
////                return o1.length() - o2.length();
////            }
////        });
//
//        System.out.println(favoriteColors);
//    }
//
//
//
////    // 클래스 따로 생성. 펑셔널 인터페이스.
////    static class MyComparator implements Comparator<String> {
////        @Override
////        public int compare(String o1, String o2) {
////            return o1.length() - o2.length();
////        }
////    }
}
