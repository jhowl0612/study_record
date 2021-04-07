#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 15. 파일 입출력
// 파일에 데이터 저장
// 파일에 저장된 데이터 불러오기


#define MAX 10000
int main_file(void)
{
	// fputs, fgets
    // fprintf, fscanf


	// fputs, fgets - 주로 문자열 입출력

	char line[MAX]; // 숫자 자리에 변수는 못 넣지만 상수(define)은 가능

	// 파일 쓰기
	//FILE* file = fopen("15_test1.txt", "wb"); // 파일명, 여는 형식
	// 여는 형식 r 읽기전용 | w 쓰기 전용 | a 뒤에 추가
	// w로 열면 기존 데이터 싹 지우고 처음부터 작성함
	// t 텍스트 | b 바이너리 데이터

	/*if (file == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}
	printf("파일 열기 성공\n");
	fputs("fputs 를 이용해서 글을 적습니다.\n", file);
	fputs("잘 적히는지 확인합니다.\n", file);*/

	// 연 파일을 닫지 않은 상태에서 프로그램에 문제가 생기면 데이터 손실 발생
	// 항상 파일 잘 닫기
	//fclose(file);


	// 파일 읽기
	//FILE* file = fopen("15_test1.txt", "rb"); // 읽기 전용, 바이너리
	//if (file == NULL) {
	//	printf("파일 열기 실패\n");
	//	return 1;
	//}
	//printf("파일 열기 성공\n");
	//
	//while (fgets(line,MAX,file) != NULL) // 문자열 저장할 곳, 사이즈, 파일명
	//{
	//	printf("%s", line);
	//}

	//fclose(file);

	// fputs, fgets - 주로 문자열 입출력
	

	// fprintf, fscanf - %d, %s 등을 사용하여 특정 자리에 특정 데이터를 집어넣을 때
	int num[6] = { 0, 0, 0, 0, 0, 0 }; // 추첨번호
	int bonus = 0; // 보너스번호
	char str1[MAX]; // 파일 읽어왔을 때 저장할 변수
	char str2[MAX];

	// 쓰기
	//FILE * file = fopen("15_test2.txt", "wb");
	//if (file == NULL) {
	//	printf("파일 열기 실패\n");
	//	return 1;
	//}
	//printf("파일 열기 성공\n");

	//// 로또 추첨 번호 저장

	//fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호 ", 1,2,3,4,5,6);
	//fprintf(file, "%s %d\n", "보너스번호 ", 7);

	//fclose(file);

	// 읽기
	FILE* file = fopen("15_test2.txt", "rb"); // 읽기 전용, 바이너리
	if (file == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}
	printf("파일 열기 성공\n");
	
	fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);

	fscanf(file, "%s %d", str2, &bonus);
	printf("%s %d\n", str2, bonus);

	fclose(file);

	return 0;
}