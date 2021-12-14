#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#include <stdbool.h>
#define MAX 100
#define SIZE 100
int dday();
int dday2();
void calender();
int suneong_1();
int suneong_2();
void maintitle();
int main_screen();
void 이미지나간수능날짜();
void 이미지나간시험날짜();
void 얼마나남았습니다(int, int, int);
void 데이터저장여부();
void 임의의날짜입력();
void 몇학년도수능();
void 데이터x();
void 데이터o();
void 이상한날짜();
void 달력선택창();
void 달력저장날짜();
void 달력확인날짜();
void 달력년도(int, int);
void 달력년도2();
void 달력달2();
void 달력보고선택();
void 저장할내용();
void 저장되었습니다();
void 저장된내용(char[MAX], int);
void 시험();
void 시험날짜();
void 시험이름();
void 저장된시험(int, int, int, char[MAX]);
void my_grade();
void put_data();
int timesum(int, int);
float GPAsum(int, int, float);
void grade_manage();
void grade_check(int, int);
void grade_main();

#ifndef __FUNC_H__
#define __FUNC_H__

struct list {
	struct list* next;
	char subject[100];
	char things[100];
	int l_page;
}person;
#endif

#ifndef TIME_TABLE_H
#define TIME_TABLE_H

struct Node {
    char subject[100];
}index[100];

#endif
void interface_word(char arr1[], char arr2[]);
void print_subject(char arr[], int max);
void print_table_format(int size);
int get_max(char arr[][6][100]);
void print_date(int, int);
void interface_choice(int choice_num, int choice_length, char arr[][100]);
void interface_one(char arr[]);
void interface_two(char arr[]);
void interface_three(char arr[]);
void interface_zero(char arr[]);
int find_subject();
void show_time_table(char arr[][6][100], int size);
int get_date(char ch[]);
void edit_time_table(FILE* fp, char arr[][6][100]);
void time_table();
int main_screen();
int menu(FILE* fp, int num);
void to_do(FILE* fp);
void choice(FILE* fp);
