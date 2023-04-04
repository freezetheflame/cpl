#include<stdio.h>
#include<math.h>
int Is_prime(int i){
	if(i==1||i==2)return 1;
	for(int k=2;k*k<=i;k++)
		if(i%k==0)return 0;
	return 1;
}
int convert(int i){
	int num=0,j=1;
	while(i>pow(10,j)){
		j++;
	}
	int m=j;
	while(j>0)
	{	num+=(i%10)*(pow(10,j-1));
		i=i/10;
		j--;
	}
	return num;
}
int main(){
	printf("%d\n",convert(145) );
	return 0;
}