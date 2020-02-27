#include<stdio.h>
#include<stdlib.h>

//--------创建链表结构--------
typedef struct Link
{
    int elem;
    struct Link* next;
}link;

//--------声明函数--------

link* initLink();
void display(link* p);

//--------主程序--------
int main()
{
    link* p=initLink();
    display(p);
    system("pause");
    return 0;
}

link* initLink()
{
    link* p=NULL;
    link* temp=(link*)malloc(sizeof(link));
    temp->elem=1;
    temp->next=NULL;
    p=temp;
    for(int i=2;i<=5;i++)
    {
        link* a=(link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
}

void display(link* p)
{
    while(p)
    {
        printf("%d ",p->elem);
        p=p->next;
    }
    printf("\n");
}