#include <stdio.h>

// 12. ����ü

struct BookInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct BookInfo * friendBook; // ���� ��ü
	// Ÿ�� struct BookInfo * | ������ friendBook
};


// ����� ���ÿ� typedef�� ������ ��� ���� ������ BookInformation�� �����ص� ��.
//typedef struct BookInformation {
typedef struct {
	char* name;
	int year;
	int price;
	char* company;

	struct BookInfo* friendBook; // ���� ��ü
	// Ÿ�� struct BookInfo * | ������ friendBook
} BOOK_INFO;


int main_struct(void)
{

	// �̸� �ݷ��� ����
	// �Ⱓ�⵵ 2019
	// ���� 9000
	// ���ǻ� å����

	char* name = "�ݷ��� ����";
	int year = 2019;
	int price = 9000;
	char* company = "å����";

	// �̸� ���̺��� ����
	// �Ⱓ�⵵ 2019
	// ���� 10000
	// ���ǻ� å����

	char* name2 = "���̺��� ����";
	int year2 = 2019;
	int price2 = 10000;
	char* company2 = "����å";


	// ����ü ���
	// ������ ���� �ϰ� ���� ����
	struct BookInfo bookInfo1;
	//struct BookInfo bookInfo2;
	// [struct BookInfo] - �ڷ����� ����
	bookInfo1.name = "�ݷ��� ����";
	bookInfo1.year = 2019;
	bookInfo1.price = 9000;
	bookInfo1.company = "å����";

	// ����ü ���
	printf("\n--------	�Ⱓ ����	--------\n");
	printf("	å�̸�	 : %s\n", bookInfo1.name);
	printf("	�Ⱓ�⵵ : %d\n", bookInfo1.year);
	printf("	����	 : %d\n", bookInfo1.price);
	printf("	���ǻ�	 : %s\n", bookInfo1.company);

	// ����ü�� �迭ó�� �ʱ�ȭ
	// ����ü ������ ���� �������
	struct BookInfo bookInfo2 = { "���̺��� ����", 2019, 10000, "����å" };
	printf("\n--------	�Ǵٸ� å �Ⱓ ����	--------\n");
	printf("	å�̸�	 : %s\n", bookInfo2.name);
	printf("	�Ⱓ�⵵ : %d\n", bookInfo2.year);
	printf("	����	 : %d\n", bookInfo2.price);
	printf("	���ǻ�	 : %s\n", bookInfo2.company);

	// ����ü �迭, ����ü�� ���� �迭
	struct BookInfo bookArray[2] = { 
		{ "�ݷ��� ����", 2019, 9000, "å����" },
		{ "���̺��� ����", 2019, 10000, "����å" } 
	};

	// ����ü ������
	struct BookInfo* bookPtr; // �̼Ǹ�
	bookPtr = &bookInfo1;
	printf("\n--------	�̼Ǹ��� å �Ⱓ ����	--------\n");
	/*printf("	å�̸�	 : %s\n", (*bookPtr).name);
	printf("	�Ⱓ�⵵ : %d\n", (*bookPtr).year);
	printf("	����	 : %d\n", (*bookPtr).price);
	printf("	���ǻ�	 : %s\n", (*bookPtr).company);*/
	// ���� ������ ���
	printf("	å�̸�	 : %s\n", bookPtr->name);
	printf("	�Ⱓ�⵵ : %d\n", bookPtr->year);
	printf("	����	 : %d\n", bookPtr->price);
	printf("	���ǻ�	 : %s\n", bookPtr->company);

	// ����ü ���� ����ü
	// ���� ��ü �Ұ�
	bookInfo1.friendBook = &bookInfo2;
	printf("\n--------	������ü�� å �Ⱓ ����	--------\n");
	printf("	å�̸�	 : %s\n", bookInfo1.friendBook->name);
	printf("	�Ⱓ�⵵ : %d\n", bookInfo1.friendBook->year);
	printf("	����	 : %d\n", bookInfo1.friendBook->price);
	printf("	���ǻ�	 : %s\n", bookInfo1.friendBook->company);


	// typedef
	// �ڷ����� ���� ����
	int i = 1;
	typedef int ����;
	typedef float �Ǽ�;
	���� �������� = 3; // int i = 3;
	�Ǽ� �Ǽ����� = 3.23f; float f = 3.23f;
	printf("\n\n\n\n�������� : %d, �Ǽ����� : %.2f\n\n", ��������, �Ǽ�����);

	typedef struct BookInfo ��������;
	�������� book1;
	book1.name = "å�̸�";
	book1.year = 2021;
	
	BOOK_INFO book2;
	book2.name = "å�̸�2";
	book2.year = 2021;

	/*struct BookInformation book3;
	book3.name = "å�̸�3";
	book3.year = 2021;*/



	return 0;
}