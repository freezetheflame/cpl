#include<stdio.h>
int k[37][37];
int yanghui(int a,int b){
	if(a==0||b==0)return 0;
	if(b>a)return 0;
	if(b==1)return 1;
	if(a==1)return 1;
	if(k[a][b]==0)
	k[a][b]=yanghui(a-1,b)+yanghui(a-1,b-1);
	return k[a][b];
}
int main(){
	int a1,b1;
	scanf("%d%d",&a1,&b1);
	int ans=yanghui(a1,b1);
	printf("%d",ans);
	return 0;
}