#include<stdio.h>
#include<stdlib.h>
#include "include/init.h"
#include "include/add.h"
#include "include/del.h"
#include "include/select.h"
#include "include/amend.h"
int main()
{
//--------初始化--------
    printf("init\n");
    table b=initTable();
//--------向表中写入数据--------
    for(int i=0;i<b.size;i++)
    {
        b.head[i]=i+1;
        b.length++;
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