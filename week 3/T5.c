#include<stdio.h>
char s[100000];
int a[100],flag[100000];
int fan(int a){
	int b,c;
	b=a%10;
	c=a/10;
	return c+b*10;
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	if(n%2==1&&s[(n-1)/2]=='?')//奇数特判
		s[(n-1)/2]='!';
	for(int i=0;i<=(n-1)/2;i++)//
	{   if(s[i]=='!')printf("99");//特判
		if(s[i]!='?')printf("%c",s[i]);//正常输出
		if(s[i]=='?')//遇到问号
		{
			if(s[n-1-i]!='?'){
			printf("%c",s[n-1-i]);
			s[i]=s[n-1-i];
			}//找对面
			else {int k=1;
				while(a[k]==1)k++;
					a[k]=1;
					s[i]=k;
					flag[i]=1;//标注数字
					printf("%02d",s[i]);
				
			}
		}
	}
	int m=(n-1)/2;//取中间值提前处理
	if((n-1)%2==0)m--;
	for(int i=m;i>=0;i--)
	{
		if(flag[i]==0)printf("%c",s[i]);
		else
		{	int ak;
			ak=s[i];
			ak=fan(ak);
			printf("%02d",ak);
		}
			
		
	}
	return 0;

}