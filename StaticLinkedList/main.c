#include<stdio.h>
#include<stdlib.h>
#define maxSize 6

//--------创建静态链表结点结构--------
typedef struct
{
    int elem;
    int cur;
}component;

//--------函数声明--------
void reserveArr(component* array);     //生成并连接备用链表
int mallocArr(component* array);      //分配一个数据节点
int initArr();      //初始化链表
void display(component* array,int body);  //打印数据链表
void displayAll(component* array);      //打印整条链表

int main()
{
    component array[maxSize];
    int body=initArr(array);
    display(array,body);
    displayAll(array);
    system("pause");
}

//--------函数定义--------
void reserveArr(component* array)
{
    for(int i=0;i<maxSize;i++)
    {
        array[i].elem=-1;
        array[i].cur=i+1;
    }
    array[maxSize-1].cur=0;
}

int mallocArr(component* array)
{
    int i=array[0].cur;
    if(array[0].cur)
    {
        array[0].cur=array[i].cur;
    }
    return i;
}

int initArr(component* array)
{
    reserveArr(array);
    int body=mallocArr(array);
    int tempBody=body;
    for(int i=1;i<4;i++)
    {
        int a=mallocArr(array);
        array[a].elem=i;
        array[a].cur=0;
        array[tempBody].cur=a;
        tempBody=a;
    }
    return body;
}

void display(component* array,int body)
{
    int tempBody=body;
    tempBody=array[tempBody].cur;
    while(array[tempBody].cur)
    {
        printf("%d--%d  ",array[tempBody].elem,array[tempBody].cur);
        tempBody=array[tempBody].cur;
    }   
    printf("%d--%d  \n",array[tempBody].elem,array[tempBody].cur);
}

void displayAll(component* array)
{
    for(int i=0;i<maxSize;i++)
    {
        printf("%d--%d  ",array[i].elem,array[i].cur);
    }
    printf("\n");
}