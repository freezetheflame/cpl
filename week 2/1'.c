#include<stdio.h>
int main(){
	int n,num=0,s;
	scanf("%d", &n );
	for(int i=1;i<= 2*n-1; i++)
	{   
		scanf("%d",&s);
		num^=s;
	}
	printf("%d",num);
	return 0;
}