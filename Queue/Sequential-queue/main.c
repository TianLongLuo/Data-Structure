#include<stdio.h>
#include<stdlib.h>
#define max 6
//--------声明函数--------
int enqueue(int* a,int rear,int front,int data);      //入队
int dequeue(int* a,int front,int rear);     //出队

int main()
{
    int a[100];
    int rear,front;
    rear=front=0;
    rear=enqueue(a,rear,front,1);
    rear=enqueue(a,rear,front,2);
    rear=enqueue(a,rear,front,3);
    rear=enqueue(a,rear,front,4);
    rear=enqueue(a,rear,front,5);
    rear=enqueue(a,rear,front,6);
    front=dequeue(a,front,rear);
    front=dequeue(a,front,rear);
    front=dequeue(a,front,rear);
    front=dequeue(a,front,rear);
    front=dequeue(a,front,rear);
    front=dequeue(a,front,rear);
    system("pause");
    return 0;
}

//--------入队函数--------
int enqueue(int* a,int rear,int front,int data)
{
    if((rear+1)%max==front)
    {
        printf("The queue is full !\n");
        return rear;
    }
    a[rear%max]=data;
    rear++;
    return rear;
}

//--------出队函数--------
int dequeue(int* a,int front,int rear)
{
    if(front%max==rear%max)
    {
        printf("The queue is empty !\n");
        return front;
    }
    printf("Dequeue: %d\n",a[front]);
    front=(front+1)%max;
    return front;
}