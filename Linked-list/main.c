#include<stdio.h>
#include<stdlib.h>

//--------创建链表结构--------
typedef struct Link
{
    int elem;
    struct Link* next;
}link;

//--------声明函数--------

link* initLink(int n);
link* insertElem(link* p,int elem,int add);
link* delElem(link* p,int add);
int selectElem(link* p,int elem);
link* amendElem(link* p,int elem,int newelem);
void display(link* p);

//--------主程序--------
int main()
{
//--------初始化链表--------
    link* p=initLink(5);
    display(p);
//--------把5插入第3个位置--------
    insertElem(p,5,3);
    display(p);
//--------把第一个结点删了--------
    delElem(p,1);
    display(p);
//--------获取4的位置--------
    printf("%d\n",selectElem(p,4));
//--------修改5为77--------
    amendElem(p,5,77);
    display(p);
    system("pause");
    return 0;
}
//--------定义初始化函数--------
link* initLink(int n)
{
    link* p=(link*)malloc(sizeof(link));
    link* temp=p;
    temp->elem=n;
    for(int i=n;i>=1;i--)
    {
        link* a=(link*)malloc(sizeof(link));
        scanf("%d",&(a->elem));
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
}

//--------定义插入结点函数--------
link* insertElem(link* p,int elem,int add)
{
    link* temp=p;

    for(int i=add;i>1;--i)
    {
        temp=temp->next;
        if(NULL==temp)
        {
        printf("Position Error\n");
        return p;
        }
    }
    link* new=(link*)malloc(sizeof(link));
    new->elem=elem;
    new->next=temp->next;
    temp->next=new;

    return p;
}

//--------定义删除结点函数--------
link* delElem(link* p,int add)
{
    link* temp=p;
    for(int i=add;i>1;i--)
    {
        temp=temp->next;
        if(NULL==temp)
        {
        printf("Position Error\n");
        return p;
        }
    }
    link* c=temp->next;
    temp->next=temp->next->next;
    free(c);
    return p;
}

//--------定义查找函数--------
int selectElem(link* p,int elem)
{
    link* temp=p;
    int i=0;
    while(NULL!=temp->next)
    {
        temp=temp->next;
        i++;
        if(elem==temp->elem)
        {
            return i;
        }
    }
    printf("Position Error!\n");
    return -1;
}

//--------定义修改函数--------
link* amendElem(link* p,int elem,int newelem)
{
    link* temp=p;
    while(NULL!=temp->next)
    {
        temp=temp->next;
        if(elem==temp->elem)
        {
            temp->elem=newelem;
            return p;
        }
    }
    printf("Position Error!\n");
    return p;
}
//--------定义打印函数--------
void display(link* p)
{
    link* temp=p;
    while(NULL!=temp->next)
    {
        temp=temp->next;
        printf("%d ",temp->elem);
    }
    printf("\n");
}