#include <stdio.h>

int main(void)
{
	// ������ �迭 Multidimensional Array;

	// int i; // ��
	// int arr[5];
	// ������
	// [0][1][2][3][4]
	
	// int arr2[2][5];
	// ������
	// ������
	 
	// [0,0][0,1][0,2][0,3][0,4] -> arr2[0][0]
	// [1,0][1,1][1,2][1,3][1,4] -> arr2[1][4]


	// int arr3[4][2];
	// ���
	// ���
	// ���
	// ���

	// [0,0][0,1]
	// [1,0][1,1]
	// [2,0][2,1]
	// [3,0][3,1] -> arr3[3][1]

	// int arr4[3][3][3];
	// ����
	// ����
	// ����
	
	// ����
	// ����
	// ����
	
	// ����
	// ����
	// ����

	int arr[5] = { 1,2,3,4,5 };
	int arr2[2][5] = { 
		{ 1,2,3,4,5 }, 
		{ 1,2,3,4,5 } 
	};
	int arr3[4][2] = { 
		{ 1,2 }, 
		{ 1,2 }, 
		{ 1,2 }, 
		{ 1,2 } 
	};
	int arr4[3][3][3] = { 
		{ 
			{ 1,2,3 },
			{ 1,2,3 },
			{ 1,2,3 } 
		}, 
		{ 
			{ 1,2,3 },
			{ 1,2,3 },
			{ 1,2,3 }
		}, 
		{ 
			{ 1,2,3 },
			{ 1,2,3 },
			{ 1,2,3 } 
		} 
	};






	return 0;
}