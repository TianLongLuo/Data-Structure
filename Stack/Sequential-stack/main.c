#include<stdio.h>
#include<stdlib.h>

//--------函数声明--------
int push(int* a,int top,int elem);      //入栈函数
int pop(int* a,int top);        //出栈函数

//--------主函数--------
int main()
{
    int a[100];
    int top=-1;
    for(int i=4;i<=9;i++)
    {
        top=push(a,top,i);
    }

    for(int i=4;i<=9;i++)
    {
        top=pop(a,top);
    }
    

    system("pause");
    return 0;
}

//--------定义入栈函数--------
int push(int* a,int top,int elem)
{
    a[++top]=elem;
    return top;
}

//--------定义出栈函数--------
int pop(int* a,int top)
{
    if(-1==top)
    {
        printf("Empty stack!");
        return -1;
    }
    printf("pop up: %d\n",a[top]);
    return --top;
}