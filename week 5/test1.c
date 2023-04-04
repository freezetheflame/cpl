#include<stdio.h>
int swap(int *&a,int *&b){
	int *p;
	p=a;
	a=b;
	b=p;
	return 0;
}
int main(){
	int a=2,b=3;
	swap(a,b);
	printf("%d\n%d",a,b);
	return 0;
}