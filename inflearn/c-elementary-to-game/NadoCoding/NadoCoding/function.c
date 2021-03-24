#include <stdio.h>

// 함수 선언
// int 파라미터를 num이라는 이름으로 받고 반환값으로는 아무 것도 뱉지 않는다
void print_number(int num);


int main(void) {

	// function - 계산기

	int num = 2;
	print_number(num);

	// 2 + 3
	num = num + 3;
	print_number(num);

	// 5 - 1
	num = num - 1;
	print_number(num);

	// 4 * 3
	num = num * 3;
	print_number(num);

	// 12 / 6
	num = num / 6;
	print_number(num);

	return 0;
}

// 함수 정의
void print_number(int num) {
	printf("num은 %d 입니다.\n", num);
}

// 함수의 형태 (구조)
// 반환형 함수이름 (전달값) {    };
