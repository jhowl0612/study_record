package kr.re.kitri.datetime;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.Period;
import java.time.temporal.ChronoUnit;
import java.time.temporal.TemporalUnit;

public class DateTime02 {
    public static void main(String[] args) {
        LocalDate theDay = LocalDate.of(2019, 12, 25)
                .minusDays(5).plusWeeks(2);

        LocalDate theDay2 = LocalDate.of(1919, 3, 1)
                .plus(3, ChronoUnit.WEEKS)
                .minus(5, ChronoUnit.DAYS);

        System.out.println(theDay);
        System.out.println(theDay2);

        DayOfWeek dayOfWeek = theDay2.getDayOfWeek();

        boolean isAfter = theDay2.isAfter(theDay);
        System.out.println(isAfter);

        Period until = theDay.until(theDay2);
        System.out.println(until);
    }
}
