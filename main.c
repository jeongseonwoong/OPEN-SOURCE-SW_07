#include"헤더.h"

int first()
{
	int option;
	option=main_screen();
	return option;
}
int main()
{
	int option;
	option=first();
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

	}
	else if (option == 5)
	{

	}
	else if (option == 6)
	{
		calender();
	}

}
