#include <stdio.h>

int main(void) {

	// 버스에 타는 승객을 학생/일반인으로 구분 (기준:20세)
	//int age = 25;
	//// if (조건) {    } else {    } 
	//if (age >= 20) {
	//	printf("일반인 입니다.\n");
	//}
	//else {
	//	printf("학생 입니다.\n");
	//}

	// 초등학생(8~13) / 중학생(14~16) / 고등학생(17~19) 으로 나누기
	// if / else if / else
	int age = 25;
	if (age >= 8 && age <= 13) {
		printf("초등학생입니다.\n");
	}
	else if (age >= 14 && age <= 16) {
		printf("중학생입니다.\n");
	}
	else if (age >= 17 && age <= 19) {
		printf("고등학생입니다.\n");
	}
	else {
		printf("학생이 아닌가봐요.\n");
	}

}