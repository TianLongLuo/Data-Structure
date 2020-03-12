#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//--------函数声明--------
void Next(int* next,char* T);       //生成用于KMP的临时数组
void KMP_String(char* S,char* T);       //KMP字符串搜索算法

//--------主函数--------
int main()
{
    KMP_String("ababcbd","bcb");
    system("pause");   
}

//--------定义Next函数--------
void Next(int* next,char* T)
{
    int i,j;
    next[0]=0;
    i=0;j=1;
    while(j<strlen(T))
    {
        if(T[i]==T[j])
        {
            next[j]=i+1;
            j++;
            i++;
        }else{
            if(i>0)
            {
                i=next[i-1];
            }else{
                j++;
            }
        }
    }
}
//--------定义KMP算法--------
void KMP_String(char* S,char* T)
{
    int len=strlen(T);
    int next[len];
    Next(next,T);
    int i=0,j=0;
    while(i<strlen(S)&&j<strlen(T))
    {
        if(S[i]==T[j])
        {
            i++;
            j++;
        }else{
            if(j>0)
            {
                j=next[j-1];
            }else{
                i++;
            }
        }
    }
    if(j>=strlen(T))
    {
        printf("Match successful!\n");
        printf("Position is: %d\n",i-j);
    }else{
        printf("Match failed!\n");
    }
}