#include<stdio.h>
#include<stdlib.h>

//--------链栈结构定义--------
typedef struct stack
{
    int data;
    struct stack* next;
}stack;

//--------函数声明--------
stack* push(stack* line,int data);        //入栈
stack* pop(stack* line);        //出栈

int main()
{
    stack* line=NULL;
    for(int i=1;i<=5;i++)
    {
        line=push(line,i);
    }
    for(int i=1;i<=5;i++)
    {
        line=pop(line);
    }
    system("pause");
    return 0;
}

//--------定义入栈函数--------
stack* push(stack* line,int data)
{
    stack* temp=(stack*)malloc(sizeof(stack));
    temp->data=data;
    temp->next=line;
    line=temp;
    return line;
}

//--------定义出栈函数--------
stack* pop(stack* line)
{
    if(line)
    {
        stack* p=line;
        line=line->next;
        printf("Pop up: %d\n",p->data);
        if(line)
        {
            printf("Top is %d\n",line->data);
        }else{
            printf("Empty stack!\n");
        }
        free(p);
    }else{
        printf("Empty stack!\n");
        return line;
    }
    return line;
}