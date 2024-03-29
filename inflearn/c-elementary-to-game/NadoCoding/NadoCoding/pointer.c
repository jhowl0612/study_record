#include <stdio.h>

void swap(int a, int b);
void swap_addr(int* a, int * b);
void changeArray(int* ptr);

int main_pointer(void)
{
	// 포인터

	// [철수] : 101호 -> 메모리 공간의 주소
	// [영희] : 102호
	// [민수] : 103호
	// 각 현관문에 암호가 걸려 있음
	//int 철수 = 1; // 암호
	//int 영희 = 2;
	//int 민수 = 3;

	//printf("철수네 주소 : %d, 암호 : %d\n", &철수, 철수);
	//printf("영희네 주소 : %d, 암호 : %d\n", &영희, 영희);
	//printf("민수네 주소 : %d, 암호 : %d\n", &민수, 민수);

	//
	//// 미션맨(포인터)
	//// 미션 1 : 각 집에 방문하여 문에 적힌 암호 확인
	//int * 미션맨; // 포인터 변수 선언
	//미션맨 = &철수; // 철수의 '주소'
	//printf("미션맨이 방문하는 곳의 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	//미션맨 = &영희;
	//printf("미션맨이 방문하는 곳의 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	//미션맨 = &민수;
	//printf("미션맨이 방문하는 곳의 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	//// 미션 2 : 각 암호에 3 곱하기
	//미션맨 = &철수; // 철수의 '주소'
	//*미션맨 = *미션맨 * 3; // 주소의 값에 3을 곱하기
	//printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	//미션맨 = &영희;
	//*미션맨 = *미션맨 * 3; 
	//printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	//미션맨 = &민수;
	//*미션맨 = *미션맨 * 3; 
	//printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);


	//// 스파이(포인터 추가)
	//// 미션맨이 바꾼 암호에서 2 빼기
	//int * 스파이 = 미션맨;
	//printf("\n ... 스파이가 미션 수행 중 ... \n\n");
	//스파이 = &철수; // 철수의 '주소'
	//*스파이 = *스파이 - 2; // 주소의 값에 2 빼기 -> 철수 = 철수 - 2
	//printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	//스파이 = &영희;
	//*스파이 = *스파이 - 2;
	//printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	//스파이 = &민수;
	//*스파이 = *스파이 - 2;
	//printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	//printf("\n ... 철수 영희 민수가 바뀐 암호를 확인 ... \n\n");

	//printf("철수네 주소 : %d, 암호 : %d\n", &철수, 철수);
	//printf("영희네 주소 : %d, 암호 : %d\n", &영희, 영희);
	//printf("민수네 주소 : %d, 암호 : %d\n", &민수, 민수);

	//// cf. 미션맨(포인터) 에게도 주소가 있다. &미션맨 으로 확인 가능
	//printf("미션맨의 주소 : %d\n", &미션맨);
	//printf("스파이의 주소 : %d\n", &스파이);


	// 배열과 포인터
	//int arr[3] = { 5,10,15 };
	//int* ptr = arr;
	//for (int i = 0; i < 3; i++) {
	//	printf("배열 arr[%d] 의 값 : %d\n", i, arr[i]);
	//}
	//for (int i = 0; i < 3; i++) {
	//	printf("포인터 ptr[%d] 의 값 : %d\n", i, ptr[i]);
	//}
	//ptr[0] = 100;
	//ptr[1] = 200;
	//ptr[2] = 300;
	//for (int i = 0; i < 3; i++) {
	//	//printf("배열 arr[%d] 의 값 : %d\n", i, arr[i]);
	//	printf("배열 arr[%d] 의 값 : %d\n", i, *(arr + i));
	//	// arr[i]  == *(arr + i)
	//	// 그냥 arr을 호명할 시 이는 arr[0]의 주소이며, 즉 arr배열의 가장 앞쪽 주소값.
	//	// arr = arr[0] 다음은 arr[1], 그 다음은 arr[2]의 주소.
	//	// 따라서 arr 주소 + 1 이라는 주소에 있는 값 *() 은 arr[1]의 값과 동의어가 됨
	//}
	//for (int i = 0; i < 3; i++) {
	//	//printf("포인터 ptr[%d] 의 값 : %d\n", i, ptr[i]);
	//	printf("포인터 ptr[%d] 의 값 : %d\n", i, *(ptr + i));
	//}
	//// arr[i]  == *(arr + i)
	//// arr == arr 배열의 첫 번째 값의 주소와 동일 == &arr[i]
	//printf("arr 자체의 값 : %d\n", arr);
	//printf("arr[0] 의 주소 : %d\n", &arr[0]);

	//printf("arr 자체의 값이 의미하는 주소에 담긴 실제 값 : %d\n", *arr); // == *{arr + 0}
	//printf("arr[0] 의 값 : %d\n", *&arr[0]);

	//// *& 는 아무것도 붙이지 않은 것과 같음. 값의 -> 주소의 -> 값. 서로 상쇄됨.
	//printf("*&*&*&*&*&*&*&*&*&*&*&*&arr[0] : %d\n", *&*&*&*&*&*&*&*&*&*&*&*&arr[0]);
	//printf("arr[0] : %d\n", arr[0]);


	// 스왑, a와 b의 값을 바꾸기
	//int a = 10;
	//int b = 20;
	//printf("a의 주소 : %d\n", &a);
	//printf("b의 주소 : %d\n", &b);

	//printf("Swap 함수 전 => a : %d, b : %d\n", a, b);
	//swap(a, b);
	//printf("Swap 함수 후 => a : %d, b : %d\n", a, b);

	//// 값에 의한 복사 ( Call by Value ) == 값만 복사한다는 뜻

	//// 주소값을 넘긴다면 ?
	//printf("(주소값 전달) Swap 함수 전 => a : %d, b : %d\n", a, b);
	//swap_addr(&a, &b);
	//printf("(주소값 전달) Swap 함수 후 => a : %d, b : %d\n", a, b);

	// 배열일 때, 'arr2' -> 주소
	int arr2[3] = { 10, 20, 30 };
	//changeArray(arr2);
	changeArray(&arr2[0]);  // 위와 같음
	for (int i = 0; i < 3; i++) {
	
		printf("%d\n", arr2[i]);
		
	}

	// scanf_s에서 & 붙인 이유 또한 이것이 주소 표시라서

	return 0;
}

void swap(int a, int b) {
	printf("swap 함수 내 a의 주소 : %d\n", &a);
	printf("swap 함수 내 b의 주소 : %d\n", &b);

	int temp = a;
	a = b;
	b = temp;
	printf("Swap 함수 중 => a : %d, b : %d\n", a, b);
}

void swap_addr(int * a, int * b) { // 주소가 오므로 포인터 변수를 받기
	printf("swap 함수 내 a의 주소 : %d\n", &a);
	printf("swap 함수 내 b의 주소 : %d\n", &b);

	int temp =*a;
	*a = *b;
	*b = temp;
	printf("(주소값 전달) Swap 함수 중 => a : %d, b : %d\n", *a, *b);
}

void changeArray(int* ptr) { // arr 자체가 포인터 변수 일종이므로 포인터로 받기
	ptr[2] = 50; // arr2[2] = 50;
}