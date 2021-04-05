#include <stdio.h>
#include <time.h>

// 10������ ���� �ٸ� ����, �� 2�徿
// 2���� �Է°��� �޾Ƽ� -> ���� ������ ã���� ī�带 ������
// ��� ���� ã���� ����
// �� ���� Ƚ�� ���

int arrayAnimal[4][5]; // ī�� ��� 20��
int checkAnamal[4][5]; // ī�� ���������� 1 or 0
char* strAnimal[10];
// ���� ������ �ʱ�ȭ �� �ص� 0���� ����� �ֳ� ��

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals(); // ���� ��ġ ���
void printQuestion(); // ���� ��� ( ī�� ���� )
int foundAllAnimals();

int test[10];

int main(void)
{
	/*for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("(%d, %d) : %d\n", i,j, checkAnamal[i][j]);
		}
	}*/

	srand(time(NULL));

	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	int failCount = 0; // ���� Ƚ��

	while (1)
	{
		int select1 = 0; // ����ڰ� ������ �� 1
		int select2 = 0; // ����ڰ� ������ �� 2

		printAnimals(); // ���� ��ġ ���
		printQuestion(); // ���� ��� ( ī�� ���� )
		printf("������ ī�带 2 �� ������ : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) // ���� ī�� ���� �� ��ȿ 
			continue;

		// ī�带 ������ ������ Ȯ��
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);
		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		if ((checkAnamal[firstSelect_x][firstSelect_y] == 0 
			&& checkAnamal[secondSelect_x][secondSelect_y] == 0)
			
			&&	
			
			arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y]
			)
		{
			printf("\n\n����! %s �� �߰��߽��ϴ�.", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]] );
			checkAnamal[firstSelect_x][firstSelect_y] = 1;
			checkAnamal[secondSelect_x][secondSelect_y] = 1;
		}
		// �ٸ� ����
		else {
			printf("\n\n��! (Ʋ�Ȱų�, �̹� ������ ī���Դϴ�.)\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");
			
			failCount++;
		}

		// ��� ������ ã�Ҵ���
		if (foundAllAnimals() == 1)
		{
			printf("\n\n �����մϴ� ! ��� ������ �� ã�ҳ׿�. \n");
			printf("�� %d �� �Ǽ��Ͽ����ϴ�. \n", failCount);
			break;
		}
	}

	return 0;
}

void initAnimalArray() 
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}
void initAnimalName() 
{
	strAnimal[0] = "������";
	strAnimal[1] = "��";
	strAnimal[2] = "������";
	strAnimal[3] = "�����";
	strAnimal[4] = "����";
	strAnimal[5] = "�ڳ���";
	strAnimal[6] = "��";
	strAnimal[7] = "�䳢";
	strAnimal[8] = "���Ƹ�";
	strAnimal[9] = "ȣ����";
}
void shuffleAnimal()
{
	// ������
	// ������
	// ������
	// ������

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

// �� ��ǥ ã��
int getEmptyPosition()
{
	// ������  0  1  2  3  4
	// ������  5  6  7  8  9 
	// ������ 10 11 12 13 14 
	// ������ 15 16 17 18 19

	while (1) {
		int randPos = rand() % 20; // 0-19
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) {
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x) {
	// 19 -> (3,4)
	return x / 5;
}
int conv_pos_y(int y) {
	
	return y % 5;
}

void printAnimals() { // ���� ��ġ ���
	// ������  0  1  2  3  4
	// ������  5  6  7  8  9 
	// ������ 10 11 12 13 14 
	// ������ 15 16 17 18 19
	printf("\n ==================���� �̸�����================== \n\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n ================================================== \n\n");
}
void printQuestion() { // ���� ��� ( ī�� ���� )
	printf("\n\n [����] \n\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// �̹� ���� ī���(1) '���� �̸�' ���
			if (checkAnamal[i][j] != 0) {
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// �ƴϸ� �޸� = ��ġ ����
			else {
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
	printf("\n ================================================== \n\n");

}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnamal[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}