#include<stdio.h>
#include<math.h>
int work(int a,int b,int c,int Q)
{
	int a1,b1,c1;
	int j=1;
	int num=0;
	while(a>0)
	{	if(a%10>=Q)return 0;
		num+=(a%10)*(pow(Q,j-1));
		a=a/10;
		j++;
	}
	a1=num;
    j=1;
    num=0;
    while(b>0)
	{	if(b%10>=Q)return 0;
		num+=(b%10)*(pow(Q,j-1));
		b=b/10;
		j++;
	}
	b1=num;
    j=1;
    num=0;
    while(c>0)
	{	if(c%10>=Q)return 0;
		num+=(c%10)*(pow(Q,j-1));
		c=c/10;
		j++;
	}
	c1=num;
	if(a1*b1==c1)return 1;
	else return 0;
}
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=2;i<=40;i++)
	{
		if(work(a,b,c,i)==1)
			{
				printf("%d",i);
				return 0;
			}
	}
	printf("0");
	return 0;
}