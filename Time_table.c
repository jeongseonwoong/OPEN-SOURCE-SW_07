#define _CRT_SECURE_NO_WARNINGS
#include "Time_table.h"

#define MAX 50

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
      printf("No time table available!");
      
      printf("Press 1 if you want to end the program\n");
      printf("Press 2 if you want to edit the original one or make a new one\n");
    }
    else
    {
      for (int i = 0; i < 13; i++)
      {
          for (int j = 0; j < 6; j++)
          {
              fscanf(in, "%s", arr[i][j]);//read from time_table.txt
          }
      }
      
      printf("time/day ");
      for (int i = 0; i < 6; i++)
      {
          print_date(i);//print weekday and weekend
      }
      printf("\n");
      
      for (int i = 0; i < 13; i++)
      {
          if(i==0)printf("%d%d~%d ", 0, 9, 10);//print time
          else printf("%d~%d ", i + 9, i + 10);//print time
          
          for (int j = 0; j < 6; j++)
          {
              printf("%s ", arr[i][j]);//print text read from time_table.txt(class name)
          }
          printf("\n");
      }
      
      printf("Press 2 if you want to edit the original one or make a new one\n");
      printf("Press 3 if you want to use the original one\n");

      fclose(in);

    }
    FILE* out;
    
    printf(">> ");
    
    int rst = 0;
    scanf("%d", &rst);
    
    if (rst == 2)//edit original or make new. get arguments. Make time table out of these arguments, and save then in time_table.txt
    {
        out=fopen("time_table.txt", "w")
    }
    else //end program || use the original
    {
        if (rst == 1)
        {
            printf("See you later. . .");
        }
        else if (rst == 3)
        {
            printf("time table saved. . .\n\n");
            printf("See you later. . .");
        }  
    }
}
