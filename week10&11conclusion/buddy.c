/*
题面：https://public.oj.cpl.icu/contest/31/problem/144
*/
#include<stdio.h>
#include<math.h>
int a[1000005][4],now=2,maxn;/*a[][0]存储该空间大小，a[][1]存上一个地址（即下标）,
a[][2]存下一个地址,a[][3]存储id,now表示现在的空间数量*/
int f(int n){
	int i=0;
	while(n>(int)pow(2.0,i))
	{
		i++;
	}
	return i+1;//找对应需要的2^n空间
}
int find(int n){
	int flag=0,min=maxn;//找恰好匹配的或者更大一点点的
	for(int i=1;i<=now-1;i++)
	{	if(flag==0&&a[i][0]==min&&a[i][3]==0)flag=i;
		if(a[i][0]>n&&a[i][0]<min&&a[i][3]==0)
		{
		min=a[i][0];
		flag=i;
		}
		if(a[i][0]==n&&a[i][3]==0)return i;
	}
	return flag;//找匹配空间的办法，缺点式兼并了恰好匹配和需要切割的情况，所以使用后要附加判断
}
void cut(int i)//对a[i][]做切割操作，除开值的减半，还有链表的结点转移
{
	a[i][0]--;//空间减半
	a[now][0]=a[i][0];//开新空间
	a[now][1]=i;
	a[now][2]=a[i][2];
	a[i][2]=now;
	now++;
}
int main(){
	scanf("%d",&maxn);
	maxn++;
	int q;
	scanf("%d",&q);
	getchar();
	a[1][0]=maxn;
	char c;
	for(int i=1;i<=q;i++)
	{	
		scanf("%c",&c);
		if(c=='Q')
		{   getchar();
			printf("%d\n",now-1);
			int j=1;			
			while(a[j][2]!=0){
					printf("%d ",a[j][3]);
					if(a[j][2]!=0)j=a[j][2];
				}
			printf("%d\n",a[j][3]);
		}
		else if(c=='A')
		{	int id,size;
			scanf("%d%d",&id,&size);
			getchar();
			size=f(size);
			int m=find(size);
			if(a[m][0]==size)a[m][3]=id;
			else {
				while(a[m][0]>size)cut(m);
				a[m][3]=id;
			}
		}
	}
	return 0;
}
//中肯地说，其实写成结构体更加合适，但其实原理和这个小二维数组差不多，模拟一个链表出来