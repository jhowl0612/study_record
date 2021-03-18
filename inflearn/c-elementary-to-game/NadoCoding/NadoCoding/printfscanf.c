#include <stdio.h>
int main_printfscanf(void)
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
	// int add = 3 + 7;

	//printf("3 + 7 = %d\n", add);
	//printf("%d * %d = %d\n", 30, 79, 30*79);

	//scanf
	// 키보드 입력을 받아서 저장
	/*int input;
	printf("값을 입력하세요 : ");
	scanf_s("%d", &input);
	printf("입력값 : %d\n", input);*/

	/*int one, two, three;
	printf("3개의 정수를 입력하세요 : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("첫 번째 값 : %d\n", one);
	printf("두 번째 값 : %d\n", two);
	printf("세 번째 값 : %d\n", three);*/

	// 문자(한 글자), 문자열(한 글자 이상의 여러 글자)
	/*char c = 'A';
	printf("%c\n", c);*/

	// 문자열을 scanf_s 받을 때 & 접두가 필요없으나 대신 문자열 길이 명시가 필요함
	// str 문자열의 길이 = sizeof(str)
	/*char str[256];
	scanf_s("%s", str, sizeof(str));
	printf("%s\n", str);*/


	// 프로젝트
	// 경찰관이 범죄자의 정보를 입수 (조서 작성)
	// 이름? 나이? 몸무게? 키? 범죄명?

	char name[256];
	printf("이름이 뭐예요? ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("몇 살이에요? ");
	scanf_s("%d", &age);

	float weight;
	printf("몸무게는 몇 kg이에요? ");
	scanf_s("%f", &weight);

	double height;
	printf("키는 몇 cm예요? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("무슨 범죄를 저질렀나요? ");
	scanf_s("%s", what, sizeof(what));


	printf("\n\n--- 범죄자 정보 ---\n\n");
	printf(" 이름      : %s\n",name);
	printf(" 나이      : %d\n", age);
	printf(" 몸무게    : %.2f\n", weight);
	printf(" 키        : %.2lf\n", height);
	printf(" 범죄명    : %s\n", what);


	return 0;
}