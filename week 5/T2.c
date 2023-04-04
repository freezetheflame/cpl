#include<stdio.h>
int work(int n,int num){
	int last=11,sum=num;
	for(int i=2;i<=n;i++)
		{
			sum+=num*last;
			last*=10;
			last++;
		}
	return sum;
}
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	printf("%d\n",work(n,t));
	return 0;
}