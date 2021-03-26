#include <stdio.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	printf("\n\n === === === === === \n\n");
	int answer; // 사용자 입력 값.
	int treatment = rand() % 4; // 맞는 약 (0-3)

	int cntShowBottle = 0; // 이번에 보여줄 병 갯수
	int prevcntShowBottle = 0; // 직전에 보여준 병 갯수
	// 보여주는 병 갯수를 다르게 하여 정답률 향상 (처음에 2개 -> 그 다음 3개 ...)

	// 3번의 시연
	for (int i = 1; i <= 3; i++)
	{
		int bottle[4] = { 0,0,0,0 }; // 병 4 개
		do
		{
			cntShowBottle = rand() % 2 + 2; //  보여줄 병 갯수 ( 0-1, +2 -> 2, 3 )
		} while (cntShowBottle == prevcntShowBottle); // 이전과 같은 개수로 나왔다면 다시 개수 변경
		prevcntShowBottle = cntShowBottle;

		int isIncluded = 0; // 보여준 병 중에 맞는 병이 있었는지 여부
		printf(" > %d 번째 시도 : ", i);

		// 보여줄 병 종류 선택
		for (int j = 0; j < cntShowBottle; j++){
			int randomBottle = rand() % 4; // 0-3

			// 아직 선택되지 않은 병이면 선택 처리
			if (bottle[randomBottle] == 0){
				bottle[randomBottle] = 1;

				if (randomBottle == treatment) {
					isIncluded = 1; // 맞는 약이 포함되었음
				}

			}
			else // 이미 선택된 병이라면 중복이므로 for문 한 번 더 반복
			{
				j--;
			}
		}


		// 사용자에게 표시
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1) {
				printf("%d 번째, ", k + 1);
			}
		}
		printf("약을 사용했습니다.\n\n");

		if (isIncluded == 1) {
			printf("    >>  성공 ! \n");
		}
		else {
			printf("    >>  실패\n");
		}

		printf("\n ... 계속하려면 아무 키나 입력하세요. \n");
		
		getchar(); // 사용자가 어떤 키를 입력할 때까지 대기
		// 키를 입력받으면 다음 for문을 돌게 됨

	}

	printf("약은 몇 번째 병에 있을까요? ");
	scanf_s("%d", &answer);

	if (answer == treatment+1) {
		printf("\n    >>  정답입니다!\n");
	}
	else {
		printf("\n    >>  틀렸어요 ㅜㅜ. 정답은 %d 번째 병입니다\n", treatment+1 );
	}

	return 0;
}