//--------游戏规则--------
//n 个参加者排成一个环，每次由主持向左轮手枪中装一颗子弹，并
//随机转动关上转轮，游戏从第一个人开始，轮流拿枪；中枪者退出
//赌桌，退出者的下一个人作为第一人开始下一轮游戏。直至最后剩
//余一个人，即为胜者。要求：模拟轮盘赌的游戏规则，找到游戏的最终胜者。
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//--------定义循环链表--------
typedef struct node
{
    int number;
    struct node* next;
}line;

line* initline(int size);       //初始化循环表
void playGame(line* head);      //开始死亡游戏

int main()
{
    line* head=initline(5);
    playGame(head);
    system("pause");
    return 0;
}

line* initline(int size)
{
    line* head=(line*)malloc(sizeof(line));
    head->number=1;
    head->next=NULL;
    line* temp=head;
    for(int i=2;i<=size;i++)
    {
        line* body=(line*)malloc(sizeof(line));
        body->number=i;
        body->next=NULL;
        temp->next=body;
        temp=temp->next;
    }
    temp->next=head;
    return head;
}

void playGame(line* head)
{
    line* temp=head;
    line* tail=temp;
    while(tail->next!=temp)
    {
        tail=tail->next;
    }
    srand((unsigned)time(0));
    while(temp->next!=temp)
    {
        int shootNum=rand()%6+1;
        printf("The %d trigger will die !\n",shootNum);
        for(int i=1;i<shootNum;i++)
        {
            tail=temp;
            temp=temp->next;
        }
        printf("Out: %d\n",temp->number);
        tail->next=temp->next;
        free(temp);
        temp=tail->next;
    }
    printf("Winner: %d\n",temp->number);
    free(temp);
}