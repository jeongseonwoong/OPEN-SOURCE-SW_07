#include "menu.h"
#include "func.h"

void maintitle()
{
	printf("\n\n");
	printf(" ■■■■    ■■■■■■   ■■     ■■ ■■■■■■  ■■    ■■ \n");
	printf("■■    ■■     ■■	    ■■     ■■ ■■     ■■  ■■  ■■  \n");
	printf("■■             ■■       ■■     ■■ ■■     ■■   ■■■■   \n");
	printf(" ■■■■        ■■	    ■■     ■■ ■■     ■■     ■■    \n");
	printf("        ■■     ■■       ■■     ■■ ■■     ■■     ■■    \n");
	printf("■■    ■■     ■■       ■■     ■■ ■■     ■■     ■■    \n");
	printf(" ■■■■        ■■	      ■■■■■  ■■■■■■      ■■    \n\n\n");
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
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("■                                                ■\n");
		printf("■  1. 수능 D-Day, 시험 D-Day, 달력에 할 일 추가  ■\n");
		printf("■  2. 요일별 시간대별 수업 설정                  ■\n");
		printf("■  3. 학점 및 성적 계산	                  ■\n");
		printf("■  4. 과목별 진행상황                            ■\n");
		printf("■  5. 메인 화면으로 돌아가기	                  ■\n");
		printf("■                                                ■\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
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
		int select = 0;
		while (select != 9)
		{
			system("cls");
			printf("실행할 프로그램을 선택하세요\n");
			printf("수능 d-day (press '1')\n");
			printf("시간표 (press '2')\n");
			printf("시험 d-dya(press '3')\n");
			printf("끝내기(press '9')\n");
			scanf_s("%d", &select);
			if (select == 1)
			{
				dday();
			}
			else if (select == 2)
			{
				calender();
			}
			else if (select == 3)
			{
				dday2();
			}
		}
		break;
	case 2:
		time_table();
		system("cls");

		int size = find_subject();
		printf("\n\n");
		printf("[과목들]\n");
		for (int i = 0; i < size; i++)
		{
			printf("%02d. %s\n", i + 1, index[i].subject);
		}
		break;
	case 3:
		system("cls");
		int a = 0;
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("■■■■■■■■■■■■■■선택창■■■■■■■■■■■■■■\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("■■■┌──────────────┐■■■■■■■■■┌──────────────┐■■■\n");
		printf("■■■│      ■      │■■■■■■■■■│  ■■■■    │■■■\n");
		printf("■■■│    ■■      │■■■■■■■■■│ ■      ■   │■■■\n");
		printf("■■■│   ■ ■      │■■■■■■■■■│ ■      ■   │■■■\n");
		printf("■■■│      ■      │■■■■■■■■■│       ■     │■■■\n");
		printf("■■■│      ■      │■■■■■■■■■│     ■       │■■■\n");
		printf("■■■│      ■      │■■■■■■■■■│   ■         │■■■\n");
		printf("■■■│   ■■■■   │■■■■■■■■■│  ■■■■■  │■■■\n");
		printf("■■■│ 학기별 성적  │■■■■■■■■■│   나의 성적  │■■■\n");
		printf("■■■│계산 및 입력  │■■■■■■■■■│ 확인 및 관리 │■■■\n");
		printf("■■■└──────────────┘■■■■■■■■■└──────────────┘■■■\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("\n원하는 기능의 번호 입력 >> ");

		scanf_s(" %d", &a);
		if (a == 1) {
			my_grade();
		}
		if (a == 2) {
			grade_manage();
		}
		else printf("제공되지 않는 기능입니다.");

		break;
	case 4:
		choice(fp);
		break;
	case 5:
		main_screen();
		break;
	default:
		printf("잘못된 숫자 입력");
		break;
	}
	return 0;
}
