#include <stdio.h>
#include <math.h>
int int_pow(int base,int exp);
void narcissistic(int x,int y);
void narcissistic_2(int z);//以上三行均为声明函数
int main()
{
    int a,temp_a;
    printf("请输入一个整数:");
    scanf("%d",&a);
    temp_a=a;
    int n=0;
    while(a!=0)//计算输入的整数为几位数
    {
        a=a/10;
        n++;
    }
    narcissistic(n,temp_a);//调用函数
    narcissistic_2(n);//调用函数
    return 0;
}
int int_pow(int base,int exp){//这里定义了一个为整型数据设计的运算函数int_pow,替换了pow以更加精确地运算
    int result=1;
    for (int i=0;i<exp;i++){
        result*=base;
    }
    return result;
}
void narcissistic(int x,int y)//第一个函数用于判断输入的函数是否为水仙花数
{
    int b,c=0,y2=y;
    for(int i=1;i<=x;i++)
    {
        b=y%10;
        y/=10;
        c+=int_pow(b,x);
    }
    if(c==y2)
    {
        printf("您输入的是一个水仙花数\n");
    }
    else
    {
        printf("您输入的不是一个水仙花数\n");
    }
}
void narcissistic_2(int z)//第二个函数用于输出输入数据的位数的所有水仙花数
{
    int minimum=int_pow(10,z-1),maximum=int_pow(10,z)-1;
    int i=minimum,temp2,b2,c=0;
    int temp_i;
    printf("%d位的水仙花数有：\n",z);
    while(i<=maximum)
    {
        temp_i=i;c=0;
        for(int g=1;g<=z;g++)
    {
        b2=temp_i%10;
        temp_i/=10;
        c+=int_pow(b2,z);
    }
    if(c==i)
    {
        printf("%d\n",i);
    }
    i++;
    }
}
