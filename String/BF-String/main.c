#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//--------函数声明--------
int mate(char* A,char* B);

int main()
{
    int result=mate("I love you!","love");
    if(result!=0)
    {
        printf("String position is at position %d of the main string\n",result);
    }
    system("pause");
    return 0;
}

//--------函数定义--------
int mate(char* A,char* B)
{
    int i=0,j=0;
    while(i<strlen(A)&&j<strlen(B))
    {
        if(A[i]==B[j])
        {
            i++;
            j++;
        }else{
            i=i-j+1;
            j=0;
        }
    }
    if(j==strlen(B))
    {
        return i-strlen(B)+1;
    }
    return 0;
}
