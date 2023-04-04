#include<stdio.h>
#include<math.h>
#include<string.h>
int work(int a,int b,int c,int Q)
{
	int a1,b1,c1;
	int j=1;
	int num=0;
	while(a>0)
	{	num+=(a%10)*(pow(Q,j-1));
		a=a/10;
		j++;
	}
	a1=num;
    j=1;
    num=0;
    while(b>0)
	{	num+=(b%10)*(pow(Q,j-1));
		b=b/10;
		j++;
	}
	b1=num;
    j=1;
    num=0;
    while(c>0)
	{	num+=(c%10)*(pow(Q,j-1));
		c=c/10;
		j++;
	}
	c1=num;
	printf("%d",c1);
	if(a1*b1==c1)return 1;
	else return 0;
}
int main(){
	printf("%d",work(6,9,42,13));
	return 0;
}