#include <stdio.h>

// 12. 구조체

struct BookInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct BookInfo * friendBook; // 연관 업체
	// 타입 struct BookInfo * | 변수명 friendBook
};


// 선언과 동시에 typedef를 지정할 경우 위쪽 변수명 BookInformation는 생략해도 됨.
//typedef struct BookInformation {
typedef struct {
	char* name;
	int year;
	int price;
	char* company;

	struct BookInfo* friendBook; // 연관 업체
	// 타입 struct BookInfo * | 변수명 friendBook
} BOOK_INFO;


int main_struct(void)
{

	// 이름 반려종 선언
	// 출간년도 2019
	// 가격 9000
	// 출판사 책세상

	char* name = "반려종 선언";
	int year = 2019;
	int price = 9000;
	char* company = "책세상";

	// 이름 사이보그 선언
	// 출간년도 2019
	// 가격 10000
	// 출판사 책세상

	char* name2 = "사이보그 선언";
	int year2 = 2019;
	int price2 = 10000;
	char* company2 = "세상책";


	// 구조체 사용
	// 선언을 먼저 하고 값을 넣음
	struct BookInfo bookInfo1;
	//struct BookInfo bookInfo2;
	// [struct BookInfo] - 자료형의 역할
	bookInfo1.name = "반려종 선언";
	bookInfo1.year = 2019;
	bookInfo1.price = 9000;
	bookInfo1.company = "책세상";

	// 구조체 출력
	printf("\n--------	출간 정보	--------\n");
	printf("	책이름	 : %s\n", bookInfo1.name);
	printf("	출간년도 : %d\n", bookInfo1.year);
	printf("	가격	 : %d\n", bookInfo1.price);
	printf("	출판사	 : %s\n", bookInfo1.company);

	// 구조체를 배열처럼 초기화
	// 구조체 안쪽의 변수 순서대로
	struct BookInfo bookInfo2 = { "사이보그 선언", 2019, 10000, "세상책" };
	printf("\n--------	또다른 책 출간 정보	--------\n");
	printf("	책이름	 : %s\n", bookInfo2.name);
	printf("	출간년도 : %d\n", bookInfo2.year);
	printf("	가격	 : %d\n", bookInfo2.price);
	printf("	출판사	 : %s\n", bookInfo2.company);

	// 구조체 배열, 구조체가 들어가는 배열
	struct BookInfo bookArray[2] = { 
		{ "반려종 선언", 2019, 9000, "책세상" },
		{ "사이보그 선언", 2019, 10000, "세상책" } 
	};

	// 구조체 포인터
	struct BookInfo* bookPtr; // 미션맨
	bookPtr = &bookInfo1;
	printf("\n--------	미션맨의 책 출간 정보	--------\n");
	/*printf("	책이름	 : %s\n", (*bookPtr).name);
	printf("	출간년도 : %d\n", (*bookPtr).year);
	printf("	가격	 : %d\n", (*bookPtr).price);
	printf("	출판사	 : %s\n", (*bookPtr).company);*/
	// 위와 동일한 기능
	printf("	책이름	 : %s\n", bookPtr->name);
	printf("	출간년도 : %d\n", bookPtr->year);
	printf("	가격	 : %d\n", bookPtr->price);
	printf("	출판사	 : %s\n", bookPtr->company);

	// 구조체 안의 구조체
	// 연관 업체 소개
	bookInfo1.friendBook = &bookInfo2;
	printf("\n--------	연관업체의 책 출간 정보	--------\n");
	printf("	책이름	 : %s\n", bookInfo1.friendBook->name);
	printf("	출간년도 : %d\n", bookInfo1.friendBook->year);
	printf("	가격	 : %d\n", bookInfo1.friendBook->price);
	printf("	출판사	 : %s\n", bookInfo1.friendBook->company);


	// typedef
	// 자료형에 별명 지정
	int i = 1;
	typedef int 정수;
	typedef float 실수;
	정수 정수변수 = 3; // int i = 3;
	실수 실수변수 = 3.23f; float f = 3.23f;
	printf("\n\n\n\n정수변수 : %d, 실수변수 : %.2f\n\n", 정수변수, 실수변수);

	typedef struct BookInfo 서지정보;
	서지정보 book1;
	book1.name = "책이름";
	book1.year = 2021;
	
	BOOK_INFO book2;
	book2.name = "책이름2";
	book2.year = 2021;

	/*struct BookInformation book3;
	book3.name = "책이름3";
	book3.year = 2021;*/



	return 0;
}