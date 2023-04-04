#include<stdio.h>
#include<string.h>
int a,b,c;int pose=1;
int x1,x2,y1,y2;
void change(char type)//type指代翻转方向，pose指代姿势
{	if(pose==1)
	{
		switch (type){
		    case 'W':x2=x1;x1-=c;pose=2;break;
		    case 'S':x1=x2;x2+=c;pose=2;break;
		    case 'A':y2=y1;y1-=c;pose=3;break;
		    case 'D':y1=y2;y2+=c;pose=3;break;
		}
	}
	else if(pose==2)
	{
		switch (type){
		    case 'W':x2=x1;x1-=b;pose=1;break;
		    case 'S':x1=x2;x2+=b;pose=1;break;
		    case 'A':y2=y1;y1-=b;pose=4;break;
		    case 'D':y1=y2;y2+=b;pose=4;break;
		}
	}
	else if(pose==3)
	{
		switch (type){
		    case 'W':x2=x1;x1-=a;pose=5;break;
		    case 'S':x1=x2;x2+=a;pose=5;break;
		    case 'A':y2=y1;y1-=a;pose=1;break;
		    case 'D':y1=y2;y2+=a;pose=1;break;
		}
	}
	else if(pose==4)
	{
		switch (type){
		    case 'W':x2=x1;x1-=a;pose=6;break;
		    case 'S':x1=x2;x2+=a;pose=6;break;
		    case 'A':y2=y1;y1-=a;pose=2;break;
		    case 'D':y1=y2;y2+=a;pose=2;break;
		}
	}
	else if(pose==5)
	{
		switch (type){
		    case 'W':x2=x1;x1-=b;pose=3;break;
		    case 'S':x1=x2;x2+=b;pose=3;break;
		    case 'A':y2=y1;y1-=b;pose=6;break;
		    case 'D':y1=y2;y2+=b;pose=6;break;
		}
	}
	else if(pose==6)
	{
		switch (type){
		    case 'W':x2=x1;x1-=c;pose=4;break;
		    case 'S':x1=x2;x2+=c;pose=4;break;
		    case 'A':y2=y1;y1-=c;pose=5;break;
		    case 'D':y1=y2;y2+=c;pose=5;break;
		}
	}
}
int main(){
	scanf("%d%d%d",&b,&a,&c);
	char ci[1005];;
	x1=0;x2=b;y1=0;y2=a;
	scanf("%s",ci);
	int len=strlen(ci);
	for(int i=0;i<=len-1;i++)
	{
		change(ci[i]);
	}
	printf("%d %d %d %d",x1,x2,y1,y2);
	return 0;
}