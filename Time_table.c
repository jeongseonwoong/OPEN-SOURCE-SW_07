#define _CRT_SECURE_NO_WARNINGS
#include "Time_table.h"

#define MAX 100
int size=0;


void print_subject(char arr[], int max)
{
    int size = strlen(arr);

    for (int i = 0; i < max - size; i++)
    {
        printf(" ");
    }
    if (strcmp(arr, "____") == 0)printf(" %s|", "    ");
    else printf(" %s|", arr);
}


void print_table_format(int size)
{
    size = (size + 2) * 6 + 10;
    for (int i = 0; i < size; i++)
    {
        printf("─");
    }
    printf("\n");
}


int get_max(char  arr[][6][MAX])
{
    int max = 0;
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (strlen(arr[i][j]) > max)max = strlen(arr[i][j]);
        }
    }

    return max;
}


void print_date(int i, int iter)
{
    iter = iter - 2;
    if (i == 0)
    {
        printf("Mon");
        for (int j = 0; j < iter; j++)
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
                    if(strcmp(arr[i][j], "____")==0)//if no subjects, don't print it as a subjects
                    {
                      arg_not_in=false;
                      break;
                    }
                    else if (strcmp(index[k].subject, arr[i][j]) != 0)//not in specific array
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
                    strcpy(index[idx].subject, arr[i][j]);
                    idx++;
                }
            }
        }
        fclose(fp);
        size = idx;
    }

    return size;
}

void show_time_table(char arr[][6][MAX])
{
    print_table_format(get_max(arr));
    printf("|time/day |");
    for (int i = 0; i < 6; i++)
    {
        print_date(i, get_max(arr));//print weekday and weekend
    }
    printf("\n");
    print_table_format(get_max(arr));

    for (int i = 0; i < 13; i++)
    {
        printf("| %02d~%02d   |", i + 9, i + 10);//print time

        for (int j = 0; j < 6; j++)
        {
            print_subject(arr[i][j], get_max(arr));//print text read from time_table.txt(class name)
        }
        printf("\n");
        print_table_format(get_max(arr));
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

    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            strcpy(newarr[i][j], arr[i][j]);
        }
    }
ANOTHER:
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

        system("cls");

        start_time -= 9;
        end_time -= 9;
        Day = get_date(day);

        for (int i = start_time; i < end_time; i++)
        {
            strcpy(newarr[i][Day], class_name);
        }
        printf("Type in the day you want to edit(ex. Mon)\n");
        printf("or 'next' for next>>");
        scanf("%s", &day);
    }
    system("cls");

    printf("[Original version]\n");
    show_time_table(arr);

    printf("\n[Edited version]\n");
    show_time_table(newarr);

    printf("Type in 1 if you want to save it\n");
    printf("and type in 2 if you want to use the original one\n");
    printf("and type in 3 if you want to take another attempt(edit)>>");

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
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                fprintf(fp, "%s\n", arr[i][j]);
            }
        }
        printf("original one saved. . .");
    }
    else if (rst == 3)
    {
        system("cls");
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

        char *str = "____";
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
    system("cls");

    if (rst == 1)//edit. get arguments. Make time table out of these arguments, and save then in Time_table_.txt
    {
        out = fopen("Time_table_.txt", "w");
        ftell(out);
        edit_time_table(out, arr);
        fclose(out);
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
