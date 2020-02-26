#include<stdio.h>
#include "include/init.h"
#include "include/del.h"

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