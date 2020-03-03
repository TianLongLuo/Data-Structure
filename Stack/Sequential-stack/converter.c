#include<stdio.h>
#include<string.h>
#include<math.h>

//--------����ȫ�ֱ���--------
int top=-1;
//--------�������躯��--------
void push(char* data,char elem);        //��ջ
void pop(char* data);       //��ջ
int Decimal(char* data,int system);     //ת��Ϊʮ����

//--------������--------
int main()
{
    char data[100];
    int system;
    printf("������ת��ǰ�Ľ��ƣ�");
    scanf("%d",&system);
    printf("������ת��ǰ������:");
    scanf("%s",data);
    int dec=Decimal(data,system);
    printf("������ת����Ľ��ƣ�");
    int newsystem;
    scanf("%d",&newsystem);
    while(dec/newsystem)
    {
        push(data,dec%newsystem);
        dec/=newsystem;
    }
    push(data,dec%newsystem);
    printf("ת���������Ϊ��");
    while(top!=-1)
    {
        pop(data);
    }
    getchar();
    getchar();
    return 0;
}

//--------������ջ����--------
void push(char* data,char elem)
{
    data[++top]=elem;
}

//--------�����ջ����--------
void pop(char* data)
{
    if(top==-1)
    {
        return ;
    }
    if(data[top]>=10)
    {
        printf("%c",data[top]+55);
    }else{
        printf("%d",data[top]);
    }
    top--;
}

//--------����ʮ����ת������--------
int Decimal(char* data,int system)
{
    int k=(int)strlen(data)-1;
    int dec=0;
    for(int i=k;i>=0;i--)
    {
        int temp;
        if(data[i]>=48&&data[i]<=57)
        {
            temp=data[i]-48;
        }else{
            temp=data[i]-55;
        }
        dec+=temp*pow(system,k-i);
    }
    return dec;
}