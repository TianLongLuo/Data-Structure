#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//--------声明函数--------
void Next(int* next,char* T);     //生成用于KMP的next数组
int KMP_String(char* S,char* T,int* site);      //找到所有子串
void replace(char* S,char* T,char* NewT,int* site);        //用于在主串中替换所有子串

//--------主函数--------
int main()
{
    char S[100]="ababaabaabbaac";
    char T[100]="baa";
    char new[100]="IOU";
    int site[10];
    replace(S,T,new,site);
    system("pause");
}

//--------生成Next数组函数--------
void Next(int* next,char* T)
{
    int i=0,j=1;
    next[0]=0;
    while(j<strlen(T))
    {
        if(T[i]==T[j])
        {
            next[j]=i+1;
            i++;
            j++;
        }else{
            if(i>0)
            {
                i=next[i-1];
            }else{
                next[j]=0;
                j++;
            }
        }
    }
}

//--------寻找所有子串函数--------
int KMP_String(char* S,char* T,int* site)
{
    int len=strlen(T);
    int next[len];
    Next(next,T);
    int i=0,j=0;
    int k=-1;
    while(i<strlen(S))
    {
        if(j<strlen(T))
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
        }else{
            
            site[++k]=i-j;
            j=0;
        }
    }
    if(k!=-1)
    {
        printf("Match %d\n",k+1);
        return k+1;
    }else{
        printf("Match failed\n");
        return -1;
    }
}

//--------定义用于替换子串的函数--------
void replace(char* S,char* T,char* NewT,int* site)
{
    int k=KMP_String(S,T,site);
    int len=strlen(T);
    int i=0,a=0,n=0;
    while(i<k)
    {
        a=site[i];
        while(a<site[i]+len)
        {
            S[a]=NewT[n];
            a++;
            n++;
        }
        n=0;
        i++;
    }
    printf("Replace successfully\n");
    printf("String is:\n");
    printf("%s\n",S);
}