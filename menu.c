#include "menu.h"
#include "func.h"

void maintitle()
{
	printf("\n\n");
	printf(" ######  ######## ##     ## ########  ##    ## \n");
	printf("##    ##    ##    ##     ## ##     ##  ##  ##  \n");
	printf("##          ##    ##     ## ##     ##   ####   \n");
	printf(" ######     ##    ##     ## ##     ##    ##    \n");
	printf("      ##    ##    ##     ## ##     ##    ##    \n");
	printf("##    ##    ##    ##     ## ##     ##    ##    \n");
	printf(" ######     ##     #######  ########     ##    \n\n\n");
}

int main_screen()
{
	int n;
	maintitle();
	printf("	1. 학습 관리 프로그램 사용\n");
	printf("	2. 종료\n	>>");
	scanf_s("%d", &n);
	if (n == 1)
	{
		system("cls");
		printf("\n\n");
		printf("####################################\n");
		printf("#                                  #\n");
		printf("#  1. 수능 D-Day, 시험 D-Day	   #\n");
		printf("#  2. 요일별 시간대별 수업 설정    #\n");
		printf("#  3. 학점 및 성적 계산		   #\n");
		printf("#  4. 과목별 진행상황              #\n");
		printf("#  5. 달력에 할 일 추가            #\n");
		printf("#  6. 메인 화면으로 돌아가기	   #\n");
		printf("#                                  #\n");
		printf("####################################\n\n");
		printf("원하시는 번호를 입력하세요>> ");
		scanf_s("%d", &n);
		return n;
	}
	else
	{
		system("cls");
		printf("학습 관리 프로그램을 종료합니다.\n");
		return -1;
	}
}

int menu(FILE* fp, int num)
{
	system("cls");
	switch (num)
	{
	case 1:
		printf("D-Day 출력 함수 자리");
		break;
	case 2:
		printf("요일별 시간대별 수업 설정 함수 자리");
		break;
	case 3:
		printf("학점 및 성적 계산 함수 자리");
		break;
	case 4:
		choice(fp);
		break;
	case 5:
		printf("달력에 날짜마다 할 일 추가 함수 자리");
		break;
	case 6:
		main_screen();
		break;
	default:
		printf("잘못된 숫자 입력");
		break;
	}
	return 0;
}
