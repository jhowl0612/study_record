package kr.re.kitri.operator;

import kr.re.kitri.stream.Salary;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.DoubleSummaryStatistics;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class CollectQuiz {
    public static void main(String[] args) throws IOException {
        Path file = Path.of("Salaries.csv");

        // 연봉 레벨로 그룹화
        // 100만 미만은 "LOW"
        // 100만 이상 1000만 미만 "NORMAL"
        // 1000만 이상 "HIGH"
        // 각 그룹 평균 도출


        Map<String, DoubleSummaryStatistics> collect = Files.lines(file)
                .skip(1)
                .map(e -> {
                    String[] s = e.split(",");
                    return new Salary(Integer.parseInt(s[0]), s[1], s[2], s[3], Long.parseLong(s[4]));
                })
                .filter(e -> e.getYear() == 2016)
                .collect(Collectors.groupingBy(e -> {
                    if (e.getSalary() < 1000000) {
                        return "LOW";
                    } else if (e.getSalary() < 10000000) {
                        return "NORMAL";
                    } else {
                        return "HIGH";
                    }
                }, Collectors.summarizingDouble(Salary::getSalary)));

        System.out.println(collect.get("HIGH").getMax());
        System.out.println(collect.get("LOW").getAverage());
        System.out.println(collect.get("LOW").getCount());

    }
}
