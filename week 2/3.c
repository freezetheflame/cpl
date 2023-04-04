#include<stdio.h>
#include<math.h>
int main(){
	int n;
	double x,sum=0;
	scanf("%lf %d", &x , &n );
	for(int i=0;i <= n;i++)
	{   if(i%2 == 0)
		   {
		   	sum+=pow(x,(2*i+1))/(2*i+1);
			}
		else sum-=pow(x,(2*i+1))/(2*i+1);
	}
	sum=sum*4;
	printf("%.10lf",sum);
	return 0;
}