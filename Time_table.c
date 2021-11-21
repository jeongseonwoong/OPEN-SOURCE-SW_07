#define _CRT_SECURE_NO_WARNINGS
#include "Time_table.h"

#define MAX 50

/*struct {
    char arr[6][MAX];//subject name for each class(6 subjects. X for 'No subject')
}time[13];*/

void print_date(int i)
{
    if (i == 0)printf("Mon ");
    else if (i == 1)printf("Tue ");
    else if (i == 2)printf("Wed ");
    else if (i == 3)printf("Thu ");
    else if (i == 4)printf("Fri ");
    else if (i == 5)printf("Sat ");
}

void  time_table()
{
    FILE *in;
    char arr[13][6][MAX];
    if((in=fopen("time_table.txt", "r"))==NULL))//When the file doesn't exists
    {
      printf("wrong");//get arguments. Make time table out of these arguments, and save then in files.
    }
    else
    {
      for (int i = 0; i < 13; i++)
      {
          for (int j = 0; j < 6; j++)
          {
              fscanf(in, "%s", arr[i][j]);
          }
      }
      printf("time/day ");
      for (int i = 0; i < 6; i++)
      {
          print_date(i);
      }
      printf("\n");
      for (int i = 0; i < 13; i++)
      {
          if(i==0)printf("%d%d~%d ", 0, 9, 10);
          else printf("%d~%d ", i + 9, i + 10);
          for (int j = 0; j < 6; j++)
          {
              printf("%s ", arr[i][j]);
          }
          printf("\n");
      }
      fclose(in);

      //read file

    }

}
