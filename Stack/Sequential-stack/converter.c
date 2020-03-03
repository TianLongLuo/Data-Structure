#include<stdio.h>
#include<string.h>
#include<math.h>

//--------声明全局变量--------
int top=-1;
//--------声明所需函数--------
void push(char* data,char elem);        //入栈
void pop(char* data);       //出栈
int Decimal(char* data,int system);     //转换为十进制

//--------主函数--------
int main()
{
    char data[100];
    int system;
    printf("请输入转换前的进制：");
    scanf("%d",&system);
    printf("请输入转换前的数据:");
    scanf("%s",data);
    int dec=Decimal(data,system);
    printf("请输入转换后的进制：");
    int newsystem;
    scanf("%d",&newsystem);
    while(dec/newsystem)
    {
        push(data,dec%newsystem);
        dec/=newsystem;
    }
    push(data,dec%newsystem);
    printf("转换后的数据为：");
    while(top!=-1)
    {
        pop(data);
    }
    getchar();
    getchar();
    return 0;
}

//--------定义入栈函数--------
void push(char* data,char elem)
{
    data[++top]=elem;
}

//--------定义出栈函数--------
void pop(char* data)
{
    if(top==-1)
    {
        return ;
    }
    if(data[top]>=10)
    {
        printf("%c",data[top]+55);
    }else{
        printf("%d",data[top]);
    }
    top--;
}

//--------定义十进制转换函数--------
int Decimal(char* data,int system)
{
    int k=(int)strlen(data)-1;
    int dec=0;
    for(int i=k;i>=0;i--)
    {
        int temp;
        if(data[i]>=48&&data[i]<=57)
        {
            temp=data[i]-48;
        }else{
            temp=data[i]-55;
        }
        dec+=temp*pow(system,k-i);
    }
    return dec;
}