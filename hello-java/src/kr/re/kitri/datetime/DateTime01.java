package kr.re.kitri.datetime;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

public class DateTime01 {
    public static void main(String[] args) {
        LocalTime now = LocalTime.now();
        System.out.println(now);
        LocalDate now1 = LocalDate.now();
        System.out.println(now1);
        LocalDateTime now2 = LocalDateTime.now();
        System.out.println(now2);

        LocalDate of = LocalDate.of(2019, 12, 25);
        System.out.println(of);
        LocalTime of1 = LocalTime.of(15, 30, 25);
        System.out.println(of1);


    }
}
