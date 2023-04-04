#include<stdio.h>
int a[10005],b[10005];
void qsort(int l,int r){
    int i,j,mid,p,p1;
    i=l;j=r;
    mid=a[(l+r)/2];
    do{
        while(a[i]<mid)i++;
        while(a[j]>mid)j--;
        if(i<=j){
            p=a[i];		p1=b[i];
            a[i]=a[j];	b[i]=b[j];
            a[j]=p;		b[j]=p1;
            i++;j--;
        }
    }while(i<=j);
    if(l<j)qsort(l,j);
    if(r>i)qsort(i,r);
}
int main()
{
	int L,n,max=0;
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	qsort(1,n);
	int t=0,j=n;
	while(t<L)
	{
		if(L-t>=b[j])
		{
			max+=b[j]*a[j];
			t+=b[j];
			j--;
		}
		else 
		{
			max+=a[j]*(L-t);
			t=L;
		}
	}
	printf("%d",max);
	return 0;
}
