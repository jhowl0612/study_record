package kr.re.kitri.datetime;

import java.time.LocalTime;

public class DateTime03 {
    public static void main(String[] args) {
        LocalTime bedtime = LocalTime.of(22, 30);

        LocalTime waketime = bedtime.plusHours(8);
        System.out.println(waketime);

    }
}
