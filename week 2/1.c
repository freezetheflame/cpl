#include<stdio.h>
int a[1000000];//我是那一个落单的桶
int main(){
   int n,b;
   scanf("%d",&n);
   for (int i = 1;i <= 2*n-1; i++ )
   {
   	   scanf("%d",&b);
   	   a[b]++;
   }
   for (int i = 1;; i++ )
   	 {
   	 	if( a[i]==1 ) {printf("%d", i);break;}
   	}
   	return 0;
}