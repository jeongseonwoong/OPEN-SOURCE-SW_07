#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define SIZE 100

#ifndef __FUNC_H__
#define __FUNC_H__

struct list {
	struct list* next;
	char subject[100];
	char things[100];
	int l_page;
}person;
#endif

void to_do(FILE* fp);
void choice(FILE* fp);
