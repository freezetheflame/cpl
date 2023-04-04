#include<stdio.h>
#include<string.h>
typedef struct coff
{
	int ad[10005];
	int bd[10005];
	int sum[10005];
	int cha[10005];
	int multi[2001000];
}Coff;
Coff coefficient;
int a=0,b=0;
char s[100];
void print(int ha[])//代码逻辑：区分首尾先，再区分+-，再区分1与其他
{	int flag=0;
	int count=0;
	for(int i=a+b;i>=0;i--)
	{	if(ha[i]==0)continue;
		count++;
		if(flag==0)//第一个数要忽略一下0,且无视加号
		{	flag=1;
				if(i==1)
				{if(ha[i]>0)
				{if(ha[i]!=1)
					{
						printf("%d%s",ha[i],s);//eg:3x
						continue;
					}
				else 
					{
						printf("%s",s);//eg:x
						continue;
					}}
			else {if(ha[i]!=-1)
					{
						printf("%d%s",ha[i],s);//eg:-8k
						continue;
					}
			else {
				printf("-%s",s);//eg:-j
				continue;
			}}
	  		}
	  		else if(i==0)
			{
				if(ha[i]>0&&count!=1)printf("+%d",ha[i]);//+3
				else printf("%d",ha[i]);//9
				continue;
			}	
			else {
			if(ha[i]>0)//开头无视加号
				{if(ha[i]!=1)
					printf("%d%s^%d",ha[i],s,i);//eg:7x^7
					else printf("%s^%d",s,i);//eg:x^3
				}
			else {
				if(ha[i]==-1) printf("-%s^%d",s,i);
					else printf("%d%s^%d",ha[i],s,i);
				}
				}
			continue;
	}
   else if(i==1)
	{	if(ha[i]>0)
			{	if(ha[i]!=1)
					{
						printf("+%d%s",ha[i],s);
					continue;
				}
				else 
					{
						printf("+%s",s);
						continue;
					}
				}
		else {
			if(ha[i]!=-1)printf("%d%s",ha[i],s);
	           else printf("-%s",s);}
	continue;
	  }	
	else if(i==0)//常数
	{
		if(ha[i]>0&&count!=1){
	      printf("+%d",ha[i]);
		}
		else if(ha[i]!=0)printf("%d",ha[i]);
		continue;
	}	
	else
	  {
	  	if(ha[i]>0)
			{	if(ha[i]!=1)
					printf("+%d%s^%d",ha[i],s,i);
				else 
					printf("+%s^%d",s,i);
				}
		else if(ha[i]!=-1)
			printf("%d%s^%d",ha[i],s,i);
		else printf("-%s^%d",s,i);
	  }
	}
	int c=0;
	if(count==0)printf("%d",c);
	return;
}
int main(){	
	scanf("%d%d",&a,&b);
	scanf("%s",s);
	int m=a>b?a:b;
	for(int i=a;i>=0;i--)
		scanf("%d",&coefficient.ad[i]);
	for(int i=b;i>=0;i--)
		scanf("%d",&coefficient.bd[i]);
	for(int i=m;i>=0;i--)
		coefficient.sum[i]=coefficient.ad[i]+coefficient.bd[i];
	for(int i=m;i>=0;i--)
		coefficient.cha[i]=coefficient.ad[i]-coefficient.bd[i];
	for(int j=a;j>=0;j--)
		for(int i=b;i>=0;i--)
			coefficient.multi[i+j]+=coefficient.ad[j]*coefficient.bd[i];
	print(coefficient.sum);
	printf("\n");
	print(coefficient.cha);
	printf("\n");
	print(coefficient.multi);
	return 0;
}