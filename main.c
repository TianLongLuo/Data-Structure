#include<stdio.h>
#include<stdlib.h>
#include "include/init.h"
#include "include/add.h"
#include "include/del.h"
int main()
{
    table b=initTable();
    for(int i=0;i<b.size;i++)
    {
        b.head[i]=i+1;
        b.length++;
    }
    displayTable(b);
    b=addTable(b,9,2);
    displayTable(b);
    b=delTable(b,6);
    displayTable(b);
    system("pause");
    return 0;
}