#include<stdio.h>
int main()
{	int n;
	scanf("%d",&n);
	char s[1001],ji[100];
	int a[53]={};
	scanf("%s",s);
	for(int i=0;i<=n-1;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
			a[s[i]-'a'+1]++;
		else a[s[i]-'A'+1+26]++;
	}
	int j=1;
	int width=0,max_appear=0;
	for(int i=1;i<=26;i++)
	{
		if(a[i]>0)ji[j++]=i-1+'a';
		if(a[i+26]>0)ji[j++]=i-1+'A';
		if(a[i]>0||a[i+26]>0)ji[j++]=' ';
	}
	for(int i=1;i<=26;i++)
		{  
			max_appear=a[i]>max_appear?a[i]:max_appear;
			max_appear=a[i+26]>max_appear?a[i+26]:max_appear;
			//找出最高的频率
			if(a[i]>0&&a[i+26]==0)width+=2;
			if(a[i]>0&&a[i+26]>0)width+=3;
			if(a[i]==0&&a[i+26]>0)width+=2;
		}
	int now_height=max_appear;
	for(int i=1;i<=max_appear;i++)
	{  for(int k=1;k<=26;k++)
		{
			if(a[k]==0&&a[k+26]==0)continue;
			if(a[k]==0&&a[k+26]>0&&a[k+26]<now_height)printf("  ");
			if(a[k]==0&&a[k+26]>0&&a[k+26]==now_height){printf("= ");a[k+26]--;}
			if(a[k]>0&&a[k]<now_height&&a[k+26]==0)printf("  ");			
			if(a[k]>0&&a[k]<now_height&&a[k+26]>0&&a[k+26]<now_height)printf("   ");
			if(a[k]>0&&a[k]<now_height&&a[k+26]>0&&a[k+26]==now_height){printf(" = ");a[k+26]--;}
			if(a[k]>0&&a[k]==now_height&&a[k+26]==0){printf("= ");a[k]--;}
			if(a[k]>0&&a[k]==now_height&&a[k+26]>0&&a[k+26]==now_height){printf("== ");a[k]--;a[k+26]--;}
			if(a[k]>0&&a[k]==now_height&&a[k+26]>0&&a[k+26]<now_height){printf("=  ");a[k]--;}
		}
        now_height--;
        printf("\n");
	}
	for(int i=1;i<=width-1;i++)
		printf("-");
	printf("\n");
	for(int i=1;i<=j-1;i++)
		printf("%c",ji[i]);
	return 0;
}