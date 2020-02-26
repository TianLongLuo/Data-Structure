#include<stdio.h>
#include<stdlib.h>
#define Size 5

typedef struct Table
{
    int* head;
    int length;
    int size;
}table;

table initTable();
void displayTable(table t);

int main()
{
    table b=initTable();
    for(int i=0;i<b.size;i++)
    {
        b.head[i]=i+1;
        b.length++;
    }
    displayTable(b);
    system("pause");
    return 0;
}

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