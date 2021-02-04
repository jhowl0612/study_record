package kr.re.kitri.collect;

import kr.re.kitri.stream.Salary;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.stream.Collectors;

public class CollectMaxMin {
    public static void main(String[] args) throws IOException {
        Path file = Path.of("Salaries.csv");
        Salary salary = Files.lines(file)
                .skip(1)
                .map(e -> {
                    String[] s = e.split(",");
                    return new Salary(Integer.parseInt(s[0]), s[1], s[2], s[3], Long.parseLong(s[4]));
                })
                .collect(Collectors.maxBy((a, b) -> (int) (a.getSalary() - b.getSalary())))
                .get();
                // null 방지를 위해 get()보다 ifPresent() 추천 됨

        System.out.println(salary);
    }

}
