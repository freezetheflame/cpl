#include<stdio.h>
int main(){
	int a[2005]={};
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j*i<=n;j++)
		{
			a[i*j]^=1;
		}
    for(int i=1;i<=n;i++)
    	if(a[i])printf("%d ",i);
}