#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define ParkSize 6
#define RoadSize 6
#define OutSize 6

//--------全局变量--------
int top_park=-1;
int top_road=-1;
int front=0,rear=0;
//--------函数声明--------
void map();        //数据面板

void push_park(int* p,int car);        //停车场入栈
int pop_park(int* p);     //停车场出栈

void push_road(int* r,int car);       //马路入栈
int pop_road(int* p);        //马路出栈

void enqueue(int* o,int car);     //外道入队
int dequeue(int* o);     //外道出队

void play();        //系统运行
//--------主函数--------
int main()
{
    play();
    system("pause");
    return 0;
}

//--------数据面板--------
void map()
{
    system("CLS");
    printf("Park: %d\n",top_park+1);
    printf("Out : %d\n",((rear-front+5)%5));
    printf("road: %d\n",top_road+1);
    printf("\n\n\n\n\n");
}
//--------车辆进入停车场--------
void push_park(int* p,int car)
{
    if(top_park==ParkSize-1)
    {
        printf("Park is full!\n");
        exit(0);
    }
    p[++top_park]=car;
}
//--------停车场车辆撤出--------
int pop_park(int* p)
{
    if(top_park==-1)
    {
        printf("It empty!\n");
        exit(0);
    }
    int temp=p[top_park];
    top_park--;
    return temp;
}

//--------车辆进入马路--------
void push_road(int* r,int car)
{
    if(top_road==RoadSize-1)
    {
        printf("Park is full!\n");
        exit(0);
    }
    r[++top_road]=car;
}
//--------车辆撤出马路--------
int pop_road(int* r)
{
    if(top_road==-1)
    {
        printf("It empty!\n");
        exit(0);
    }
    int temp=r[top_road];
    top_road--;
    return temp;
}

//--------车辆暂停过道--------
void enqueue(int* o,int car)
{
    if((rear+1)%OutSize==front)
    {
        printf("Space is full!\n");
        exit(0);
    }
    o[rear%OutSize]=car;
    rear++;
}
//--------车辆离开过道--------
int dequeue(int* o)
{
    if(front==rear%OutSize)
    {
        printf("out is empty!\n");
        exit(0);
    }
    int temp=o[front];
    front=(front+1)%OutSize;
    return temp;
}

//--------运行系统--------
void play()
{
    int park[ParkSize];
    int road[RoadSize];
    int out[OutSize];
    while(1)
    {
        map();
        printf("1.new car   2.delete car    3.break\n");
        char c=getch();
        if(c=='1')
        {
            printf("enter new car name:");
            int carname;
            scanf("%d",&carname);
            if(top_park==ParkSize-1)
            {
                enqueue(out,carname);
            }else{
                push_park(park,carname);
            }
        }else{
            printf("delete car number:");
            int delcarname;
            scanf("%d",&delcarname);
            while(park[top_park]!=delcarname)
            {
                push_road(road,pop_park(park));
                Sleep(200);
                map();
            }
            pop_park(park);
            while(top_road!=-1)
            {
                push_park(park,pop_road(road));
                Sleep(200);
                map();
            }
            if(front!=rear%OutSize)
            {
                push_park(park,dequeue(out));
            }
        }
    }
}