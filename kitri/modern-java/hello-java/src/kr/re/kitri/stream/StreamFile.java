package kr.re.kitri.stream;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

// Salary 모델 사용
public class StreamFile {
    public static void main(String[] args) throws IOException {
        // 루트 경로 : 프로젝트명 폴더. imi 파일과 같은 단계
        Path file = Path.of("Salaries.csv");

        // 아메리칸 리그의 연봉 탑5 출력
        // 1. 아메리칸 리그 필터 - 2. 연봉 내림차순 정렬 - 3. limit(5) - 4. 출력
        // 라인 하나당 하나의 문자열로, Stream<String>
        Files.lines(file)
                .skip(1) // 1 엘리먼트 스킵 -> 헤더 스킵
                // .peek(System.out::println)
                .map(e -> {
                    String[] s = e.split(",");
                    return new Salary(Integer.parseInt(s[0]), s[1], s[2], s[3], Long.parseLong(s[4]));
                })  // 샐러리 타입으로 변경! 데이터 누락, 빈 데이터 대비는 안 했음
                .filter(e -> e.getLeague().equals("AL"))
                .sorted((a,b) -> (int) (b.getSalary() - a.getSalary()))
                // 소티드는 인트가 리턴되므로, 인트 캐스팅을 해 줘야 함
                .limit(5)
                .forEach(System.out::println);
                // .count();

//        System.out.println(count);
    }
}
