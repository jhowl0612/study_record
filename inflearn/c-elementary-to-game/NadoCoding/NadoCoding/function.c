#include <stdio.h>

// 함수 선언
// int 파라미터를 num이라는 이름으로 받고 반환값으로는 아무 것도 뱉지 않는다
void print_number(int num);

void function_without_return();
int function_with_return();
void function_without_params();
void function_with_params(int num1, int num2, int num3);
int apple(int total, int ate); // total 개에서 ate 개를 먹고 남은 수를 반환

int main(void) {

	// function - 계산기

	//int num = 2;
	//print_number(num);

	//// 2 + 3
	//num = num + 3;
	//print_number(num);

	//// 5 - 1
	//num = num - 1;
	//print_number(num);

	//// 4 * 3
	//num = num * 3;
	//print_number(num);

	//// 12 / 6
	//num = num / 6;
	//print_number(num);

	// 함수 종류
	// 반환값이 없는 함수
	 //function_without_return();

	 // 반환값이 있는 함수
	 //int ret = function_with_return();
	 //print_number(ret);

	 // 파라미터(전달값)가 없는 함수
	 //function_without_params();

	 // 파라미터(전달값)가 있는 함수
	 //function_with_params(37, 25, 12);

	// 파라미터(전달값)을 받고 반환값이 있는 함수
	//int ret = apple(5, 2); // 사과 5개 중 2개를 먹었다면 남은 수는
	//print_number(ret);
	// printf("사과 5 개 중에서 2 개를 먹으면 %d 개가 남아요.\n", ret);
	// printf 파라미터에 함수를 넣을 수 있음
	printf("사과 %d 개 중에서 %d 개를 먹으면 %d 개가 남아요.\n", 10, 4, apple(10, 4));

	return 0;
}

// 함수 정의
void print_number(int num) {
	printf("num은 %d 입니다.\n", num);
}

// 함수의 형태 (구조)
// 반환형 함수이름 (전달값) {    };

void function_without_return() {
	printf("반환값이 없는 함수입니다.\n");
}
int function_with_return() {
	printf("반환값이 있는 함수입니다.\n");
	return 10;
}
void function_without_params() {
	printf("전달값이 없는 함수입니다.\n");
}
void function_with_params(int num1, int num2, int num3) {
	printf("전달값이 있는 함수입니다. 전달받은 값은 %d, %d, %d 입니다.\n", num1, num2, num3);
}
int apple(int total, int ate) {
	printf("전달값과 반환값이 있는 함수입니다.\n");
	return total - ate;
}
