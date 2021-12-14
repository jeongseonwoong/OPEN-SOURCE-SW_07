#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#define MAX 100
#define TIME 1000

#ifndef TIME_TABLE_H
#define TIME_TABLE_H

struct Node {
    char subject[MAX];
}index[MAX];

#endif

void interface_word(char, char);

void print_subject(char, int);

void print_table_format(int);

int get_max(char arr[][6][MAX]);

void print_date(int, int);

void interface_choice(int, char arr[][MAX]);

void interface_one(char arr[]);

void interface_two(char arr[]);

void interface_three(char arr[]);

void interface_zero(char arr[]);

int find_subject();

void show_time_table(char arr[][6][MAX], int);

int get_date(char ch[]);

void edit_time_table(FILE*, char arr[][6][MAX]);

void time_table();
