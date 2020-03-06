#include<stdio.h>
#include<stdlib.h>

//--------创建链式结构--------
typedef struct LinkQueue
{
    int data;
    struct LinkQueue* next;
}queue;

//--------函数声明--------
queue* enqueue(queue* rear,int data);     //入队
void dequeue(queue* front,queue* rear);      //出队

int main()
{
    //初始化头节点
    queue* p=(queue*)malloc(sizeof(queue));
    p->next=NULL;
    queue* front=p;
    queue* rear=p;
    //入队
    for(int i=1;i<=5;i++)
    {
        rear=enqueue(rear,i);
    }
    //出队
    for(int i=1;i<=5;i++)
    {
        dequeue(front,rear);
    }
    system("pause");
    return 0;
}

//--------定义入队函数--------
queue* enqueue(queue* rear,int data)
{
    queue* temp=(queue*)malloc(sizeof(queue));
    temp->data=data;
    temp->next=NULL;
    rear->next=temp;
    rear=rear->next;
    return rear;
}

//--------定义出队函数--------
void dequeue(queue* front,queue* rear)
{
    if(front->next==NULL)
    {
        printf("queue is empty!\n");
        return ;
    }
    queue* temp=front->next;
    front->next=temp->next;
    printf("Dequeue: %d\n",temp->data);
    if(rear==temp)
    {
        rear=front;
    }
    free(temp);
}