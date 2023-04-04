#include<stdio.h>
#include<math.h>
int n=0,p=0;
int a[25]={0};
double f(double x){
	double sum=0.0;
	double t=1.0;
	for(int i=0;i<=n;i++)
	{
		sum+=a[i]*t;
		t*=x;
	}
	if(p==1)return sum;
	if(p==-1)return 1.0/sum;
	if(p==-2)return 1.0/(sum*sum);
	if(p==2)return sum*sum;

}
double caculus(double a,double b)
{
	return (4.0*f((a+b)/2.0)+f(a)+f(b))*(b-a)/6.0;
}

double sps(double l,double r,double el){
	double mid=(l+r)/2.0;
    double S=caculus(l,r);
    double SR=caculus(mid,r);
    double SL=caculus(l,mid);
    if(fabs(SL+SR-S)<=(15.0*el))return SL+SR+(SL+SR-S)/15.0;
    else 
    return sps(l,mid,el/2.0)+sps(mid,r,el/2.0);	
}
int main(){	
	scanf("%d%d",&n,&p);
	for(int i=0;i<=n;i++){
		scanf("%d",&a[i]);
	}
	double c=0.0,b=0.0;
	scanf("%lf%lf",&c,&b);
	printf("%lf",sps(c,b,0.0001));
	return 0;
}