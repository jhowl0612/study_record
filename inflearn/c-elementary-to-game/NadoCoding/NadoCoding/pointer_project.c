#include <stdio.h>
#include <time.h>

// ����� 6������ ���� ���׿� ��� ����
// �� ������ ���� ���� ���Ƿ� ���׿� ���� �ֱ�
// ���� �ð� �̻� ����

// ���� ����
int level;
int arrayFish[6];
int* cursor; // pointer.c �� �̼Ǹ� ���� ����

// �Լ� ����
void initData();
void printFishes();
void decreaseWater(long elapsedTime);


int main(void)
{
	// �ð� ������ ���� long��
	long startTime = 0; // ���� �ð�
	long totalElapsedTime = 0; // �� ��� �ð�
	long prevElapsedTime = 0; // ���� ��� �ð� (������ ���� �� �ð� ����)

	int num; // �� �� ���׿� ���� �� ������ ����� �Է�
	initData();

	cursor = arrayFish; // cursor[0] ó�� �迭�� �������� ���� ����

	startTime = clock(); // ����ð��� millisecond(1000���� 1��) ������ ��ȯ
	while (1)  // ���� �ݺ�
	{
		printFishes(); // ���� ���� ���
		printf("�� �� ���׿� ���� �ٱ��?");
		scanf_s("%d", &num);

		if (num < 1 || num > 6) {
			printf("\n�Է°��� �߸��Ǿ����ϴ�.\n\n");
			continue;
		}

		// �� ��� �ð�
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // �и��ʸ� �ʷ� �ٲٱ� ���� 1000���� ����
		printf("�� ��� �ð� : %1d ��\n", totalElapsedTime);

		// ���� ���������� �� �� �ð� '���ķ� �帥 �ð�' ����
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð� : %1d ��\n", prevElapsedTime);

		// ������ �� ����
		decreaseWater(prevElapsedTime);

		// ����ڰ� �Է��� ���׿� ���� ��
		// 1. ������ ���� 0�̸� : ���� ���� �ʴ´�.
		if (cursor[num - 1] <= 0) {
			printf("%d �� ������ �̹� �׾����ϴ�... ���� ���� �ʽ��ϴ�.\n", num);
		}
		// 2. ������ ���� 0�� �ƴ� ��� ���� �ش�. ��, 100�� ���� �ʴ��� üũ
		else if (cursor[num - 1] < 100) {
			printf("%d �� ���׿� ���� �ݴϴ�.\n", num);
			cursor[num - 1] += 1;
		}

		// �������� �� ���� Ȯ�� (�������� 20��(���氡��)���� �� ����)
		if (totalElapsedTime / 10 > (level - 1)) {
			level++;
			printf(" *** �� ������ ! ���� %d �������� %d ������ ���׷��̵� ***\n\n", level - 1, level);

			if (level >= 5) {
				printf("\n\n�����մϴ�. �ְ� ������ �޼��Ͽ����ϴ�. ������ �����մϴ�.\n\n");
				exit(0);
			}
		}

		// ��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0) {
			printf("\n\n��� ����Ⱑ �׾����ϴ� ��\n\n");
			exit(0);
		}
		else {
			// �ϳ� �̻� ��� ����
			printf("\n\n����Ⱑ ���� ��� �־��!\n\n");
		}
		prevElapsedTime = totalElapsedTime;
		//prevElapsedTime�� '���������� �� �� ����ð�' ����
	}

	return 0;
}
void initData() {
	level = 1;
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100; // ������ �� ���� (0-100);

	}
};
void printFishes() {
	printf(" %d��  %d��  %d��  %d��  %d��  %d��\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf(" %3d ", arrayFish[i]);
	}
	printf("\n\n");
}
void decreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 1 * (int)elapsedTime); //  3(���氡��)�� ���̵������� ���� ��
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}
int checkFishAlive() {
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1; // True
	}
	return 0;
}