#include<stdio.h>
#include<stdbool.h>
int ItemCount[27];
int n;
typedef struct Item{
int bignum;
int smallnum;
bool BIG_Exist;
bool SMALL_Exist;
}ITEM;
ITEM handle[27];
int main(){
	scanf("%d",&n);
	char s[1001];
	scanf("%s",s);
	for(int i=0;i<=n-1;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
			{
				handle[s[i]-'a'+1].smallnum++;
				handle[s[i]-'a'+1].SMALL_Exist=true;
			}
		else {
			handle[s[i]-'A'+1].bignum++;
			handle[s[i]-'A'+1].BIG_Exist=true;
			}
	}
	int max_appear=0;
	for(int i=1;i<=26;i++)
	{
		if(handle[i].smallnum>max_appear)max_appear=handle[i].smallnum;
		if(handle[i].bignum>max_appear)max_appear=handle[i].bignum;
	}
	for(int i=max_appear;i>=1;i--)
	{
		for(int k=1;k<=26;k++)
		{
			if(handle[k].SMALL_Exist)
			{
				if(handle[k].smallnum==i)
						{
							handle[k].smallnum--;
							printf("=");
						}
				else printf(" ");
			}
			if(handle[k].BIG_Exist)
			{
				if(handle[k].bignum==i)
				{
					handle[k].bignum--;
					printf("=");	
				}
				else printf(" ");
			}
			if(handle[k].BIG_Exist||handle[k].SMALL_Exist)
				printf(" ");
		}
		printf("\n");
	}
	int flag=0;
	for(int i=1;i<=26;i++)
	{
		if((handle[i].BIG_Exist||handle[i].SMALL_Exist)&&flag!=0)printf("-");
		if(flag==0&&(handle[i].BIG_Exist||handle[i].SMALL_Exist))flag=1;
		if(handle[i].SMALL_Exist)printf("-");
		if(handle[i].BIG_Exist)printf("-");
	}
	printf("\n");
	for(int i=1;i<=26;i++)
	{
		if(handle[i].SMALL_Exist)printf("%c",i+'a'-1);
		if(handle[i].BIG_Exist)printf("%c",i+'A'-1);
		if(handle[i].BIG_Exist||handle[i].SMALL_Exist)printf(" ");
	}
	return 0;
}
/*
经验总结：通过一定的结构体和函数封装把数据之间的关联点明，优化数据
结构有利于代码的稳定性以及易于编辑修改，寻找对应的bug
*/