#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 16. 입출력 프로젝트
// 비밀번호를 입력받아서 일치하면 일기를 보여주고 계속 작성
// 틀리면 경고를 출력하고 종료

#define MAX 10000

int main(void)
{
	// fgets, fputs

	char line[MAX];    // 파일에서 읽어온 데이터 저장할 변수
	char contents[MAX];    // 일기장에 입력할 내용
	char password[20];
	char c; // 비밀번호 입력할 때 ****로 표기하기 위해 (마스킹)

	printf("\n비밀번호를 입력하세요 : \n");

	// getchar - 어떤 키 입력 후 엔터를 입력받아야 작동 시작
	// getch - 키 입력 시 바로 동작

	int i = 0;
	while (1) // 한 글자 입력 시마다 반복
	{
		c = getch();
		if (c == 13) // 아스키코드 '엔터' 인가? -> 비밀번호 입력 종료
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
	printf("\n\n ==== 비밀번호 확인 중 . . .  ====  \n\n");
	if (strcmp(password, "aaaa") == 0) // 스트링 컴페어 사용해서 비교하기. 다르면 -1 이나 1 반환 (크기비교)
	{
		printf(" ==== 비밀번호 확인 완료  ====  \n\n");
		char* fileName = "16_file_project.txt";
		FILE* file = fopen(fileName, "a+b"); // "a+" - 파일이 없으면 생성, 파일이 있으면 append(추가) 모드로 열기
		if (file == NULL) {
			printf("파일 열기 실패\n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);
		}

		printf("\n\n 내용을 계속 작성하세요 ! 종료하려면 EXIT 를 입력하세요. \n\n");

		while (1) {

			scanf("%[^\n]", contents); // 엔터(\n)가 나오기 전까지 문자열을 다 넣기. 한 줄씩
			getchar(); // 위에서 엔터(\n) '전까지' 받았으므로 엔터 처리. Flush 처리라고 한다. 버퍼에 남아 있던 엔터를 없앤다?

			if (strcmp(contents, "EXIT") == 0)
			{
				printf(" ==== 입력을 종료합니다. ==== \n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file); // 콘텐츠 변수에 안 담았던 엔터를 추가

		}
		fclose(file);
	}
	else {
		printf(" ==== 비밀번호가 틀렸어요.  ====  \n\n");
	}

	return 0;
}