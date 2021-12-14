#include "학습프로그램.h"


void grade_main() {

	system("cls");
	int a = 0;
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■선택창■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■■■┌──────────────┐■■■■■■■■■┌──────────────┐■■■■■■■■■┌──────────────┐■■■\n");
	printf("■■■│      ■      │■■■■■■■■■│  ■■■■    │■■■■■■■■■│   ■■■■   │■■■\n");
	printf("■■■│    ■■      │■■■■■■■■■│ ■      ■   │■■■■■■■■■│  ■      ■  │■■■\n");
	printf("■■■│   ■ ■      │■■■■■■■■■│ ■      ■   │■■■■■■■■■│        ■    │■■■\n");
	printf("■■■│      ■      │■■■■■■■■■│       ■     │■■■■■■■■■│    ■■■    │■■■\n");
	printf("■■■│      ■      │■■■■■■■■■│     ■       │■■■■■■■■■│         ■   │■■■\n");
	printf("■■■│      ■      │■■■■■■■■■│   ■         │■■■■■■■■■│  ■      ■  │■■■\n");
	printf("■■■│   ■■■■   │■■■■■■■■■│  ■■■■■  │■■■■■■■■■│   ■■■■   │■■■\n");
	printf("■■■│ 학기별 성적  │■■■■■■■■■│  나의 성적   │■■■■■■■■■│              │■■■\n");
	printf("■■■│ 계산 및 입력 │■■■■■■■■■│ 계산 및 관리 │■■■■■■■■■│   뒤로가기   │■■■\n");
	printf("■■■└──────────────┘■■■■■■■■■└──────────────┘■■■■■■■■■└──────────────┘■■■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n원하는 기능의 번호 입력 >> ");

	scanf_s(" %d", &a);
	if (a == 1) {
		my_grade();
	}
	if (a == 2) {
		grade_manage();
	}
	if (a == 3) {
		system("cls");
		main();
	}
	else printf("제공되지 않는 기능입니다.");
}


void grade_check(int a, int b) {

	system("cls");
	printf("┌───────%d학년 %d학기───────────────────────┐\n", a, b);

	int c = 0;
	FILE* fp = NULL;
	if (a == 1 && b == 1) {
		fp = fopen("1-1.txt", "r");
	}
	else if (a == 1 && b == 2) {
		fp = fopen("1-2.txt", "r");
	}
	else if (a == 2 && b == 1) {
		fp = fopen("2-1.txt", "r");
	}
	else if (a == 2 && b == 2) {
		fp = fopen("2-2.txt", "r");
	}
	else if (a == 3 && b == 1) {
		fp = fopen("3-1.txt", "r");
	}
	else if (a == 3 && b == 2) {
		fp = fopen("3-2.txt", "r");
	}
	else if (a == 4 && b == 1) {
		fp = fopen("4-1.txt", "r");
	}
	else if (a == 4 && b == 2) {
		fp = fopen("4-2.txt", "r");
	}
	else if (a == 5 && b == 1) {
		fp = fopen("5-1.txt", "r");
	}
	else if (a == 5 && b == 2) {
		fp = fopen("5-2.txt", "r");
	}
	else if (a == 6 && b == 1) {
		fp = fopen("6-1.txt", "r");
	}
	else if (a == 6 && b == 2) {
		fp = fopen("6-2.txt", "r");
	}

	if (fp == NULL) {
		printf("│                                         │\n");
		printf("│                                         │\n");
		printf("│                                         │\n");
		printf("│      입력 정보가 존재하지 않습니다      │\n");
		printf("│                                         │\n");
		printf("│                                         │\n");
		printf("│                                         │\n");
		printf("└─────────────────────────────────────────┘\n");
		printf("\n입력하시려면 1을 입력해주세요 : ");
		scanf("%d", &c);
		if (c == 1) put_data(a, b);
	}

	else {
		char line[10000];
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
		printf("\n수정하시려면 1을 입력해주세요 : ");
		scanf("%d", &c);
		if (c == 1) put_data(a, b);
	}
}
void my_grade() {

	system("cls");
	int a = 0;
	int b, c = 0;
	int count4 = 1;
	printf("┌───────  입력하실 학기를 선택하세요 ─────┐\n│                                         │\n");
	for (int i = 1; i < 7; i++) {
		if (i < 6) {
			for (int e = 1; e < 3; e++) {
				if (count4 < 10) {
					printf("│");
					printf("             %d. %d학년 %d학기              │\n│                                         │ \n", count4, i, e);
					count4++;
				}
				if (count4 == 10) {
					printf("│");
					printf("            %d. %d학년 %d학기              │\n│                                         │\n", count4, i, e);
					count4++;
				}
			}
		}
		else {
			for (int e = 1; e < 3; e++) {
				printf("│");
				printf("            %d. %d학년 %d학기              │\n│                                         │\n", count4, i, e);
				count4++;
			}
		}
	}
	printf("└─────────────────────────────────────────┘\n\n");

	printf(">> ");
	scanf("%d", &a);
	if (a == 1) {
		b = 1; c = 1;
	}
	else if (a == 2) {
		b = 1; c = 2;
	}
	else if (a == 3) {
		b = 2; c = 1;
	}
	else if (a == 4) {
		b = 2; c = 2;
	}
	else if (a == 5) {
		b = 3; c = 1;
	}
	else if (a == 6) {
		b = 3; c = 2;
	}
	else if (a == 7) {
		b = 4; c = 1;
	}
	else if (a == 8) {
		b = 4; c = 2;
	}
	else if (a == 9) {
		b = 5; c = 1;
	}
	else if (a == 10) {
		b = 5; c = 2;
	}
	else if (a == 11) {
		b = 6; c = 1;
	}
	else if (a == 12) {
		b = 6; c = 2;
	}
	else {
		printf("잘못된 입력입니다. 돌아가시려면 0을 입력해주세요");
		printf("\n >> ");
		int x = -1;
		scanf("%d", &x);
		if (x == 0) grade_main();
	}
	grade_check(b, c);
}

void put_data(a, b) {
	system("cls");
	char name[50][50];
	int grade[20] = { 0, };
	int times[20] = { 0, };
	int major_grade[20] = { 0, };
	int major_times[20] = { 0, };
	int i = 0;
	int count = 0;
	int major = 0;
	float GPA = 0;
	float major_GPA = 0;
	float sum = 0;
	float major_sum = 0;
	int sum2 = 0;
	int major_sum2 = 0;
	int count1 = 0;
	int count3 = 0;
	while (1)
	{
		char grade1[3];
		system("cls");
		printf("┌────────────────% d학년% d학기───────────────────────────────────┐\n│                                                               │\n", a, b);
		printf("│    학점계산기입니다.                                          │\n│    입력을 모두 하였을경우 과목명에 1을 입력하여 주십시오.     │\n│                                                               │");

		printf("\n└───────────────────────────────────────────────────────────────┘\n");
		printf("────────────────────────────────────────────\n");
		if (count3 > 0) {
			printf("\n");
			for (int w = 0; w < count3; w++) {
				printf(" - 입력된 과목명 : %s\n", name[w]);
			}
			printf("\n");
			printf("────────────────────────────────────────────\n");
		}

		printf("\n  과목명을 입력하여 주십시오 : ");
		rewind(stdin);
		scanf("%[^\n]", &name[i]);
		if (name[i][0] == '1') break;
		printf("\n  평점을 입력하여 주십시오");
		printf(" (Ex.A+) : ");
		rewind(stdin);
		scanf("%s", grade1);
		if (strcmp(grade1, "A+") == 0) {

			grade[i] = 1;
		}
		else if (strcmp(grade1, "A0") == 0 || strcmp(grade1, "AO") == 0 || strcmp(grade1, "Ao") == 0) {

			grade[i] = 2;
		}
		else if (strcmp(grade1, "B+") == 0) {

			grade[i] = 3;
		}
		else if (strcmp(grade1, "B0") == 0 || strcmp(grade1, "BO") == 0 || strcmp(grade1, "Bo") == 0) {

			grade[i] = 4;
		}
		else if (strcmp(grade1, "C+") == 0) {

			grade[i] = 5;
		}
		else if (strcmp(grade1, "C0") == 0 || strcmp(grade1, "CO") == 0 || strcmp(grade1, "Co") == 0) {

			grade[i] = 6;
		}
		else if (strcmp(grade1, "D+") == 0) {

			grade[i] = 7;
		}
		else if (strcmp(grade1, "D0") == 0 || strcmp(grade1, "DO") == 0 || strcmp(grade1, "Do") == 0) {

			grade[i] = 8;
		}
		else if (strcmp(grade1, "F") == 0) {
			grade[i] = 9;
		}
		else {
			printf("\n  존재하지 않는 평점입니다.");
			exit(1);

		}
		printf("\n  과목의 학점을 입력하시오 : ");
		scanf("%d", &times[i]);
		printf("\n  전공과목일 경우 1 아닐경우 2를 입력하여 주십시오 : ");
		scanf("%d", &major);
		if (major == 1) {
			major_grade[i] = grade[i];
			major_times[i] = times[i];
			count++;
		}
		count3++;
		sum = GPAsum(grade[i], times[i], sum);
		sum2 = timesum(times[i], sum2);
		if (major == 1)
		{
			major_sum = GPAsum(major_grade[i], major_times[i], major_sum);
			major_sum2 = timesum(major_times[i], major_sum2);
			count1++;
		}
		i++;
		count++;
	}
	if (name[i][0] == '1' && count3 == 0) {
		system("cls");
		printf("입력받은 정보가 없습니다\n");
		printf("돌아가려면 1을 입력하세요 : ");
		int c = 0;
		scanf("%d", &c);
		if (c == 1) {
			grade_main();
		}
		else exit(1);
	}
	else {
		system("cls");
		FILE* fp = NULL;
		char line[10000];
		if (a == 1 && b == 1) {
			fp = fopen("1-1.txt", "w+");
		}
		else if (a == 1 && b == 2) {
			fp = fopen("1-2.txt", "w+");
		}
		else if (a == 2 && b == 1) {
			fp = fopen("2-1.txt", "w+");
		}
		else if (a == 2 && b == 2) {
			fp = fopen("2-2.txt", "w+");
		}
		else if (a == 3 && b == 1) {
			fp = fopen("3-1.txt", "w+");
		}
		else if (a == 3 && b == 2) {
			fp = fopen("3-2.txt", "w+");
		}
		else if (a == 4 && b == 1) {
			fp = fopen("4-1.txt", "w+");
		}
		else if (a == 4 && b == 2) {
			fp = fopen("4-2.txt", "w+");
		}
		else if (a == 5 && b == 1) {
			fp = fopen("5-1.txt", "w+");
		}
		else if (a == 5 && b == 2) {
			fp = fopen("5-2.txt", "w+");
		}
		else if (a == 6 && b == 1) {
			fp = fopen("6-1.txt", "w+");
		}
		else if (a == 6 && b == 2) {
			fp = fopen("6-2.txt", "w+");
		}

		if (fp == NULL)
		{
			printf("파일 열기 실패\n");
		}

		fprintf(fp, "%d학년 %d학기\n", a, b);
		for (int i = 0; i < count; i++)
		{
			if (grade[i] == 1) {
				fprintf(fp, "과목명 : %s\n", name[i]);
				fprintf(fp, "평점 : A+\n학점 : %d\n", times[i]);
			}
			else if (grade[i] == 2) {
				fprintf(fp, "과목명 : %s\n", name[i]);
				fprintf(fp, "평점 : A0\n학점 : %d\n", times[i]);
			}
			else if (grade[i] == 3) {
				fprintf(fp, "과목명 : %s\n", name[i]);
				fprintf(fp, "평점 : B+\n학점 : %d\n", times[i]);
			}
			else if (grade[i] == 4) {
				fprintf(fp, "과목명 : %s\n", name[i]);
				fprintf(fp, "평점 : B0\n학점 : %d\n", times[i]);
			}
			else if (grade[i] == 5) {
				fprintf(fp, "과목명 : %s\n", name[i]);
				fprintf(fp, "평점 : C+\n학점 : %d\n", times[i]);
			}
			else if (grade[i] == 6) {
				fprintf(fp, "과목명 : %s\n", name[i]);
				fprintf(fp, "평점 : C0\n학점 : %d\n", times[i]);
			}
			else if (grade[i] == 7) {
				fprintf(fp, "과목명 : %s\n", name[i]);
				fprintf(fp, "평점 : D+\n학점 : %d\n", times[i]);
			}
			else if (grade[i] == 8) {
				fprintf(fp, "과목명 : %s\n", name[i]);
				fprintf(fp, "평점 : D0\n학점 : %d\n", times[i]);
			}
			else if (grade[i] == 9) {
				fprintf(fp, "과목명 : %s\n", name[i]);
				fprintf(fp, "평점 : F\n학점 : %d\n", times[i]);
			}
		}
		fprintf(fp, "\n이수학점 : %d", sum2);
		fprintf(fp, "\nGPA : %.2f", (float)sum / sum2);
		if (count1 != 0) {
			fprintf(fp, "\nmajor GPA : %.2f\n", (float)major_sum / major_sum2);
		}

		fclose(fp);

		if (a == 1 && b == 1) {
			fp = fopen("1-1.txt", "r");
		}
		else if (a == 1 && b == 2) {
			fp = fopen("1-2.txt", "r");
		}
		else if (a == 2 && b == 1) {
			fp = fopen("2-1.txt", "r");
		}
		else if (a == 2 && b == 2) {
			fp = fopen("2-2.txt", "r");
		}
		else if (a == 3 && b == 1) {
			fp = fopen("3-1.txt", "r");
		}
		else if (a == 3 && b == 2) {
			fp = fopen("3-2.txt", "r");
		}
		else if (a == 4 && b == 1) {
			fp = fopen("4-1.txt", "r");
		}
		else if (a == 4 && b == 2) {
			fp = fopen("4-2.txt", "r");
		}
		else if (a == 5 && b == 1) {
			fp = fopen("5-1.txt", "r");
		}
		else if (a == 5 && b == 2) {
			fp = fopen("5-2.txt", "r");
		}
		else if (a == 6 && b == 1) {
			fp = fopen("6-1.txt", "r");
		}
		else if (a == 6 && b == 2) {
			fp = fopen("6-2.txt", "r");
		}

		printf("┌───────%d학년 %d학기───────────────────────┐\n", a, b);
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
		int r = 0;
		printf("\n메인화면으로 돌아가려면 1을 입력하세요 : ");
		scanf("%d", &r);
		if (r == 1) {
			system("cls");
			grade_main();
		}
	}
}

float GPAsum(int grade, int times, float sum) {
	float a;

	switch (grade) {

	case 1:
		a = 4.5;
		break;
	case 2:
		a = 4.0;
		break;
	case 3:
		a = 3.5;
		break;
	case 4:
		a = 3.0;
		break;
	case 5:
		a = 2.5;
		break;
	case 6:
		a = 2.0;
		break;
	case 7:
		a = 1.5;
		break;
	case 8:
		a = 1.0;
		break;
	case 9:
		a = 0;
		break;
	}

	float k = a * times;
	sum = sum + k;

	return sum;
}

int timesum(int times, int sum2) {

	sum2 = sum2 + times;

	return sum2;
}

void grade_manage() {

	system("cls");
	char line[1000];
	FILE* fp = NULL;
	fp = fopen("test.txt", "w");
	fclose(fp);
	fp = fopen("test.txt", "r");
	int count = 0;

	if (fopen("1-1.txt", "r") != NULL) {
		count++;
		printf("\n┌───────1학년 1학기───────────────────────┐\n");
		fp = fopen("1-1.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (fopen("1-2.txt", "r") != NULL) {
		count++;
		printf("\n┌───────1학년 2학기───────────────────────┐\n");
		fp = fopen("1-2.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (fopen("2-1.txt", "r") != NULL) {
		count++;
		printf("\n┌───────2학년 1학기───────────────────────┐\n");
		fp = fopen("2-1.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (fopen("2-2.txt", "r") != NULL) {
		count++;
		printf("\n┌───────2학년 2학기───────────────────────┐\n");
		fp = fopen("2-2.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (fopen("3-1.txt", "r") != NULL) {
		count++;
		printf("\n┌───────3학년 1학기───────────────────────┐\n");
		fp = fopen("3-1.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (fopen("3-2.txt", "r") != NULL) {
		count++;
		printf("\n┌───────3학년 2학기───────────────────────┐\n");
		fp = fopen("3-2.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (fopen("4-1.txt", "r") != NULL) {
		count++;
		printf("\n┌───────4학년 1학기───────────────────────┐\n");
		fp = fopen("4-1.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (fopen("4-2.txt", "r") != NULL) {
		count++;
		printf("\n┌───────4학년 2학기───────────────────────┐\n");
		fp = fopen("4-2.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (fopen("5-1.txt", "r") != NULL) {
		count++;
		printf("\n┌───────5학년 1학기───────────────────────┐\n");
		fp = fopen("5-1.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (fopen("5-2.txt", "r") != NULL) {
		count++;
		printf("\n┌───────5학년 2학기───────────────────────┐\n");
		fp = fopen("5-2.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (fopen("6-1.txt", "r") != NULL) {
		count++;
		printf("\n┌───────6학년 1학기───────────────────────┐\n");
		fp = fopen("6-1.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (fopen("6-2.txt", "r") != NULL) {
		count++;
		printf("\n┌───────6학년 2학기───────────────────────┐\n");
		fp = fopen("6-2.txt", "r");
		printf("\n");
		while (fgets(line, 1000, fp) != NULL) {
			printf("│                                         │   \n");
			printf("│    %s", line);
		}
		printf("\n└─────────────────────────────────────────┘");
		fclose(fp);
	}
	if (count == 0) printf("┌───────입력된 정보가 없습니다.───────────────────────┐\n");
	int o = 0;
	printf("\n돌아가려면 1을 입력하세요 : ");
	scanf("%d", &o);
	if (o == 1) grade_main();
}
