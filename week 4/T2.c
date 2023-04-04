#include<stdio.h>
char lei[101][101];
int le[101][101];
int a[3]={1,0,-1},b[3]={1,-1,0};
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)//i是行，j是列
	{
		for(int j=1;j<=n;j++)
		   lei[i][j]=getchar();
		getchar();
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{	int p=0;
			if(lei[i][j]!='*')
			{
				for(int k=0;k<=2;k++)
				  for(int h=0;h<=2;h++)
					if(lei[i+a[k]][j+b[h]]=='*')p++;
				le[i][j]=p;
			}
		}
	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			if(lei[i][j]=='o')printf("%d",le[i][j]);
				else printf("*");
		printf("\n");}

}