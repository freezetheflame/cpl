#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(char *p1,char *p2)
{
	int i=0,j=0;
	int len1=strlen(p1),len2=strlen(p2);
	int flag=-1;
	for(i=0;i<=len1-1;i++)
	{	
		for(int k=0;k<=len1-1-i;k++)
		{
			if(*(p1+k+i)!=*(p2+k))
				{
					flag=-1;
					break;
				}
				else flag=i;
		}
		if(flag!=-1)break;
	}
	return flag;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{	char *p1=malloc(1005*sizeof(char));
		char *p2=malloc(1005*sizeof(char));
		char *p11=malloc(1005*sizeof(char));
		scanf("%s%s",p1,p2);
		int len1=strlen(p1),len2=strlen(p2);	
		int flag=cmp(p1,p2);
		strcat(p1,p2);
		if(flag==-1)printf("%s\n",p1);
		else 
		{
			for(int j=0;j<=len1+len2-1;j++)
			{
				if(j==flag)j=len1;
				printf("%c",*(p1+j));
			}
		}
		printf("\n");
		free(p1);
		free(p2);
		free(p11);
	}
	return 0;
}