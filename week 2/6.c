#include<stdio.h>
char str[1000000];
int main(){
	int n,k;
	char c;
	scanf("%d",&n);
	c=getchar();
   for(int i=0;i<=n-1;i++)
   	str[i]=getchar();
   scanf("%d",&k);
    for(int i=k-1;i>=0;i--)
    	printf("%c",str[i]);
    for(int i=n-1;i>=k;i--)
    	printf("%c",str[i]);
	return 0;
}