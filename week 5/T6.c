#include<stdio.h>
int a[1000][1000];
void work(int n){
	int k=(n+1)/2,i=1;
	a[i][k]=1;
	int num=1;
	while(num<=n*n)
	{
		int pi=i,pk=k;
		i--;k++;
		if(i<=0)i=i+n;
		if(k>n)k=k%n;
		if(a[i][k]==0)a[i][k]=++num;
		else {
			i=pi+1;
			k=pk;
			a[i][k]=++num;
		}
	}
	for(int o=1;o<=n;o++)
	{
		for(int p=1;p<=n;p++)
			printf("%d ",a[o][p]);
		printf("\n");
	}
}
int main(){
	int n;
	scanf("%d",&n);
	work(n);
	return 0;
}