#include<stdio.h>
#define MAX 100
int arrangenum()
{
  int n[MAX]={1};
  while(n[0]>0)
  {
    int i=0,j=0,,times=0,ptr;
    float ave,result=0;
    printf("Enter integers>>");
    while(scanf_s("%d",&n[i])>0)
    {
      if(n[i]<0)
      {
        break;
      }
      result=result+n[i];
      i++;
      times++;
    }
    			if (n[i] < 0)
			{
				break;
			}
    ave=result/times;
    for(i=0;i<times-1;i++)
    {
      for(j=i+1;j<times;j++)
      {
          if(n[i]>n[j])
          {
            ptr=n[i];
            n[i]=n[j];
            n[j]=ptr;
          }  
      }
    }
    for(i=0;i<times;i++)
    {
        printf("%d ",n[i]);
    }
    printf("\t The average is %-6.2f\n",ave);
 }
 return 0;
}

int main()
{
  arrangenum(); //음수가 나올때까지 숫자를 입력받은 후, 입력받은 숫자를 나열하고 평균을 계산한다. 처음으로 입력받은 숫자가 음수이면 종료.
}  