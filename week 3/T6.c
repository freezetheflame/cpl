#include<stdio.h>
int a[1000005];
int main(){
	int n,k,p;//p是容器
	scanf("%d%d",&n,&k);
	for(int h=1;h<=n;h++)
		scanf("%d",&a[h]);
	int mid=a[k];
	int i=1,j=n;
	while(i<j){
        while(a[i]<mid&&i!=j)i++;
        while(a[j]>=mid&&j!=i)j--;
        if(i<j){
            p=a[i];
            a[i]=a[j];
            a[j]=p;
        }
    }
    if(j==i){
        i=1;
        while(a[i]!=mid)i++;
    	p=a[i];
        a[i]=a[j];
        a[j]=p;
    }
    for(int h=1;h<=n;h++)
    printf("%d ",a[h]);
	return 0;
}