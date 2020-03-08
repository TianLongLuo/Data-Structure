#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LinkSize 3

//--------创建链串结构--------
typedef struct Link
{
    char a[LinkSize];
    struct Link* next;
}link;

//--------函数声明--------
link* init(link* head,char* str);       //初始化链串
void display(link* head);       //显示链串

//--------主函数--------
int main()
{
    link* head=NULL;
    head=init(head,"c.biancheng.net.ltl");
    display(head);
    system("pause");
    return 0;
}

//--------定义初始化函数--------
link* init(link* head,char* str)
{
    int length=(int)strlen(str);
    int num=length/LinkSize;
    if(length%LinkSize)
    {
        num++;
    }
    head=(link*)malloc(sizeof(link));
    head->next=NULL;
    link* temp=head;
    for(int i=0;i<num;i++)
    {
        int j=0;
        for(;j<LinkSize;j++)
        {
            if(i*LinkSize+j<length)
            {
                temp->a[j]=str[i*LinkSize+j];
            }else{
                temp->a[j]='#';
            }
        }
        if(i*LinkSize+j<length)
        {
            link* body=(link*)malloc(sizeof(link));
            body->next=NULL;
            temp->next=body;
            temp=temp->next;
        }
    }
    return head;
}

//--------定义打印函数--------
void display(link* head)
{
    link* temp=head;
    while(temp)
    {
        for(int i=0;i<LinkSize;i++)
        {
            printf("%c",temp->a[i]);
        }
        temp=temp->next;
    }
    printf("\n");
}