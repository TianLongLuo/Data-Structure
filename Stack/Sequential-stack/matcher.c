#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//--------全局变量声明--------
int top=-1;
//--------函数声明--------
void push(char* a,char elem);       //入栈
void pop(char* a);      //出栈
char visit(char* a);        //调取栈顶元素

//--------主函数--------
int main()
{
    char a[30];
    char bracket[100];
    printf("Please enter your parentheses:\n");
    scanf("%s",bracket);
    int length=(int)strlen(bracket);
    for(int i=0;i<length;i++)
    {
        if(bracket[i]=='{'||bracket[i]=='(')
        {
            push(a,bracket[i]);
        }else{
            if(bracket[i]=='}')
            {
                if(visit(a)=='{')
                {
                    pop(a);
                }else{
                    printf("Mismatch!\n");
                }
            }else{
                if(visit(a)=='(')
                {
                    pop(a);
                }else{
                    printf("Mismatch!\n");
                }
            }
        }
    }
    if(top!=-1)
    {
        printf("Mismatch!\n");
    }else{
        printf("Match all brackets!!!\n");
    }
    system("pause");
    return 0;
}

//--------定义入栈函数--------
void push(char* a,char elem)
{
    a[++top]=elem;
}

//--------定义出栈函数--------
void pop(char* a)
{
    if(top!=-1)
    {
        top--;
    }else{
        return;
    }
}

//--------调取栈顶元素--------
char visit(char* a)
{
    if(a[top]!=-1)
    {
        return a[top];
    }else{
        return ' ';
    }
}