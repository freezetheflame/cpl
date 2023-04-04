#include<stdio.h>
char map[51][51];
int ftpr[51][51];
int mov[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main(){
	int m,n,x0,y0,sum=0,x,y,flag=1;
	scanf("%d%d%d%d",&m,&n,&x0,&y0);
	getchar();
	for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
				{
					map[i][j]=getchar();
					if(map[i][j]=='#')sum++;
				}
			getchar();
		}
		x=x0;y=y0;ftpr[x][y]=1;
		printf("%d\n",sum );
		printf("%d %d\n",x0,y0 );
    while(flag){
    	for(int i=0;i<=3;i++)
    	{
    		if(map[x+mov[i][0]][y+mov[i][1]]=='#'&&ftpr[x+mov[i][0]][y+mov[i][1]]!=1){
    			x=x+mov[i][0];y=y+mov[i][1];sum++;
    			ftpr[x][y]=1;flag=1;
    			printf("%d %d\n",x,y);
    			break;
    		}
    		flag=0;
    	}

    }
    
    for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				if(ftpr[i][j])return 0;
	return 0;
}