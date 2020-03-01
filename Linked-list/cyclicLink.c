#include<stdio.h>
#include<stdlib.h>

//--------定义约瑟夫环的结点结构--------
typedef struct node
{
    int number;
    struct node* next;
}person;

person* initline(int n);     //初始化循环链表
void findAndKillM(person* head,int k,int m);        //找到从k开始数到m的人并删除
void display(person* head);     //打印链表

int main()
{
    //初始化循环链表
    person* head=initline(5);
    display(head);
    findAndKillM(head,3,7);
    system("pause");
    return 0;
}

//--------定义初始化链表函数--------
person* initline(int n)
{
    person* head=(person*)malloc(sizeof(person));
    head->number=1;
    head->next=NULL;
    person* temp=head;
    for(int i=2;i<=n;i++)
    {
        person* body=(person*)malloc(sizeof(person));
        body->number=i;
        body->next=NULL;
        temp->next=body;
        temp=temp->next;
    }
    temp->next=head;
    return head;
}

//--------找到从k开始数到m的人并删除--------
void findAndKillM(person* head,int k,int m)
{
    person* temp=head;
    person* tail=temp;
    while(temp->number!=k)
    {
        tail=temp;
        temp=temp->next;
    }
    while(temp->next!=temp)
    {
        for(int i=1;i<m;i++)
        {
            tail=temp;
            temp=temp->next;
        }
        tail->next=temp->next;
        printf("Dequeue: %d\n",temp->number);
        free(temp);
        temp=tail->next;
    }
    printf("Last person: %d\n",temp->number);
    free(temp);
}

//--------定义打印函数--------
void display(person* head)
{
    person* temp=head;
    while(temp->next!=head)
    {
        printf("%d ",temp->number);
        temp=temp->next;
    }
    printf("%d\n",temp->number);
}