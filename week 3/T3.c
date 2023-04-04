#include<stdio.h>
int main(){
	int n,k;
	int a[501]={};
	int kill=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n-1;i++)
    {   int num_count=1;
    	while(num_count!=k){
    		if(a[kill]!=1)num_count++;
    		kill++;
    		if(kill>n)kill=1;
    	}
    	while(a[kill]==1){kill++;if(kill>n)kill=1;}
    	a[kill]=1;
    }
    for(int i=1;i<=n;i++)
    	{if(a[i]==0)
    		printf("%d",i);}
    return 0;
}