#include <stdio.h>

int main_array(void)
{
	// 배열
	//int subway_1 = 30; // 1지하철 1호차에 30명
	//int subway_2 = 40; 
	//int subway_3 = 50; 

	//printf("지하철 1호차에 %d 명이 타고 있습니다.\n", subway_1);
	//printf("지하철 2호차에 %d 명이 타고 있습니다.\n", subway_2);
	//printf("지하철 3호차에 %d 명이 타고 있습니다.\n", subway_3);

	// 여러 개의 변수를 한꺼번에 생성
	//int subway_array[3]; // [0] [1] [2]
	//subway_array[0] = 30;
	//subway_array[1] = 40;
	//subway_array[2] = 50;

	/*for (int i = 0; i < 3; i++) {
		printf("지하철 %d호차에 %d 명이 타고 있습니다.\n", i+1, subway_array[i]);
	}*/

	//// 값 설정 방법
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//// 변수명 선언만 해두고 값 선언을 안 하면=초기화를 안 하면( int arr[10]; ) 임의의 더미 값이 들어감
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d\n", arr[i]);
	//}

	// 에러 발생. 배열 크기에는 직접 상수를 입력해야 함
	/*int size = 10;
	int arr[size];*/

	//int arr[10] = { 1,2, }; // 일부만이라도 초기화를 해 두면 나머지 값도 0으로 초기화됨
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d\n", arr[i]);
	//}


	// int arr[] = { 1,2 }; // arr[2]. 크기를 안 적으면 알아서 세어서 넣어 줌

	//float arr_f[5] = {1.0f, 2.0f, 3.0f}; // 선언 안 한 나머지도 0.00 으로 초기화
	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%.2f\n", arr_f[i]);
	//}


	//// 문자 vs 문자열
	//char c = 'A';
	//printf("%c\n", c);

	// 문자열 끝에는 '끝'을 의미하는 NULL 문자 '\0'이 포함되어야 함
	//char str[6] = "coding"; // [c][o][d][i][n][g][\0]
	//char str[7] = "coding"; // [c][o][d][i][n][g][\0] 한 칸 넉넉하게 둬야 \0이 들어감
	//printf("%s\n", str);

	//char str[] = "coding"; // 자동으로 \0을 추가
	////printf("%s\n", str);
	////printf("%d\n", sizeof(str)); // 7

	//for (int i = 0; i < sizeof(str); i++)
	//{
	//	printf("%c\n", str[i]);
	//}

	// 영어 한글자 1 byte, 한글 한글자 2 byte
	// char 크기 : 1 byte
	//char kor[] = "나도코딩"; // 8 + 1 = 9
	//printf("%s\n", kor);
	//printf("%d\n", sizeof(kor)); // 9

	//char c_array[7] = { 'c','o','d','i','n','g','\0' };  // 문자열 선언과 똑같은 결과
	//char c_array[6] = { 'c','o','d','i','n','g' };  // 문자열처럼 끝에 더미데이터 발생
	//printf("%s\n", c_array);

	char c_array[10] = { 'c','o','d','i','n','g' }; // 나머지 7890이 전부 각각 \0이 들어감
	//printf("%s\n", c_array);
	/*for (int i = 0; i < sizeof(c_array); i++)
	{
		printf("%c\n", c_array[i]);
	}*/
	//for (int i = 0; i < sizeof(c_array); i++)
	//{
	//	printf("%d\n", c_array[i]); // 문자를 %d로 출력하면 ASCII 코드 값으로 출력됨
	//}

	// 문자열 입력받기 - printfscanf.c
	//char name[256];
	//printf("이름을 입력하세요 : ");
	//scanf_s("%s", name, sizeof(name));
	//printf("%s\n", name);

	// ASCII 코드 - ANSI(미국표준협회)에서 제시한 표준코드체계
	// 7bit -> 128개 코드 ( 0 - 127 )
	// a 의 아스키코드 값 : 97
	// A : 65
	// 0 : 48

	//printf("%c\n", 'a');
	//printf("%d\n", 'a'); // 출력포맷만 '정수형'으로 설정하면 아스키 코드로 나옴
	//printf("%c\n", 'b');
	//printf("%d\n", 'b');
	//printf("%c\n", 'A');
	//printf("%d\n", 'A');
	//printf("%c\n", '\0');
	//printf("%d\n", '\0');
	//printf("%c\n", '0');
	//printf("%d\n", '0');
	//printf("%c\n", '1');
	//printf("%d\n", '1');

	//printf("%c\n", 97); // 숫자를 '문자형'으로 출력하면 해당하는 문자가 나옴
	for (int i = 0; i < 128; i++)
	{
		printf("아스키코드 번호 %d : %c\n", i, i);
	}

	return 0;
}