#include<stdio.h>
int a[100005];
int N[100005][2];
int find(int l,int r)
{
	int max=a[l],cut=l;
	for(int j=l;j<=r;j++)
	{
		if(a[j]>max){
			max=a[j];
			cut=j;
		}
	}
	//printf("a%da",cut);
	return cut;
}
void magset(int l,int r){
	if(l==r){
		N[l][0]=N[l][1]=l;
		return;
	}
	int k=find(l,r);
	//printf("b%d%db",l,r);
	N[k][0]=l;N[k][1]=r;
	if(k==l){
		magset(k+1,r);
		return;
	}
	if(k==r){
	magset(l,k-1);
	return;
	}
	magset(k+1,r);
	magset(l,k-1);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	magset(1,n);
	for(int i=1;i<=n;i++)
		printf("%d %d\n",N[i][0],N[i][1]);
	return 0;
}