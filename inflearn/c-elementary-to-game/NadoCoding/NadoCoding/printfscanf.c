#include <stdio.h>
int main_printfscanf(void)
{
	////����

	//int age = 12;
	//printf("%d\n", age); // 12
	//// %d = ���� �޸�(,) �ڿ� ���� ������ ���� �� �ڸ��� ����� ���̶�� ��
	//age = 13;
	//printf("%d\n", age); // 12 \ 13
	//int one = 1;
	//int two = 2;
	//printf("%d\n%d\n", one, two); // 1 \ 2
	//// %d�� ������ ���� ���� ����� ���� ���ʴ�� ��.

	///* �ּ��� CSS�� ���� ���� */


	//// �Ǽ�

	//float f = 46.5f; // �÷� �ڿ��� f ���� ��
	//// %f = �÷� �� �ڸ�
	//printf("%f\n", f); // 46.500000
	//printf("%.2f\n", f); // 46.50, �Ҽ��� ��° �ڸ�����

	//// %lf = ���� �� �ڸ�
	//double d = 4.428; // ���� �ڿ��� f �� �ٿ��� ��
	//printf("%.2lf\n", d); // 4.43, �ݿø� �Ҽ��� ��° �ڸ�����


	//// ���
	//const int YEAR = 2000; // const -  ������ �Ұ��� ����� ���� �빮�� ǥ��
	//printf("�¾ �⵵ : %d\n", YEAR);
	//// YEAR = 2001; // �����߻�


	//printf
	//����
	// int add = 3 + 7;

	//printf("3 + 7 = %d\n", add);
	//printf("%d * %d = %d\n", 30, 79, 30*79);

	//scanf
	// Ű���� �Է��� �޾Ƽ� ����
	/*int input;
	printf("���� �Է��ϼ��� : ");
	scanf_s("%d", &input);
	printf("�Է°� : %d\n", input);*/

	/*int one, two, three;
	printf("3���� ������ �Է��ϼ��� : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("ù ��° �� : %d\n", one);
	printf("�� ��° �� : %d\n", two);
	printf("�� ��° �� : %d\n", three);*/

	// ����(�� ����), ���ڿ�(�� ���� �̻��� ���� ����)
	/*char c = 'A';
	printf("%c\n", c);*/

	// ���ڿ��� scanf_s ���� �� & ���ΰ� �ʿ������ ��� ���ڿ� ���� ��ð� �ʿ���
	// str ���ڿ��� ���� = sizeof(str)
	/*char str[256];
	scanf_s("%s", str, sizeof(str));
	printf("%s\n", str);*/


	// ������Ʈ
	// �������� �������� ������ �Լ� (���� �ۼ�)
	// �̸�? ����? ������? Ű? ���˸�?

	char name[256];
	printf("�̸��� ������? ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("�� ���̿���? ");
	scanf_s("%d", &age);

	float weight;
	printf("�����Դ� �� kg�̿���? ");
	scanf_s("%f", &weight);

	double height;
	printf("Ű�� �� cm����? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("���� ���˸� ����������? ");
	scanf_s("%s", what, sizeof(what));


	printf("\n\n--- ������ ���� ---\n\n");
	printf(" �̸�      : %s\n",name);
	printf(" ����      : %d\n", age);
	printf(" ������    : %.2f\n", weight);
	printf(" Ű        : %.2lf\n", height);
	printf(" ���˸�    : %s\n", what);


	return 0;
}