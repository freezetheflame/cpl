#include<stdio.h>
int a[51];
int anttt(int n)
{
	if(n==1)return 1;
	if(n==2)return 2;
	if(a[n]==0)
	a[n]=anttt(n-2)+anttt(n-1);
	return a[n];
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",anttt(n));
	return 0;
}
