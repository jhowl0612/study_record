#include <stdio.h>

// �Լ� ����
// int �Ķ���͸� num�̶�� �̸����� �ް� ��ȯ�����δ� �ƹ� �͵� ���� �ʴ´�
void print_number(int num);

void function_without_return();
int function_with_return();
void function_without_params();
void function_with_params(int num1, int num2, int num3);
int apple(int total, int ate); // total ������ ate ���� �԰� ���� ���� ��ȯ

int main(void) {

	// function - ����

	//int num = 2;
	//print_number(num);

	//// 2 + 3
	//num = num + 3;
	//print_number(num);

	//// 5 - 1
	//num = num - 1;
	//print_number(num);

	//// 4 * 3
	//num = num * 3;
	//print_number(num);

	//// 12 / 6
	//num = num / 6;
	//print_number(num);

	// �Լ� ����
	// ��ȯ���� ���� �Լ�
	 //function_without_return();

	 // ��ȯ���� �ִ� �Լ�
	 //int ret = function_with_return();
	 //print_number(ret);

	 // �Ķ����(���ް�)�� ���� �Լ�
	 //function_without_params();

	 // �Ķ����(���ް�)�� �ִ� �Լ�
	 //function_with_params(37, 25, 12);

	// �Ķ����(���ް�)�� �ް� ��ȯ���� �ִ� �Լ�
	//int ret = apple(5, 2); // ��� 5�� �� 2���� �Ծ��ٸ� ���� ����
	//print_number(ret);
	// printf("��� 5 �� �߿��� 2 ���� ������ %d ���� ���ƿ�.\n", ret);
	// printf �Ķ���Ϳ� �Լ��� ���� �� ����
	printf("��� %d �� �߿��� %d ���� ������ %d ���� ���ƿ�.\n", 10, 4, apple(10, 4));

	return 0;
}

// �Լ� ����
void print_number(int num) {
	printf("num�� %d �Դϴ�.\n", num);
}

// �Լ��� ���� (����)
// ��ȯ�� �Լ��̸� (���ް�) {    };

void function_without_return() {
	printf("��ȯ���� ���� �Լ��Դϴ�.\n");
}
int function_with_return() {
	printf("��ȯ���� �ִ� �Լ��Դϴ�.\n");
	return 10;
}
void function_without_params() {
	printf("���ް��� ���� �Լ��Դϴ�.\n");
}
void function_with_params(int num1, int num2, int num3) {
	printf("���ް��� �ִ� �Լ��Դϴ�. ���޹��� ���� %d, %d, %d �Դϴ�.\n", num1, num2, num3);
}
int apple(int total, int ate) {
	printf("���ް��� ��ȯ���� �ִ� �Լ��Դϴ�.\n");
	return total - ate;
}
