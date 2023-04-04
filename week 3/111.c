#include <stdio.h>
#define N 100005
int a[N]={0};
int ans[N][2]={0};
int Find(int l,int r)
{
    int max=a[l];
    int i,p;
    for(i=l;i<=r;i++)
    {
        if(a[i]>=max)
        {max=a[i];
        p=i;}
    }
    return p;

}
void magset(int l,int r)
{
    
    int mid=Find(l,r);
    ans[mid][0]=l;ans[mid][1]=r;
    if(l==r)
    {return;}
    else
    {
    magset(l,mid-1);
    magset(mid+1,r);}

}

int main(void)
{
    int n,j,mid;
    
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        scanf("%d",&a[j]);
    }
    magset(1,n);
    for(int k=1;k<=n;k++)
    {
        printf("%d %d\n",ans[k][0],ans[k][1]);
    }
    return 0;
}