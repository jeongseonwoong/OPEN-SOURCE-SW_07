#include <stdio.h>
#define MAX 30
struct {
    char arr[14][7];//9시 수업부터 21시 수업까지, 월요일부터 토요일까지.
}column;
struct {

};
int main()
{
    FILE *in;
    int rst=fopen_s(&in, "schedule.txt", "r");
    if(rst==0)//파일이 존재하는 경우.
    {
        char arr[14][7]; 
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                fscanf_s(in, "%s", &arr[j][i]);
            }
        }
    }
    else
    {

    }

}
