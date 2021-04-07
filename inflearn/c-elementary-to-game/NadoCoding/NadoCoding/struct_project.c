#include <stdio.h>
#include <time.h>

// 13. ����ü ������Ʈ

// 5 ������ ����̰� �ִ�
// �ƹ� Ű�� ������ �������� ����̸� �̵�
// 5 ���� ��� �����ؼ� �⸣��(����) ����
// �ߺ� ����(!)

// �����
// �̸�, ����, ����, Ű��� ���̵�(����)

typedef struct {
	char* name; // �̸�
	int age; // ����
	char* character; // ����
	int level; // Ű��� ���̵�(���� 1-5, 5�� ������ �����)

} CAT;

// ������� ������ ����� ����
int collection[5] = {0, 0, 0, 0, 0};

// ��ü ����� ����Ʈ
CAT cats[5];

void initCats(); // ����� ���� �ʱ�ȭ
void printCat(int selected);
int checkCollection();


int main_struct_project(void)
{
	srand(time(NULL));

	initCats();

	while (1) {

		printf("��� ����̸� ������ �ɱ��? \n ====> �ƹ� Ű�� ������ Ȯ���غ�����.");
		getchar(); // �ƹ� Ű�� �Է��� ������ ��ٸ���

		int selected = rand() % 5; // 0-4
		printCat(selected); // ���� ����� ���� ���
		collection[selected] = 1; // ����� ���� �� ó�� - �ش� ĭ true

		int collectAll = checkCollection();

		if (collectAll) // collectAll == 1 �� �������� ���
		{
			printf("\n\n �����մϴ� ! ��� ����̸� �����Ծ��. ������ Ű���ּ���. \n\n");
			printf(" ====> �ƹ� Ű�� ������ ����˴ϴ�.");
			getchar();
			break;
		}

	}

	return 0;
}

void initCats()
{
	cats[0].name = "����";
	cats[0].age = 7;
	cats[0].character = "�¼���";
	cats[0].level = 1;

	cats[1].name = "����";
	cats[1].age = 3;
	cats[1].character = "��ĥ��";
	cats[1].level = 2;

	cats[2].name = "����";
	cats[2].age = 4;
	cats[2].character = "���� ����";
	cats[2].level = 3;

	cats[3].name = "���";
	cats[3].age = 5;
	cats[3].character = "�ֱ��� ����";
	cats[3].level = 4;

	cats[4].name = "��";
	cats[4].age = 1;
	cats[4].character = "��Ž�� ����";
	cats[4].level = 5;
}

void printCat(int selected)
{
	printf("\n\n ==== ����� �� ������� ���簡 �Ǿ���� ! ==== \n\n");
	printf("     �̸�     : %s\n", cats[selected].name);
	printf("     ����     : %d\n", cats[selected].age);
	printf("  Ư¡(����)  : %s\n", cats[selected].character);
	//printf("    ���̵�    : %d", cats[selected].level);
	printf("    ���̵�    : ");
	
	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("%s","��");
	}
	printf("\n\n");
}

int checkCollection()
{
	// 1. ���� ������ ����� ��� ���
	// 2. �� �����Դ��� ���� ���
	int collectAll = 1;

	printf("\n\n ================ ������ ����� ��� ================ \n\n");

	for (int i = 0; i < 5; i++) // collection �迭�� ���̸�ŭ
	{
		if (collection[i] == 0) // �ش� ����� ����
		{
			printf("%10s", "(�� ����)");
			collectAll = 0; // �������� ���� ����̰� ���� ���
		}
		else // �ش� ����� ����
		{
			printf("%10s", cats[i].name);
		}
	}
	printf("\n\n ==================================================== \n\n");

	return collectAll;
}