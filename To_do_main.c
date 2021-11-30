#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "To_do.h"

int main()
{
	FILE* fp;
	fp = fopen("To_do_things.txt", "a+");

	choice(fp);

	fclose(fp);
	return 0;
}
