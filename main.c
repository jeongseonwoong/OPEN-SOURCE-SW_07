#include"헤더.h"

int main()
{
	int option=8,select;
	select=maintitle();
	while (option != 7&&select!=2)
	{
		option = main_screen(select);
		if (option == 1)
		{
			dday();
		}
		else if (option == 2)
		{
			dday2();
		}
		else if (option == 3)
		{
			system("cls");
			interface_word("시간표 기능", "");
			Sleep(TIME*2);
			system("cls");
			time_table();
			system("cls");

			int size = find_subject();
			printf("\n\n");
			printf("[과목들]\n");
			for (int i = 0; i < size; i++)
			{
				printf("%02d. %s\n", i + 1, index[i].subject);
			}
			Sleep(TIME*3);
			system("cls");
		}
		else if (option == 4)
		{
			grade_main();
		}
		else if (option == 5)
		{
			choice();
		}
		else if (option == 6)
		{
			calender();
		}
		else if (option == 7)
		{
			break;
		}
	}

}
