#include<stdio.h>
#include<stdlib.h>

//--------创建双链表结构--------
typedef struct node
{
    struct node* prior;
    int data;
    struct node* next;
}line;

line* initDoubleLink();     //初始化双向循环链表;
void display(line* head);   //打印循环链表;

int main()
{
    line* head=initDoubleLink();
    display(head);
    system("pause");
    return 0;
}

//--------定义初始化链表函数--------
line* initDoubleLink()
{
    line* head=(line*)malloc(sizeof(line));
    head->data=1;
    head->prior=NULL;
    head->next=NULL;
    line* temp=head;
    for(int i=2;i<=5;i++)
    {
        line* body=(line*)malloc(sizeof(line));
        body->data=i;
        body->prior=temp;
        body->next=NULL;
        temp->next=body;
        temp=temp->next;
    }
    temp->next=head;
    return head;
}

//--------定义打印函数--------
void display(line* head)
{
    line* temp=head;
    while(temp->next!=head)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}