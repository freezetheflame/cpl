#include<stdio.h>
#include<math.h>
int main(){
	int len,N;
	long sum=0;
	scanf("%d%d",&len,&N);
	char shu[31];
	int su[31];
	scanf("%s",shu);
    for(int i=0;i<=len-1;i++)
    {
     if(shu[i]>='A'&&shu[i]<'Z')su[i]=shu[i]-'A'+10;
       else {su[i]=shu[i]-'1';su[i]++;}
     if(su[i]>=N){printf("Error");return 0;}
   }
   for(int i=0;i<=len-1;i++)
   {    if(i==len-1)sum+=su[i];
   		else sum+=su[i]*pow(N,len-i-1);
   }
   printf("%d",sum);
   return 0;
}