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

		}
		else if (option == 4)
		{
			grade_main();
		}
		else if (option == 5)
		{

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
