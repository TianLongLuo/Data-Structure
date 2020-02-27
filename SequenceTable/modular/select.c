#include<stdio.h>
#include "include/init.h"
#include "include/select.h"
int selectTable(table t,int elem)
{
    for(int i=0;i<t.length;i++)
    {
        if(t.head[i]==elem)
        return i+1;
    }
    return -1;
}