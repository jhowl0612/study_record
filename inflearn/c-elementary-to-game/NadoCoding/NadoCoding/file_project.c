#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 16. ����� ������Ʈ
// ��й�ȣ�� �Է¹޾Ƽ� ��ġ�ϸ� �ϱ⸦ �����ְ� ��� �ۼ�
// Ʋ���� ��� ����ϰ� ����

#define MAX 10000

int main(void)
{
	// fgets, fputs

	char line[MAX];    // ���Ͽ��� �о�� ������ ������ ����
	char contents[MAX];    // �ϱ��忡 �Է��� ����
	char password[20];
	char c; // ��й�ȣ �Է��� �� ****�� ǥ���ϱ� ���� (����ŷ)

	printf("\n��й�ȣ�� �Է��ϼ��� : \n");

	// getchar - � Ű �Է� �� ���͸� �Է¹޾ƾ� �۵� ����
	// getch - Ű �Է� �� �ٷ� ����

	int i = 0;
	while (1) // �� ���� �Է� �ø��� �ݺ�
	{
		c = getch();
		if (c == 13) // �ƽ�Ű�ڵ� '����' �ΰ�? -> ��й�ȣ �Է� ����
		{
			password[i] = '\0';
			break;
		}
		else
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}
	//printf("%s",password);
	printf("\n\n ==== ��й�ȣ Ȯ�� �� . . .  ====  \n\n");
	if (strcmp(password, "aaaa") == 0) // ��Ʈ�� ����� ����ؼ� ���ϱ�. �ٸ��� -1 �̳� 1 ��ȯ (ũ���)
	{
		printf(" ==== ��й�ȣ Ȯ�� �Ϸ�  ====  \n\n");
		char* fileName = "16_file_project.txt";
		FILE* file = fopen(fileName, "a+b"); // "a+" - ������ ������ ����, ������ ������ append(�߰�) ���� ����
		if (file == NULL) {
			printf("���� ���� ����\n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);
		}

		printf("\n\n ������ ��� �ۼ��ϼ��� ! �����Ϸ��� EXIT �� �Է��ϼ���. \n\n");

		while (1) {

			scanf("%[^\n]", contents); // ����(\n)�� ������ ������ ���ڿ��� �� �ֱ�. �� �پ�
			getchar(); // ������ ����(\n) '������' �޾����Ƿ� ���� ó��. Flush ó����� �Ѵ�. ���ۿ� ���� �ִ� ���͸� ���ش�?

			if (strcmp(contents, "EXIT") == 0)
			{
				printf(" ==== �Է��� �����մϴ�. ==== \n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file); // ������ ������ �� ��Ҵ� ���͸� �߰�

		}
		fclose(file);
	}
	else {
		printf(" ==== ��й�ȣ�� Ʋ�Ⱦ��.  ====  \n\n");
	}

	return 0;
}