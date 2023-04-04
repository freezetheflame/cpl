#include<stdio.h>
int a[101][101],b[101][101];
int main(){
	int m,n,p;
	scanf("%d%d%d",&m,&n,&p);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=p;j++)
			scanf("%d",&b[i][j]);
	for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=p;j++)
			{   int sum=0;
				for(int k=1;k<=n;k++)
					sum+=a[i][k]*b[k][j];
				printf("%d ",sum );
			}
			printf("\n");
		}
		return 0;
}