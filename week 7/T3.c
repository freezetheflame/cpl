#include<stdio.h>
int num[4]={},past[1000][4]={},V[4]={},a,b,c;
int flag=0,k,nn=0;
void recover(){
	nn--;
	for(int i=1;i<=3;i++)
		num[i]=past[nn][i];//队列取用。取完就废了
	
}
void pour(int n,int m)
{	
	for(int i=1;i<=3;i++)
		past[nn][i]=num[i];//存新的情况	
	nn++;
	num[m]+=num[n];
	num[n]=0;
	if(num[m]>V[m])num[m]=V[m];
}
void search(int step)
{	if(flag==1)return;
	if(step>k)return;
	if(num[1]!=0)
		{
			pour(1,2);
			if(num[1]==a&&num[2]==b&&num[3]==c)
				{
					flag=1;
					return;
				}
			else search(step+1);//进入第一步DFS
			recover();
			if(flag==1)return;
			pour(1,3);
			if(num[1]==a&&num[2]==b&&num[3]==c)
				{
					flag=1;
					return;
				}
			else search(step+1);
			recover();
			if(flag==1)return;
		}
	if(num[2]!=0)
		{
			pour(2,1);
			if(num[1]==a&&num[2]==b&&num[3]==c)
				{
					flag=1;
					return;
				}
			else search(step+1);
			recover();
			if(flag==1)return;
			pour(2,3);
			if(num[1]==a&&num[2]==b&&num[3]==c)
				{
					flag=1;
					return;
				}
			else search(step+1);
			recover();
			if(flag==1)return;
		}
		if(num[3]!=0)
		{	
			pour(3,1);
			if(num[1]==a&&num[2]==b&&num[3]==c)
				{
					flag=1;
					return;
				}
			else search(step+1);
			recover();
			if(flag==1)return;
			pour(3,2);
			if(num[1]==a&&num[2]==b&&num[3]==c)
				{
					flag=1;
					return;
				}
			else search(step+1);
			recover();
			if(flag==1)return;
		}
}
int main(){
	scanf("%d",&k);
	for(int i=1;i<=3;i++)
		scanf("%d",&V[i]);
	for(int i=1;i<=3;i++)
	{
		scanf("%d",&num[i]);
	}	
	scanf("%d%d%d",&a,&b,&c);
	if(num[1]==a&&num[2]==b&&num[3]==c)
	{
		printf("Yes");
		return 0;
	}
	if(a!=0&&b!=0&&c!=0){
		printf("No");
		return 0;
	}
	search(1);
	if(flag==1)printf("Yes");
	else printf("No");
	return 0;
}
