package kr.re.kitri.operator;

import kr.re.kitri.stream.Salary;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.OptionalDouble;

public class SalaryQuiz {
    public static void main(String[] args) throws IOException {
        // Quiz 1 : 내셔널 리그 상위 30명 연봉의 평균
        // Quiz 2 : 2010이후 "NYA"의 상위 5명 연봉의 합

        // 1. 필터링
        // 2. 소팅
        // 3. 매핑 Salary -> long(Salary)
        // 4. Stream<Long> -> LongStream (mapToLong)
        // 5. limit()
        // 6. 집계. average, sum

        Path file = Path.of("Salaries.csv");

        OptionalDouble average = Files.lines(file)
                .skip(1)
                .map(e -> {
                    String[] s = e.split(",");
                    return new Salary(Integer.parseInt(s[0]), s[1], s[2], s[3], Long.parseLong(s[4]));
                })
                .filter(e -> e.getLeague().equals("NL"))
                .sorted((a, b) -> (int) (b.getSalary() - a.getSalary())) // 특화 타입은 소팅이 오름차순밖에 안 되므로 먼저함
                .mapToLong(e -> e.getSalary())
                .limit(30)
//                .peek(System.out::println)
                .average();

        // sum은 빈 스트림에서 0을 도출할 수 있지만. average는 0을 도출하지 않음. null을 뱉음.
        // 스트림이 비었을 경우를 대비해, 값이 null일 수도 있다는 걸 알리는 데이터타입 옵셔널 더블로 리턴함.
        // 이를 널세이프 기능이라고 함! 값을 옵셔널이라는 껍데기가 감싸고 있는 타입.
        // [ 더블 값 ] 형태로 들어있으며, getAsDouble()로 더블 값을 꺼낼 수 있음.
        
        // 디스팅트, 소팅은 오래 걸리니 최대한 안 하는 방향으로, 한다면 되도록 데이터 줄어든 후에 (병렬처리가 안됨)
        // 이를 내부 상태가 있는 중간연산이라고 함

        System.out.println("Quiz 1 : " + average.getAsDouble());

        long sum = Files.lines(file)
                .skip(1)
                .map(e -> {
                    String[] s = e.split(",");
                    return new Salary(Integer.parseInt(s[0]), s[1], s[2], s[3], Long.parseLong(s[4]));
                })
                .filter(e -> e.getYear() >= 2010) // 같은 필터는 &&으로 연결할 수 있지만 속도상 차이가 없을 확률이 높으므로
                .filter(e -> e.getTeam().equals("NYA")) // 가독성을 위해 두 줄로 적음
                .sorted((a, b) -> (int) (b.getSalary() - a.getSalary()))
                .mapToLong(e -> e.getSalary())
                .limit(5)
//                .peek(System.out::println)
                .sum();

        System.out.println("Quiz 2 : " + sum);
    }
}
