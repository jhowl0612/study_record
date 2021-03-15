#include <stdio.h>
int main(void)
{
	////정수

	//int age = 12;
	//printf("%d\n", age); // 12
	//// %d = 이후 콤마(,) 뒤에 적힌 정수형 값을 이 자리에 출력할 것이라는 뜻
	//age = 13;
	//printf("%d\n", age); // 12 \ 13
	//int one = 1;
	//int two = 2;
	//printf("%d\n%d\n", one, two); // 1 \ 2
	//// %d와 정수형 값이 여러 개라면 각각 차례대로 들어감.

	///* 주석은 CSS와 같은 형식 */


	//// 실수

	//float f = 46.5f; // 플롯 뒤에는 f 붙일 것
	//// %f = 플롯 값 자리
	//printf("%f\n", f); // 46.500000
	//printf("%.2f\n", f); // 46.50, 소수점 둘째 자리까지

	//// %lf = 더블 값 자리
	//double d = 4.428; // 더블 뒤에는 f 안 붙여도 됨
	//printf("%.2lf\n", d); // 4.43, 반올림 소수점 둘째 자리까지


	//// 상수
	//const int YEAR = 2000; // const -  재정의 불가능 상수는 보통 대문자 표기
	//printf("태어난 년도 : %d\n", YEAR);
	//// YEAR = 2001; // 오류발생


	//printf
	//연산
	int add = 3 + 7;

	//printf("3 + 7 = %d\n", add);
	printf("%d * %d = %d\n", 30, 79, 30*79);

	return 0;
}