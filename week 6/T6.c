#include<stdio.h>
#include<math.h>

char a[1025][2049];
void paint(int n,int x,int y){//x是横坐标，y是纵坐标
  if(n==1)
  {a[x][y]='/';a[x][y+1]='\\';a[x+1][y-1]='/';a[x+1][y]='_';
  	a[x+1][y+1]='_';a[x+1][y+2]='\\';
  }
  else 
  	{
  		paint(n-1,x+pow(2,n-1),y-pow(2,n-1));
  		paint(n-1,x+pow(2,n-1),y+pow(2,n-1));
  		paint(n-1,x,y);
  	}
}
int main(){
	int n1;
	scanf("%d",&n1);
	int maxn=pow(2,n1+1);
	for(int i=1;i<=maxn/2;i++)
		for(int j=1;j<=maxn;j++)
			a[i][j]=' ';
	paint(n1,1,maxn/2);
	for(int i=1;i<=maxn/2;i++)
	{	
		for(int j=1;j<=maxn;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
}