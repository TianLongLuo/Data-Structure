#include<stdio.h>
#include"include/init.h"
#include"include/select.h"
#include"include/amend.h"

table amendTable(table t,int elem,int newelem)
{
    int add=selectTable(t,elem);
    t.head[add-1]=newelem;
    return t;
}