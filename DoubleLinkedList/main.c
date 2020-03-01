#include<stdio.h>
#include<stdlib.h>
#define Size 6
//--------创建双向链表结点结构--------
typedef struct line
{
    struct line* prior;
    int data;
    struct line* next;
}line;

//--------函数声明--------
line* initLine(line* head);     //初始化双向链表
void display(line* head);       //打印双向链表数据

//--------主函数--------
int main()
{
    line* head=NULL;
    head=initLine(head);
    display(head);

    system("pause");
    return 0;
}

//--------定义初始化函数--------
line* initLine(line* head)
{
    head=(line*)malloc(sizeof(line));
    head->data=1;
    head->prior=NULL;
    head->next=NULL;
    line* list=head;
    for(int i=2;i<=Size;i++)
    {
        line* body=(line*)malloc(sizeof(line));
        body->data=i;
        body->prior=NULL;
        body->next=NULL;

        body->prior=list;
        list->next=body;
        list=list->next;
    }
    return head;
}

//--------定义打印函数--------
void display(line* head)
{
    line* list=head;
    while(list->next!=NULL)
    {
        printf("%d <-> ",list->data);
        list=list->next;
    }
    printf("%d\n",list->data);
}