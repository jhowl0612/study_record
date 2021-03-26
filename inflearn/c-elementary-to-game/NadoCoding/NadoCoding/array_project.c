#include <stdio.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	printf("\n\n === === === === === \n\n");
	int answer; // ����� �Է� ��.
	int treatment = rand() % 4; // �´� �� (0-3)

	int cntShowBottle = 0; // �̹��� ������ �� ����
	int prevcntShowBottle = 0; // ������ ������ �� ����
	// �����ִ� �� ������ �ٸ��� �Ͽ� ����� ��� (ó���� 2�� -> �� ���� 3�� ...)

	// 3���� �ÿ�
	for (int i = 1; i <= 3; i++)
	{
		int bottle[4] = { 0,0,0,0 }; // �� 4 ��
		do
		{
			cntShowBottle = rand() % 2 + 2; //  ������ �� ���� ( 0-1, +2 -> 2, 3 )
		} while (cntShowBottle == prevcntShowBottle); // ������ ���� ������ ���Դٸ� �ٽ� ���� ����
		prevcntShowBottle = cntShowBottle;

		int isIncluded = 0; // ������ �� �߿� �´� ���� �־����� ����
		printf(" > %d ��° �õ� : ", i);

		// ������ �� ���� ����
		for (int j = 0; j < cntShowBottle; j++){
			int randomBottle = rand() % 4; // 0-3

			// ���� ���õ��� ���� ���̸� ���� ó��
			if (bottle[randomBottle] == 0){
				bottle[randomBottle] = 1;

				if (randomBottle == treatment) {
					isIncluded = 1; // �´� ���� ���ԵǾ���
				}

			}
			else // �̹� ���õ� ���̶�� �ߺ��̹Ƿ� for�� �� �� �� �ݺ�
			{
				j--;
			}
		}


		// ����ڿ��� ǥ��
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1) {
				printf("%d ��°, ", k + 1);
			}
		}
		printf("���� ����߽��ϴ�.\n\n");

		if (isIncluded == 1) {
			printf("    >>  ���� ! \n");
		}
		else {
			printf("    >>  ����\n");
		}

		printf("\n ... ����Ϸ��� �ƹ� Ű�� �Է��ϼ���. \n");
		
		getchar(); // ����ڰ� � Ű�� �Է��� ������ ���
		// Ű�� �Է¹����� ���� for���� ���� ��

	}

	printf("���� �� ��° ���� �������? ");
	scanf_s("%d", &answer);

	if (answer == treatment+1) {
		printf("\n    >>  �����Դϴ�!\n");
	}
	else {
		printf("\n    >>  Ʋ�Ⱦ�� �̤�. ������ %d ��° ���Դϴ�\n", treatment+1 );
	}

	return 0;
}