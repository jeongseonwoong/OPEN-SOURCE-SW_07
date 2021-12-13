#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#ifndef TIME_TABLE_H
#define TIME_TABLE_H

struct Node {
  char subject[100];
}index[100];

#endif

void print_subject(char arr[], int max);
void print_table_format(int size);
int get_max(char arr[][6][100]);
void print_date(int, int);
int find_subject();
void show_time_table(char arr[][6][100]);
int get_date(char ch[]);
void edit_time_table(FILE *fp, char arr[][6][100]);
void time_table();
