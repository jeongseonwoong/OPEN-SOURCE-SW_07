#define _CRT_SECURE_NO_WARNINGS
#include "Time_table.h"

#define MAX 100
int size=0;

struct Node{
  char subject[MAX];
}index[MAX];

void print_date(int i, int iter)
{
    iter = iter - 2;
    if (i == 0)
    {
        printf("Mon");
        for (int j = 0; j < iter-1; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    else if (i == 1)
    {
        printf("Tue");
        for (int j = 0; j < iter; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    else if (i == 2)
    {
        printf("Wed");
        for (int j = 0; j < iter; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    else if (i == 3)
    {
        printf("Thu");
        for (int j = 0; j < iter; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    else if (i == 4)
    {
        printf("Fri");
        for (int j = 0; j < iter; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    else if (i == 5)
    {
        printf("Sat");
        for (int j = 0; j < iter; j++)
        {
            printf(" ");
        }
        printf("|");
    }
}

void find_subject()
{
    FILE* fp;
    char arr[13][6][MAX] = { 0, };
    int idx = 0;
    fp = fopen("Time_table_.txt", "rb");
    if (fp == NULL)
    {
        printf("Wrong");
        return 0;
    }
    else
    {
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                fscanf(fp, "%s", arr[i][j]);
            }
        }
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                bool arg_not_in = true;

                for (int k = 0; k < 10; k++)//check if the subject is in the structure
                {
                    if (strcmp(index[k].subject, arr[i][j]) != 0)//not in specific array
                    {
                        continue;
                    }
                    else//in specific array
                    {
                        arg_not_in = false;//check that the argument is in a specific array
                        break;
                    }
                }
                if (arg_not_in == true)//if the argument is not in a specific array
                {
                    /*for (int p = 0; p < strlen(arr[i][j]); p++)
                    {
                        index[idx].subject[p] = arr[i][j][p];
                    }*/
                    strcpy(index[idx].subject, arr[i][j]);
                    idx++;
                }
            }
        }
        fclose(fp);
        size = idx;
    }
}

void show_time_table(char arr[][6][MAX])
{
    printf("time/day |");
    for (int i = 0; i < 6; i++)
    {
        print_date(i, 22);//print weekday and weekend
    }
    printf("\n");

    for (int i = 0; i < 13; i++)
    {
        if (i == 0)printf(" %02d~%d   |", 9, 10);//print time
        else printf(" %02d~%d   |", i + 9, i + 10);//print time

        for (int j = 0; j < 6; j++)
        {
            printf("%22s| ", arr[i][j]);//print text read from time_table.txt(class name)
        }
        printf("\n");
    }
}

int get_date(char ch[])
{
    if (strcmp(ch, "Mon")==0)return 0;
    else if (strcmp(ch, "Tue") == 0)return 1;
    else if (strcmp(ch, "Wed") == 0)return 2;
    else if (strcmp(ch, "Thu") == 0)return 3;
    else if (strcmp(ch, "Fri") == 0)return 4;
    else if (strcmp(ch, "Sat") == 0)return 5;
    else
    {
        get_date(ch);
    }
}

void edit_time_table(FILE* fp, char arr[][6][MAX])
{
    char day[10], class_name[MAX];
    int Day, start_time, end_time;

    char newarr[13][6][MAX] = { 0, };
ANOTHER:
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < strlen(arr[i][j]); k++)
            {
                newarr[i][j][k] = arr[i][j][k];
            }
        }
    }

    printf("Type in the day you want to edit(ex. Mon)\n");
    printf("or 'next' for next>>");
    scanf("%s", &day);
    while (strcmp(day, "next") != 0)
    {
        printf("Starting time>>");
        scanf("%d", &start_time);

        printf("Ending time>>");
        scanf("%d", &end_time);

        printf("Class name>>");
        scanf("%s", &class_name);

        start_time -= 9;
        end_time -= 9;
        Day = get_date(day);

        for (int i = start_time; i < end_time; i++)
        {
            for (int j = 0; j < strlen(class_name); j++)
            {
                newarr[i][Day][j] = class_name[j];
            }
        }
        printf("Type in the day you want to edit(ex. Mon)\n");
        printf("or 'next' for next>>");
        scanf("%s", &day);
    }
    printf("[Original version]\n");
    show_time_table(arr);

    printf("\n[Edited version]\n");
    show_time_table(newarr);

    printf("Type in 1 if you want to save it\n");
    printf("and type in 2 if you want to use the original one\n");
    printf("and type in 3 if you want to take another attempt>>");

    int rst = 0;
    scanf("%d", &rst);
    if (rst == 1)
    {
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                fprintf(fp, "%s\n", newarr[i][j]);
            }
        }
        printf("edited one saved. . .");
    }
    else if (rst == 2)
    {
        printf("original one saved. . .");
    }
    else if (rst == 3)
    {
        goto ANOTHER;
    }
}

void  time_table()
{

    FILE* in;
    char arr[13][6][MAX] = { 0, };
AGAIN:
    if ((in = fopen("Time_table_.txt", "rb")) == NULL)//When the file doesn't exists: make new file
    {
        FILE* make;
        make = fopen("Time_table_.txt", "w");

        char *str = "NONE";
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                fprintf(make, "%s\n", str);
            }
        }
        fclose(make);

        FILE* in;
        goto AGAIN;
    }
    else
    {
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                fscanf(in, "%s", arr[i][j]);//read from the Time_table_.txt
            }
        }
        show_time_table(arr);

        printf("\n[PROGRAM]>>Press 1 if you want to edit the original one or make a new one\n");
        printf("[PROGRAM]>>Press 2 if you want to use the original one\n");
        printf("[PROGRAM]>>Press 0 if you want to end the program\n");

        fclose(in);

    }
    FILE* out;

    printf("[ME]>> ");

    int rst = 0;
    scanf("%d", &rst);

    if (rst == 1)//edit. get arguments. Make time table out of these arguments, and save then in Time_table_.txt
    {
        out = fopen("Time_table_.txt", "w");
        ftell(out);
        edit_time_table(out, arr);
        fclose(out);

        find_subject();
        printf("\n\n");
        for (int i = 0; i < size; i++)
        {
            printf("%02d. %s\n", i+1, index[i].subject);
        }
    }
    else if (rst == 2)//use the original
    {
        printf("[PROGRAM]>>time table saved. . .\n\n");
        printf("[PROGRAM]>>See you later. . .");
    }
    else if (rst == 0)//end the program
    {
        printf("[PROGRAM]>>See you later. . .");
    }
}
