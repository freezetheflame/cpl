//Q from TEST A
//Sakiyary uses Sliding Window to solve the problem at a low cost->前缀和做法
#include<stdio.h>
int sum[1301][1301],value[600][600];
int main()
{
    int n,m,d;
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0;i<n;i++){
        for(int j=0;j< m;j++)
        {
            int a=d+m+i-j,b=d+i+j+1;
            scanf("%d",&sum[a][b]);
        }
    }
    int c=m+n+2*d;
    for(int i=0;i<n;i++){
        for(int j=0;j< m;j++)
        { 
            sum[i][j]+=(i?sum[i-1][j]:0)+(j?sum[i][j-1]:0)-(i&&j?sum[i-1][j-1]:0);
        }
    }
    int max_value=0x80000000,max_cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j< m;j++)
        {
            int a=d+m+i-j,b=d+i+j+1;
            value[i][j]=sum[a+d][b+d]+sum[a-d-1][b-d-1]-sum[a+d][b-d-1]-sum[a-d-1][b+d];
            if(max_value==value[i][j])
            max_cnt++;
            else if(max_value){
                max_value=value[i][j];
                max_cnt=1;
            }
            
            
        }
    }
    printf("%d %d\n",max_value,max_cnt);
    for(int i=0;i<n;i++)
        for(int j=0;j< m;j++)
            if(max_value==value[i][j])
                printf("%d %d\n",i+1,j+1);
    return 0;
        
}