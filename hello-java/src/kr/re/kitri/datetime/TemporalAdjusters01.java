package kr.re.kitri.datetime;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.temporal.TemporalAdjusters;

public class TemporalAdjusters01 {
    public static void main(String[] args) {
        LocalDate theDay = LocalDate.of(1945, 8, 15);

        System.out.println(theDay
                .with(TemporalAdjusters.nextOrSame(DayOfWeek.WEDNESDAY))
                .with(TemporalAdjusters.next(DayOfWeek.WEDNESDAY)) );
            // 데이의 다음 수요일(데이가 수요일이라면 변하지않음) -> 데이의 다음 수요일

        System.out.println(theDay
                .with(TemporalAdjusters.nextOrSame(DayOfWeek.WEDNESDAY))
                .with(TemporalAdjusters.next(DayOfWeek.WEDNESDAY)) );
    }
}
