package kr.re.kitri.datetime;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Formatting01 {
    public static void main(String[] args) {
        DateTimeFormatter formater = DateTimeFormatter.ofPattern("yyyy년 MM월 dd일 E");

        String format = formater.format(LocalDate.of(2019, 12, 25));

        System.out.println(format);
    }
}
