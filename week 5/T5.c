#include<stdio.h>
	int a[2005]={};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int j1=n,k1=n-1;
	while(a[j1]<a[k1]){
		j1--;
		k1--;
	}//找最长的序列,直到a[j1]>a[k1]
	int num=j1;
	int u=a[k1];
	while(a[num]>u)num++;//找比a[k1]大的最后一个,找到的则是比a[k1]小的第一个
	//printf("%d",j1);
	int pi=a[num-1];
	a[num-1]=a[k1];
	a[k1]=pi;
	int free=1;
	while(free<j1)
	{
		printf("%d ",a[free]);
		free++;
	}
	for(int i=n;i>=j1;i--)
		printf("%d ",a[i]);
	return 0;
}