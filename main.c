#include<stdio.h>
#include<stdlib.h>
#define Size 5

//--------顺序表结构--------
typedef struct Table
{
    int* head;
    int length;
    int size;
}table;

//--------函数声明--------
table initTable();        //初始化函数
void displayTable(table t);        //打印数据
table addTable(table t,int elem,int add);        //添加文件
table delTable(table t,int add);     //删除文件
int selectTable(table t,int elem);      //查找文件
table amendTable(table t,int elem,int newelem);         //修改文件

int main()
{
//--------初始化--------
    printf("init\n");
    table b=initTable();
//--------向表中写入数据--------
    for(int i=0;i<b.size;i++)
    {
        b.head[i]=i+1;
    }
    displayTable(b);
//--------添加元素--------
    printf("plus 66 to four\n");
    b=addTable(b,66,4);
    displayTable(b);
//--------查找元素--------
    printf("select 4 position\n");
    printf("%d\n",selectTable(b,4));
//--------修改元素--------
    printf("amend 3 to 9\n");
    b=amendTable(b,3,9);
    displayTable(b);
//--------删除元素--------
    printf("delete position 2\n");
    b=delTable(b,2);
    displayTable(b);

    system("pause");
    return 0;
}
//--------函数定义--------
table initTable()
{
    table t;
    t.head=(int*)malloc(Size*sizeof(int));
    if(!t.head)
    {
        printf("初始化失败");
        exit(0);
    }
    t.length=0;
    t.size=Size;
    return t;
}

void displayTable(table t)
{
    for(int i=0;i<t.length;i++)
    {
        printf("%d ",t.head[i]);
    }
    printf("\n");
}

table addTable(table t,int elem,int add)
{
    if(add>t.size+1||add<1)
    {
        printf("插入位置错误！");
        return t;
    }

    if(t.length==t.size)
    {
        t.head=(int*)realloc(t.head,(Size+1)*sizeof(int));
        if(!t.head)
        {
            printf("内存分配失败");
            return t;
        }
        t.size++;
    }
    for(int i=t.length-1;i>=add-1;i--)
    {
        t.head[i+1]=t.head[i];
    }
    t.head[add-1]=elem;
    t.length++;
    return t;
}

table delTable(table t,int add)
{
    if(add<0||add>t.length)
    {
        printf("删除位置有误！");
        return t;
    }
    for(int i=add-1;i<=t.length-1;i++)
    {
        t.head[i]=t.head[i+1];
    }
    t.length--;
    return t;
}

int selectTable(table t,int elem)
{
    for(int i=0;i<t.length;i++)
    {
        if(t.head[i]==elem)
        return i+1;
    }
    return -1;
}

table amendTable(table t,int elem,int newelem)
{
    int add=selectTable(t,elem);
    t.head[add-1]=newelem;
    return t;
}