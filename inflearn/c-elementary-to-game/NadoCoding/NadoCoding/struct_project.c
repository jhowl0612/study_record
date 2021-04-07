#include <stdio.h>
#include <time.h>

// 13. 구조체 프로젝트

// 5 종류의 고양이가 있다
// 아무 키나 눌러서 랜덤으로 고양이를 뽑되
// 5 종류 모두 수집해서 기르는(생략) 게임
// 중복 가능(!)

// 고양이
// 이름, 나이, 성격, 키우기 난이도(레벨)

typedef struct {
	char* name; // 이름
	int age; // 나이
	char* character; // 성격
	int level; // 키우기 난이도(레벨 1-5, 5로 갈수록 어려움)

} CAT;

// 현재까지 보유한 고양이 상자
int collection[5] = {0, 0, 0, 0, 0};

// 전체 고양이 리스트
CAT cats[5];

void initCats(); // 고양이 정보 초기화
void printCat(int selected);
int checkCollection();


int main_struct_project(void)
{
	srand(time(NULL));

	initCats();

	while (1) {

		printf("어느 고양이를 만나게 될까요? \n ====> 아무 키나 눌러서 확인해보세요.");
		getchar(); // 아무 키나 입력할 때까지 기다리기

		int selected = rand() % 5; // 0-4
		printCat(selected); // 뽑은 고양이 정보 출력
		collection[selected] = 1; // 고양이 뽑은 후 처리 - 해당 칸 true

		int collectAll = checkCollection();

		if (collectAll) // collectAll == 1 다 데려왔을 경우
		{
			printf("\n\n 축하합니다 ! 모든 고양이를 데려왔어요. 열심히 키워주세요. \n\n");
			printf(" ====> 아무 키나 누르면 종료됩니다.");
			getchar();
			break;
		}

	}

	return 0;
}

void initCats()
{
	cats[0].name = "우주";
	cats[0].age = 7;
	cats[0].character = "온순함";
	cats[0].level = 1;

	cats[1].name = "연님";
	cats[1].age = 3;
	cats[1].character = "까칠함";
	cats[1].level = 2;

	cats[2].name = "감자";
	cats[2].age = 4;
	cats[2].character = "잠이 많음";
	cats[2].level = 3;

	cats[3].name = "삼색";
	cats[3].age = 5;
	cats[3].character = "애교가 많음";
	cats[3].level = 4;

	cats[4].name = "무";
	cats[4].age = 1;
	cats[4].character = "심탐이 강함";
	cats[4].level = 5;
}

void printCat(int selected)
{
	printf("\n\n ==== 당신은 이 고양이의 집사가 되었어요 ! ==== \n\n");
	printf("     이름     : %s\n", cats[selected].name);
	printf("     나이     : %d\n", cats[selected].age);
	printf("  특징(성격)  : %s\n", cats[selected].character);
	//printf("    난이도    : %d", cats[selected].level);
	printf("    난이도    : ");
	
	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("%s","★");
	}
	printf("\n\n");
}

int checkCollection()
{
	// 1. 현재 보유한 고양이 목록 출력
	// 2. 다 데려왔는지 여부 출력
	int collectAll = 1;

	printf("\n\n ================ 데려온 고양이 목록 ================ \n\n");

	for (int i = 0; i < 5; i++) // collection 배열의 길이만큼
	{
		if (collection[i] == 0) // 해당 고양이 없음
		{
			printf("%10s", "(빈 상자)");
			collectAll = 0; // 데려오지 못한 고양이가 있을 경우
		}
		else // 해당 고양이 있음
		{
			printf("%10s", cats[i].name);
		}
	}
	printf("\n\n ==================================================== \n\n");

	return collectAll;
}