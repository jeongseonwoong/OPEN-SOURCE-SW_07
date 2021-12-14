#define _CRT_SECURE_NO_WARNINGS
#include "Time_table.h"

int size = 0;


void interface_word(char arr1[], char arr2[])
{
    if (strcmp(arr2, "") == 0)
    {
        int size = strlen(arr1);
        for (int i = 0; i < (size + 2)/2; i++)
        {
            printf("■");
        }
        printf("\n");
        printf("%s", arr1);
        printf("\n");
        for (int i = 0; i < (size + 2)/2; i++)
        {
            printf("■");
        }
        printf("\n");
    }
    else
    {
        int size1 = strlen(arr1);
        int size2 = strlen(arr2);
        int max = size1;
        bool first_bigger = true;
        if (size2 > size1)
        {
            max = size2;
            first_bigger = false;
        }

        for (int i = 0; i < (max + 2)/2; i++)
        {
            printf("■");
        }
        if (first_bigger == true)
        {
            printf("\n");
            printf("%s", arr1);
            printf("\n");
            printf("\n");
            printf("%s", arr2);
            for (int i = 0; i < (max - size2); i++)
            {
                printf(" ");
            }
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("%s", arr1);
            for (int i = 0; i < max - size2; i++)
            {
                printf(" ");
            }
            printf("\n");
            printf("\n");
            printf("%s", arr2);
            printf("\n");
        }
        for (int i = 0; i < (max + 2)/2; i++)
        {
            printf("■");
        }
        printf("\n");
    }

}


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
            int size = strlen(arr[i][j]);
            if (size > max)max = size;
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


void interface_choice(int choice_num, char arr[][MAX])
{
    for (int i = 0; i < 15; i++)
    {
        printf("■");
    }
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        printf("■");
    }
    printf("선택창");
    for (int i = 0; i < 6; i++)
    {
        printf("■");
    }
    printf("\n");
    for (int i = 0; i < 15; i++)
    {
        printf("■");
    }
    printf("\n");

    switch (choice_num-1)
    {

    case 1:
        interface_one(arr[0]);
        interface_zero(arr[choice_num-1]);
        break;
    case 2:
        interface_one(arr[0]);
        interface_two(arr[1]);
        interface_zero(arr[choice_num-1]);
        break;
    case 3:
        interface_one(arr[0]);
        interface_two(arr[1]);
        interface_three(arr[2]);
        interface_zero(arr[choice_num-1]);
        break;
    }
    for (int i = 0; i < 15; i++)
    {
        printf("■");
    }
    printf("\n");
}


void interface_one(char arr[])
{
    printf("■■■┌──────────────┐■■■■\n");
    printf("■■■│      ■      │■■■■\n");
    printf("■■■│    ■■      │■■■■\n");
    printf("■■■│   ■ ■      │■■■■\n");
    printf("■■■│      ■      │■■■■\n");
    printf("■■■│      ■      │■■■■\n");
    printf("■■■│      ■      │■■■■\n");
    printf("■■■│   ■■■■   │■■■■\n");
    if (strlen(arr) < 14)
    {
        printf("■■■│%s", arr);
        int size = strlen(arr);
        for (int i = 0; i < 14 - size; i++)
        {
            printf(" ");
        }
        printf("│■■■■\n");
        printf("■■■│              │■■■■\n");
    }
    else
    {
        printf("■■■│");
        for (int i = 0; i < 14; i++)
        {
            printf("%c", arr[i]);
        }
        printf("│■■■■\n");
        printf("■■■│");
        int end = 28;
        for (int i = 14; i<28; i++)
        {
            if (arr[i] == '\0')
            {
                printf(" ");
                end = i;
            }
            else if(end>i)
            {
                printf("%c", arr[i]);
            }
            else
            {
                printf(" ");
            }

        }
        printf("│■■■■\n");
    }
    printf("■■■└──────────────┘■■■■\n");

}


void interface_two(char arr[])
{
    printf("■■■┌──────────────┐■■■■\n");
    printf("■■■│  ■■■■    │■■■■\n");
    printf("■■■│ ■      ■   │■■■■\n");
    printf("■■■│ ■      ■   │■■■■\n");
    printf("■■■│       ■     │■■■■\n");
    printf("■■■│     ■       │■■■■\n");
    printf("■■■│   ■         │■■■■\n");
    printf("■■■│  ■■■■■  │■■■■\n");
    if (strlen(arr) < 14)
    {
        printf("■■■│%s", arr);
        int size = strlen(arr);
        for (int i = 0; i < 14 - size; i++)
        {
            printf(" ");
        }
        printf("│■■■■\n");
        printf("■■■│              │■■■■\n");
    }
    else
    {
        printf("■■■│");
        for (int i = 0; i < 14; i++)
        {
            printf("%c", arr[i]);
        }
        printf("│■■■■\n");
        printf("■■■│");
        int end = 28;
        for (int i = 14; i < 28; i++)
        {
            if (arr[i] == '\0')
            {
                printf(" ");
                end = i;
            }
            else if (end > i)
            {
                printf("%c", arr[i]);
            }
            else
            {
                printf(" ");
            }

        }
        printf("│■■■■\n");
    }

    printf("■■■└──────────────┘■■■■\n");
}


void interface_three(char arr[])
{

    printf("■■■┌──────────────┐■■■■\n");
    printf("■■■│   ■■■■   │■■■■\n");
    printf("■■■│  ■      ■  │■■■■\n");
    printf("■■■│        ■    │■■■■\n");
    printf("■■■│    ■■■    │■■■■\n");
    printf("■■■│         ■   │■■■■\n");
    printf("■■■│  ■      ■  │■■■■\n");
    printf("■■■│   ■■■■   │■■■■\n");    if (strlen(arr) < 14)
    {
        printf("■■■│%s", arr);
        int size = strlen(arr);
        for (int i = 0; i < 14 - size; i++)
        {
            printf(" ");
        }
        printf("│■■■■\n");
        printf("■■■│              │■■■■\n");
    }
    else
    {
        printf("■■■│");
        for (int i = 0; i < 14; i++)
        {
            printf("%c", arr[i]);
        }
        printf("│■■■■\n");
        printf("■■■│");
        int end = 28;
        for (int i = 14; i < 28; i++)
        {
            if (arr[i] == '\0')
            {
                printf(" ");
                end = i;
            }
            else if (end > i)
            {
                printf("%c", arr[i]);
            }
            else
            {
                printf(" ");
            }

        }
        printf("│■■■■\n");
    }

    printf("■■■└──────────────┘■■■■\n");

}


void interface_zero(char arr[])
{

    printf("■■■┌──────────────┐■■■■\n");
    printf("■■■│     ■■     │■■■■\n");
    printf("■■■│   ■    ■   │■■■■\n");
    printf("■■■│  ■      ■  │■■■■\n");
    printf("■■■│  ■      ■  │■■■■\n");
    printf("■■■│  ■      ■  │■■■■\n");
    printf("■■■│   ■    ■   │■■■■\n");
    printf("■■■│     ■■     │■■■■\n");
    int size = strlen(arr);
    if (size < 14)
    {
        printf("■■■│%s", arr);
        for (int i = 0; i < 14 - size; i++)
        {
            printf(" ");
        }
        printf("│■■■■\n");
        printf("■■■│              │■■■■\n");
    }
    else
    {
        printf("■■■│");
        for (int i = 0; i < 14; i++)
        {
            printf("%c", arr[i]);
        }
        printf("│■■■■\n");
        printf("■■■│");
        int end = 28;
        for (int i = 14; i < 28; i++)
        {
            if (arr[i] == '\0')
            {
                printf(" ");
                end = i;
            }
            else if (end > i)
            {
                printf("%c", arr[i]);
            }
            else
            {
                printf(" ");
            }

        }
        printf("│■■■■\n");
    }

    printf("■■■└──────────────┘■■■■\n");
}


int find_subject()
{
    FILE* fp;
    char arr[13][6][MAX] = { 0, };
    int idx = 0;
    fp = fopen("Time_table_.txt", "rb");
    if (fp == NULL)
    {
        interface_word("Wrong", "");

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
                    if (strcmp(arr[i][j], "____") == 0)//if no subject, don't print it as a subject
                    {
                        arg_not_in = false;
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


void show_time_table(char arr[][6][MAX], int size)
{
    size = (size + 2) * 3 + 5;
    for (int i = 0; i < size / 2 ; i++)
    {
        printf("■");
    }
    printf("시간표");
    for (int i = 0; i < size / 2; i++)
    {
        printf("■");
    }
    printf("\n");
    int arr_size = get_max(arr);
    print_table_format(arr_size);
    printf("|time/day |");
    for (int i = 0; i < 6; i++)
    {
        print_date(i, arr_size);//print weekday and weekend
    }
    printf("\n");
    print_table_format(arr_size);

    for (int i = 0; i < 13; i++)
    {
        printf("| %02d~%02d   |", i + 9, i + 10);//print time

        for (int j = 0; j < 6; j++)
        {
            print_subject(arr[i][j], arr_size);//print text read from time_table.txt(class name)
        }
        printf("\n");
        print_table_format(arr_size);
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
        interface_word("Error", "");
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
    interface_word("Type in the day you want to edit(ex. Mon)", "or 'next' for next");

    printf(">>");
    scanf("%s", &day);
    while (strcmp(day, "next") != 0)
    {
        printf("\n");
        interface_word("Starting time", "");

        printf(">>");
        scanf("%d", &start_time);

        printf("\n");
        interface_word("Ending time", "");

        printf(">>");
        scanf("%d", &end_time);

        printf("\n");
        interface_word("Class name", "");

        printf(">>");
        scanf("%s", &class_name);

        system("cls");

        start_time -= 9;
        end_time -= 9;
        Day = get_date(day);

        for (int i = start_time; i < end_time; i++)
        {
            strcpy(newarr[i][Day], class_name);
        }
        interface_word("Type in the day you want to edit(ex. Mon)", "or 'next' for next");

        printf(">>");
        scanf("%s", &day);
    }
    system("cls");

    interface_word("[Original version]", "");

    printf("\n");
    show_time_table(arr, get_max(arr));

    interface_word("[Edited version]", "");

    printf("\n");
    show_time_table(newarr, get_max(newarr));
    printf("\n\n");
    interface_word("넘어가려면 엔터. . .", "");

    rewind(stdin);
    char c;
    while ((c = getchar()) != '\n' && c != EOF);

    system("cls");

    char interfaces[4][MAX];
    strcpy(interfaces[0], " Save the new one");
    strcpy(interfaces[1], " Use the original one");
    strcpy(interfaces[2], " Additional edit");
    strcpy(interfaces[3], " End the program");
    interface_choice(4, interfaces);
    printf("[선택창]>> ");

    int rst = 0;
    scanf("%d", &rst);
    if (rst == 1)
    {
        system("cls");

        interface_word("saving time table.", "");
        Sleep(TIME);
        system("cls");
        interface_word("saving time table. .", "");
        Sleep(TIME);
        system("cls");
        interface_word("saving time table. . .", "");
        Sleep(TIME);
        system("cls");
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                fprintf(fp, "%s\n", newarr[i][j]);
            }
        }
        interface_word("edited one saved. . !", "(넘어가려면 엔터. . .)");

        rewind(stdin);
        char c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    else if (rst == 2)
    {
        system("cls");

        interface_word("saving time table.", "");
        Sleep(TIME);
        system("cls");
        interface_word("saving time table. .", "");
        Sleep(TIME);
        system("cls");
        interface_word("saving time table. . .", "");
        Sleep(TIME);
        system("cls");
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                fprintf(fp, "%s\n", arr[i][j]);
            }
        }
        interface_word("original one saved. . !", "(넘어가려면 엔터. . .)");

        rewind(stdin);
        char c;
        while ((c = getchar()) != '\n' && c != EOF);

    }
    else if (rst == 3)
    {
        system("cls");
        goto ANOTHER;
    }
    else
    {
        system("cls");


        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                fprintf(fp, "%s\n", arr[i][j]);
            }
        }

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
        show_time_table(arr, get_max(arr));
        interface_word("넘어가려면 엔터. . .", "");

        rewind(stdin);
        char c;
        while ((c = getchar()) != '\n' && c != EOF);

        system("cls");

        char interfaces[4][MAX];
        strcpy(interfaces[0], " Edit the original one");
        strcpy(interfaces[1], " Use the original one");
        strcpy(interfaces[2], " End the program");
        interface_choice(3, interfaces);

        fclose(in);

    }
    FILE* out;

    printf("[선택창]>> ");

    int rst = 0;
    scanf("%d", &rst);
    system("cls");

    if (rst == 1)//edit. get arguments. Make time table out of these arguments, and save then in Time_table_.txt
    {
        out = fopen("Time_table_.txt", "w");

        edit_time_table(out, arr);
        fclose(out);

        system("cls");

        interface_word("Going to main.", "");
        Sleep(TIME);
        system("cls");
        interface_word("Going to main. .", "");
        Sleep(TIME);
        system("cls");
        interface_word("Going to main. . .", "");
        Sleep(TIME);
        system("cls");
    }
    else if (rst == 2)//use the original
    {
        system("cls");

        interface_word("saving time table.", "");
        Sleep(TIME);
        system("cls");
        interface_word("saving time table. .", "");
        Sleep(TIME);
        system("cls");
        interface_word("saving time table. . .", "");
        Sleep(TIME);
        system("cls");

        interface_word("time table saved. . !", "(넘어가려면 엔터. . .)");

        rewind(stdin);
        char c;
        while ((c = getchar()) != '\n' && c != EOF);

        system("cls");

        interface_word("Going to main.", "");
        Sleep(TIME);
        system("cls");
        interface_word("Going to main. .", "");
        Sleep(TIME);
        system("cls");
        interface_word("Going to main. . .", "");
        Sleep(TIME);
        system("cls");

    }
    else if (rst == 0)//end the program
    {
        system("cls");

        interface_word("Going to main.", "");
        Sleep(TIME);
        system("cls");
        interface_word("Going to main. .", "");
        Sleep(TIME);
        system("cls");
        interface_word("Going to main. . .", "");
        Sleep(TIME);
        system("cls");

    }
}
