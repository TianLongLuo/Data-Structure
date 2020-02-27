#include<stdio.h>
#include<stdlib.h>
#include "include/init.h"

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