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
line* insertLine(line* head,int data,int add);      //插入结点函数
line* delDataLine(line* head,int data);     //根据数据删除结点函数
line* delPositionLine(line* head,int add);      //根据位置删除结点函数
int selectLine(line* head,int data);        //返回元素所在结点位置
line* amendLine(line* head,int data,int newData);       //修改旧元素为新元素
void display(line* head);       //打印双向链表数据


//--------主函数--------
int main()
{
    //初始化双链表
    line* head=NULL;
    head=initLine(head);
    display(head);
    //插入7到第3个位置
    head=insertLine(head,7,3);
    display(head);
    //删除链表中数据为2的结点
    head=delDataLine(head,2);
    display(head);
    //删除位置1的结点
    head=delPositionLine(head,1);
    display(head);
    //查找数据7所在位置
    printf("%d\n",selectLine(head,7));
    //修改元素7为99,5为66
    amendLine(head,7,99);
    amendLine(head,5,66);
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

//--------定义插入结点函数--------
line* insertLine(line* head,int data,int add)
{
    line* body=(line*)malloc(sizeof(line));
    body->data=data;
    body->prior=NULL;
    body->next=NULL;
    if(1==add)
    {
        body->next=head;
        head->prior=body;
        head=body;
    }else{
        line* temp=head;
        for(int i=1;i<add-1;i++)
        {
            temp=temp->next;
        }
        if(NULL==temp->next)
        {
            temp->next=body;
            body->prior=temp;
        }else{
            body->next=temp->next;
            temp->next->prior=body;
            temp->next=body;
            body->prior=temp;
        }
    }
    return head;
}

//--------定义根据数据删除结点函数--------
line* delDataLine(line* head,int data)
{
    line* temp=head;
    while(temp)
    {
        if(data==temp->data)
        {
            if(NULL==temp->prior)
            {
                head=temp->next;
                free(temp);

            }else{
                if(NULL==temp->next)
                {
                    temp->prior->next=NULL;
                    free(temp);
                }else{
                    temp->prior->next=temp->next;
                    temp->next->prior=temp->prior;
                    free(temp);
                }
            }
            return head;
        }
        temp=temp->next;
    }
    printf("Error Position!\n");
    return head;
}

//--------定义根据位置删除结点--------
line* delPositionLine(line* head,int add)
{
    line* temp=head;
    for(int i=1;i<add;i++)
    {
        temp=temp->next;
    }
    if(NULL==temp->prior)
    {
        head=temp->next;
        free(temp);
    }else{
        if(NULL==temp->next)
        {
            temp->prior->next=NULL;
            free(temp);
        }else{
            temp->prior->next=temp->next;
            temp->next->prior=temp->prior;
            free(temp);
        }
    }
    return head;
}

//--------查找元素所在结点的位置--------
int selectLine(line* head,int data)
{
    line* temp=head;
    int i=1;
    while(temp)
    {
        if(data==temp->data)
        {
            return i;
        }
        temp=temp->next;
        i++;
    }
    return -1;
}

//--------修改目标元素为新元素--------
line* amendLine(line* head,int data,int newData)
{
    line* temp=head;
    int add=selectLine(temp,data);
    if(add==-1)
    {
        printf("Nope data!");
        return head;
    }
    for(int i=1;i<add;i++)
    {
        temp=temp->next;
    }
    temp->data=newData;
    return head;
}

//--------定义打印函数--------
void display(line* head)
{
    line* temp=head;
    while(temp->next!=NULL)
    {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}