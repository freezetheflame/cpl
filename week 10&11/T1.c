#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct athe
{
     char s[100];
     int attack;
     int defence;
     int organization;
}Athe;
Athe team[1001];
char name[100],temp[30];
int compareatt(const void *a,const void *b)
{	Athe *aa=(Athe *)a;
	Athe *bb=(Athe *)b;
	return (bb->attack-aa->attack);
}
int comparedef(const void *a,const void *b)
{	Athe *aa=(Athe *)a;
	Athe *bb=(Athe *)b;
	return (bb->defence-aa->defence);
}
int compareorg(const void *a,const void *b)
{	Athe *aa=(Athe *)a;
	Athe *bb=(Athe *)b;
	return (bb->organization-aa->organization);
}
int main()
{
	int n,att,def,org;
	scanf("%d",&n);
	for(int i=0;i<=n-1;i++)
	{	int att1,def1,org1; 
        att1=def1=org1=0;
		scanf("%s",team[i].s);
		for(int j=0;j<=10;j++)
		{	scanf("%s",temp);
			scanf("%d%d%d",&att,&def,&org);
			att1+=att;
			def1+=def;
			org1+=org;
		}
		team[i].attack=att1;
		team[i].defence=def1;
		team[i].organization=org1;
	}
	qsort(team,n,sizeof(Athe),compareatt);
	for(int i=0;i<n;i++)
	{
		printf("%s ",team[i].s);
	}
	printf("\n");
	qsort(team,n,sizeof(Athe),comparedef);
	for(int i=0;i<n;i++)
	{
		printf("%s ",team[i].s);
	}
	printf("\n");
	qsort(team,n,sizeof(Athe),compareorg);
	for(int i=0;i<n;i++)
	{
		printf("%s ",team[i].s);
	}
	return 0;
}
/*
2
China
Fanzhiyi 77 55 22
Zhaopeng 33 44 22
Zhangsan 20 19 11
Lisi 21 15 9
Wangwu 15 11 7
Haishen 10 9 8
Tuiqian 10 22 33
Lanjingling 10 22 33
Tang 10 22 33
Yao 10 22 33
Geneva 0 30 0
Netherlands
Gakpo 0 0 20
Depay 0 0 10
Bergwijn 0 51 28
Weghorst 0 56 27
Dejong 0 61 54
Koopmeiners 00 66 63
vanDijk 0 83 79
Deligt 0 70 71
Ake 0 74 78
Blind 0 59 61
Pasveer 0 61 0
*/