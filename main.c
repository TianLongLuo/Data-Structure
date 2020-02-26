#include<stdio.h>
#include<stdlib.h>
#include "include/init.h"
#include "include/add.h"

int main()
{
    table b=initTable();
    for(int i=0;i<b.size;i++)
    {
        b.head[i]=i+1;
        b.length++;
    }
    displayTable(b);
    b=addTable(b,3,1);
    displayTable(b);
    system("pause");
    return 0;
}