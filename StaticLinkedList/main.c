#include<stdio.h>
#include<stdlib.h>
#define maxSize 10

//--------创建静态链表结点结构--------
typedef struct
{
    int elem;
    int cur;
}component;

//--------函数声明--------
void reserveArr(component* array);     //生成并连接备用链表
int mallocArr(component* array);      //分配一个数据节点
int initArr(component* array);      //初始化链表
void insertArr(component* array,int body,int add,int elem);     //增加结点
void freeArr(component* array,int k);       //回收空间
void delPositionArr(component* array,int body,int add);     //根据位置删除结点
void delDataArr(component* array,int body,int elem);        //根据数据删除结点
int selectArrElem(component* array,int body,int elem);     //根据数据查找结点下标位置
void amendArrElem(component* array,int body,int elem,int newelem);      //修改结点数据
void display(component* array,int body);  //打印数据链表
void displayAll(component* array);      //打印整条链表

int main()
{
    //初始化静态链表
    component array[maxSize];
    int body=initArr(array);
    display(array,body);
    //添加66到第4个位置
    insertArr(array,body,4,66);
    display(array,body);
    //删除数据为1的结点
    delDataArr(array,body,1);
    display(array,body);
    //删除第2个位置的结点
    delPositionArr(array,body,2);
    display(array,body);
    //查找元素66所在的下标位置
    printf("%d\n",selectArrElem(array,body,66));
    //修改元素66为99
    amendArrElem(array,body,66,99);
    display(array,body);
    system("pause");
    return 0;
}

//--------用于连接静态链表--------
void reserveArr(component* array)
{
    for(int i=0;i<maxSize;i++)
    {
        array[i].elem=-1;
        array[i].cur=i+1;
    }
    array[maxSize-1].cur=0;
}
//--------用于提取备用链表空间--------
int mallocArr(component* array)
{
    int i=array[0].cur;
    if(array[0].cur)
    {
        array[0].cur=array[i].cur;
    }
    return i;
}
//--------初始化静态链表--------
int initArr(component* array)
{
    reserveArr(array);
    int body=mallocArr(array);
    int tempBody=body;
    for(int i=1;i<6;i++)
    {
        int a=mallocArr(array);
        array[a].elem=i;
        array[a].cur=0;
        array[tempBody].cur=a;
        tempBody=a;
    }
    return body;
}
//--------用于插入新的结点--------
void insertArr(component* array,int body,int add,int elem)
{
    int tempBody=body;
    for(int i=1;i<add;i++)
    {
        tempBody=array[tempBody].cur;
    }
    int new=mallocArr(array);
    array[new].elem=elem;
    array[new].cur=array[tempBody].cur;
    array[tempBody].cur=new;
}
//--------用于回收空结点到备用链表--------
void freeArr(component* array,int k)
{
    array[k].cur=array[0].cur;
    array[0].cur=k;
}
//--------根据提供的位置删除结点--------
void delPositionArr(component* array,int body,int add)
{
    int tempBody=body;
    for(int i=1;i<add;i++)
    {
        tempBody=array[tempBody].cur;
        if(0==tempBody)
        {
            printf("Error Position!");
            return;
        }
    }
    int del=array[tempBody].cur;
    array[tempBody].cur=array[del].cur;
    freeArr(array,del);
}
//--------根据提供的数据删除结点--------
void delDataArr(component* array,int body,int elem)
{
    int tempBody=body;
    while(elem!=array[tempBody].elem)
    {
        tempBody=array[tempBody].cur;
        if(0==tempBody)
        {
            printf("Error Position!");
            return;
        }
    }
    int del=tempBody;
    tempBody=body;
    while(del!=array[tempBody].cur)
    {
        tempBody=array[tempBody].cur;
    }
    array[tempBody].cur=array[del].cur;
    freeArr(array,del);
}
//--------根据数据查找结点位置下标--------
int selectArrElem(component* array,int body,int elem)
{
    int tempBody=body;
    while(tempBody)
    {
        if(elem==array[tempBody].elem)
        {
            return tempBody;
        }
        tempBody=array[tempBody].cur;
    }
    return -1;
}
//--------根据数据查找结点并修改结点元素--------
void amendArrElem(component* array,int body,int elem,int newelem)
{
    int add=selectArrElem(array,body,elem);
    if(-1==add)
    {
        printf("Nope Elem!");
        return;
    }
    array[add].elem=newelem;
}
//--------打印静态链表中的数据表--------
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
//--------打印整条静态链表--------
void displayAll(component* array)
{
    for(int i=0;i<maxSize;i++)
    {
        printf("%d--%d  ",array[i].elem,array[i].cur);
    }
    printf("\n");
}