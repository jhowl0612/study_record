#include <stdio.h>

// �Լ� ����
// int �Ķ���͸� num�̶�� �̸����� �ް� ��ȯ�����δ� �ƹ� �͵� ���� �ʴ´�
void print_number(int num);


int main(void) {

	// function - ����

	int num = 2;
	print_number(num);

	// 2 + 3
	num = num + 3;
	print_number(num);

	// 5 - 1
	num = num - 1;
	print_number(num);

	// 4 * 3
	num = num * 3;
	print_number(num);

	// 12 / 6
	num = num / 6;
	print_number(num);

	return 0;
}

// �Լ� ����
void print_number(int num) {
	printf("num�� %d �Դϴ�.\n", num);
}

// �Լ��� ���� (����)
// ��ȯ�� �Լ��̸� (���ް�) {    };
