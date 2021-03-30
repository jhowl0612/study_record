#include <stdio.h>
#include <time.h>

// 물고기 6마리가 각각 어항에 들어 있음
// 각 어항의 물이 말라 가므로 어항에 물을 주기
// 일정 시간 이상 성공

// 전역 변수
int level;
int arrayFish[6];
int* cursor; // pointer.c 의 미션맨 같은 역할

// 함수 선언
void initData();
void printFishes();
void decreaseWater(long elapsedTime);


int main(void)
{
	// 시간 변수는 보통 long형
	long startTime = 0; // 시작 시간
	long totalElapsedTime = 0; // 총 경과 시간
	long prevElapsedTime = 0; // 직전 경과 시간 (직전에 물을 준 시간 간격)

	int num; // 몇 번 어항에 물을 줄 것인지 사용자 입력
	initData();

	cursor = arrayFish; // cursor[0] 처럼 배열을 자유자재 선택 가능

	startTime = clock(); // 현재시각을 millisecond(1000분의 1초) 단위로 반환
	while (1)  // 무한 반복
	{
		printFishes(); // 어항 상태 출력
		printf("몇 번 어항에 물을 줄까요?");
		scanf_s("%d", &num);

		if (num < 1 || num > 6) {
			printf("\n입력값이 잘못되었습니다.\n\n");
			continue;
		}

		// 총 경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // 밀리초를 초로 바꾸기 위해 1000으로 나눔
		printf("총 경과 시간 : %1d 초\n", totalElapsedTime);

		// 직전 마지막으로 물 준 시간 '이후로 흐른 시간' 저장
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %1d 초\n", prevElapsedTime);

		// 어항의 물 감소
		decreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물을 줌
		// 1. 어항의 물이 0이면 : 물을 주지 않는다.
		if (cursor[num - 1] <= 0) {
			printf("%d 번 물고기는 이미 죽었습니다... 물을 주지 않습니다.\n", num);
		}
		// 2. 어항의 물이 0이 아닌 경우 물을 준다. 단, 100을 넘지 않는지 체크
		else if (cursor[num - 1] < 100) {
			printf("%d 번 어항에 물을 줍니다.\n", num);
			cursor[num - 1] += 1;
		}

		// 레벨업을 할 건지 확인 (레벨업은 20초(변경가능)마다 한 번씩)
		if (totalElapsedTime / 10 > (level - 1)) {
			level++;
			printf(" *** 축 레벨업 ! 기존 %d 레벨에서 %d 레벨로 업그레이드 ***\n\n", level - 1, level);

			if (level >= 5) {
				printf("\n\n축하합니다. 최고 레벨을 달성하였습니다. 게임을 종료합니다.\n\n");
				exit(0);
			}
		}

		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0) {
			printf("\n\n모든 물고기가 죽었습니다 ㅜ\n\n");
			exit(0);
		}
		else {
			// 하나 이상 살아 있음
			printf("\n\n물고기가 아직 살아 있어요!\n\n");
		}
		prevElapsedTime = totalElapsedTime;
		//prevElapsedTime에 '마지막으로 물 준 경과시간' 저장
	}

	return 0;
}
void initData() {
	level = 1;
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100; // 어항의 물 높이 (0-100);

	}
};
void printFishes() {
	printf(" %d번  %d번  %d번  %d번  %d번  %d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf(" %3d ", arrayFish[i]);
	}
	printf("\n\n");
}
void decreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 1 * (int)elapsedTime); //  3(변경가능)은 난이도조절을 위한 값
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