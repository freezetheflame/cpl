#include<stdio.h>
const int maxn=10007;
int main(){
	int sum=1,sumultra=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{   sum=sum*i;
		sum=sum%maxn;
		sumultra+=sum;
	}
	sumultra%=maxn;
	printf("%d",sumultra);
	return 0;
}