#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 15. ���� �����
// ���Ͽ� ������ ����
// ���Ͽ� ����� ������ �ҷ�����


#define MAX 10000
int main_file(void)
{
	// fputs, fgets
    // fprintf, fscanf


	// fputs, fgets - �ַ� ���ڿ� �����

	char line[MAX]; // ���� �ڸ��� ������ �� ������ ���(define)�� ����

	// ���� ����
	//FILE* file = fopen("15_test1.txt", "wb"); // ���ϸ�, ���� ����
	// ���� ���� r �б����� | w ���� ���� | a �ڿ� �߰�
	// w�� ���� ���� ������ �� ����� ó������ �ۼ���
	// t �ؽ�Ʈ | b ���̳ʸ� ������

	/*if (file == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}
	printf("���� ���� ����\n");
	fputs("fputs �� �̿��ؼ� ���� �����ϴ�.\n", file);
	fputs("�� �������� Ȯ���մϴ�.\n", file);*/

	// �� ������ ���� ���� ���¿��� ���α׷��� ������ ����� ������ �ս� �߻�
	// �׻� ���� �� �ݱ�
	//fclose(file);


	// ���� �б�
	//FILE* file = fopen("15_test1.txt", "rb"); // �б� ����, ���̳ʸ�
	//if (file == NULL) {
	//	printf("���� ���� ����\n");
	//	return 1;
	//}
	//printf("���� ���� ����\n");
	//
	//while (fgets(line,MAX,file) != NULL) // ���ڿ� ������ ��, ������, ���ϸ�
	//{
	//	printf("%s", line);
	//}

	//fclose(file);

	// fputs, fgets - �ַ� ���ڿ� �����
	

	// fprintf, fscanf - %d, %s ���� ����Ͽ� Ư�� �ڸ��� Ư�� �����͸� ������� ��
	int num[6] = { 0, 0, 0, 0, 0, 0 }; // ��÷��ȣ
	int bonus = 0; // ���ʽ���ȣ
	char str1[MAX]; // ���� �о���� �� ������ ����
	char str2[MAX];

	// ����
	//FILE * file = fopen("15_test2.txt", "wb");
	//if (file == NULL) {
	//	printf("���� ���� ����\n");
	//	return 1;
	//}
	//printf("���� ���� ����\n");

	//// �ζ� ��÷ ��ȣ ����

	//fprintf(file, "%s %d %d %d %d %d %d\n", "��÷��ȣ ", 1,2,3,4,5,6);
	//fprintf(file, "%s %d\n", "���ʽ���ȣ ", 7);

	//fclose(file);

	// �б�
	FILE* file = fopen("15_test2.txt", "rb"); // �б� ����, ���̳ʸ�
	if (file == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}
	printf("���� ���� ����\n");
	
	fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);

	fscanf(file, "%s %d", str2, &bonus);
	printf("%s %d\n", str2, bonus);

	fclose(file);

	return 0;
}