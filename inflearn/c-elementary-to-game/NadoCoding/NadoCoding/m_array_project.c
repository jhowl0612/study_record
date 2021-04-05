#include <stdio.h>
#include <time.h>

// 10마리의 서로 다른 동물, 각 2장씩
// 2개의 입력값을 받아서 -> 같은 동물을 찾으면 카드를 뒤집기
// 모든 쌍을 찾으면 종료
// 총 실패 횟수 출력

int arrayAnimal[4][5]; // 카드 목록 20장
int checkAnamal[4][5]; // 카드 뒤집혔는지 1 or 0
char* strAnimal[10];
// 전역 변수는 초기화 안 해도 0으로 만들어 주나 봄

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals(); // 동물 위치 출력
void printQuestion(); // 문제 출력 ( 카드 지도 )
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

	int failCount = 0; // 실패 횟수

	while (1)
	{
		int select1 = 0; // 사용자가 선택한 수 1
		int select2 = 0; // 사용자가 선택한 수 2

		printAnimals(); // 동물 위치 출력
		printQuestion(); // 문제 출력 ( 카드 지도 )
		printf("뒤집을 카드를 2 개 고르세요 : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) // 같은 카드 선택 시 무효 
			continue;

		// 카드를 뒤집어 같은지 확인
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
			printf("\n\n정답! %s 를 발견했습니다.", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]] );
			checkAnamal[firstSelect_x][firstSelect_y] = 1;
			checkAnamal[secondSelect_x][secondSelect_y] = 1;
		}
		// 다른 동물
		else {
			printf("\n\n땡! (틀렸거나, 이미 뒤집힌 카드입니다.)\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");
			
			failCount++;
		}

		// 모든 동물을 찾았는지
		if (foundAllAnimals() == 1)
		{
			printf("\n\n 축하합니다 ! 모든 동물을 다 찾았네요. \n");
			printf("총 %d 번 실수하였습니다. \n", failCount);
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
	strAnimal[0] = "원숭이";
	strAnimal[1] = "뱀";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";
	strAnimal[5] = "코끼리";
	strAnimal[6] = "쥐";
	strAnimal[7] = "토끼";
	strAnimal[8] = "병아리";
	strAnimal[9] = "호랑이";
}
void shuffleAnimal()
{
	// □□□□□
	// □□□□□
	// □□□□□
	// □□□□□

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

// 빈 좌표 찾기
int getEmptyPosition()
{
	// □□□□□  0  1  2  3  4
	// □□□□□  5  6  7  8  9 
	// □□□□□ 10 11 12 13 14 
	// □□□□□ 15 16 17 18 19

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

void printAnimals() { // 동물 위치 출력
	// □□□□□  0  1  2  3  4
	// □□□□□  5  6  7  8  9 
	// □□□□□ 10 11 12 13 14 
	// □□□□□ 15 16 17 18 19
	printf("\n ==================정답 미리보기================== \n\n");
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
void printQuestion() { // 문제 출력 ( 카드 지도 )
	printf("\n\n [문제] \n\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// 이미 맞춘 카드면(1) '동물 이름' 출력
			if (checkAnamal[i][j] != 0) {
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// 아니면 뒷면 = 위치 숫자
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