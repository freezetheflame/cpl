#include <stdio.h>
int main(void)
{
    int n,i=0,j=0;
    int a[101][101]={};//初始化
    int vectors[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},{-1,-1},{1,1},{-1,1},{1,-1}};
    scanf("%d",&n);    
    for(i=0;i<n;i++)
    {   
        getchar();
        for(j=0;j<n;j++)
        {
            scanf("%c",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
    	{
	     int count = 0;
         if(a[i][j]=='o')
        {

        	 for (int k = 0; k < 8; ++k) 
         	{
                int newI = i + vectors[k][0];
                int newJ = j + vectors[k][1];
                if(newI >= 0 && newJ >= 0 && newI < n&& newJ < n)
                {	
                    if (a[newI][newJ] == '*') 
                    {
                        count++;                        
                    }
                }
         		a[i][j]=count+'0';       
                
        	}
        }
    }
    for(i=0;i<n;i++)
    {       
     for(j=0;j<n;j++)
         printf("%c",a[i][j]);
       printf("\n");
    }
                return 0;
}