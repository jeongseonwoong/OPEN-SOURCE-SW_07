//과목별 할일
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

struct list {
	struct list* next;
	char subject[100];
	char things[100];
	int l_page;
};

void to_do(FILE *fp)
{
	FILE* FP = fp;
	list* now = (list*)malloc(sizeof(struct list));
	while (1)
	{
		char sub[100];
		char thg[100];
		int page;

		printf("과목(없다면 x를 입력하세요) : ");
		scanf_s("%s", &sub, SIZE);
		strcpy(now->subject, sub);
		if (sub[0] == 'x')
			break;
		printf("할일 : ");
		scanf_s("%s", &thg, SIZE);
		strcpy(now->things, thg);
		printf("마지막으로 공부한 페이지 : ");
		scanf_s("%d", &page);
		now->l_page = page;
		fprintf(FP, "과목 : %s\n", sub);
		fprintf(FP, "할일 : %s\n", thg);
		fprintf(FP, "마지막 페이지 : %d\n", page);
		fprintf(FP, "===========================\n");

		list* newnode = (list*)malloc(sizeof(struct list));
		now->next = newnode;
		now = now->next;
	}

}

int main()
{
	FILE* fp;
	fp = fopen("To_do_things.txt", "w");

	to_do(fp);

	fclose(fp);
	return 0;
}
