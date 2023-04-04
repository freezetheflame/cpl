#include<stdio.h>
int main(){
	int n,maxn = 0,num = 0;
	scanf("%d",&n);
	while(n != 1){
       num++;
       if(num == 1) maxn = n ;
       if(n%2 != 0){
       	n = n*3+1;
		maxn = n>maxn ? n:maxn;
		}
		else n = n/2;
	}
	printf("%d %d",num,maxn);
	return 0;
}