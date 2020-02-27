#include<stdio.h>
#include<stdlib.h>
#include "include/init.h"
#include "include/add.h"

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