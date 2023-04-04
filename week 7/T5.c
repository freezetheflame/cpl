#include<stdio.h>
#include<string.h>
#define maxn 20
char c[100005];
int flag[100005][2];
int judge(char c[])
{
	int top=0,i=0,j=0;
	int length=strlen(c);
	while(i<=length-1)
	{   
		if(c[i]=='(')
			{	
				flag[i][0]=1;
				flag[i][1]=j;
				j=i;
				top++;
			}
		else if(c[i]=='[')
		{	
			flag[i][0]=2;
			flag[i][1]=j;
			j=i;
			top++;
		}
		else if(c[i]=='{')
		{	
			flag[i][0]=3;
			flag[i][1]=j;
			j=i;
			top++;
		}
		if(c[i]==')'){
			if(top>0&&flag[j][0]==1){
				top--;
				if(top>0)j=flag[j][1];
			}
			else return 0;
		}
		else if(c[i]==']')
		{	
			if(top>0&&flag[j][0]==2){
				top--;
				if(top>0)j=flag[j][1];
			}
			else return 0;
		}
		else if(c[i]=='}')
		{	
			if(top>0&&flag[j][0]==3){
				top--;
				if(top>0)j=flag[j][1];
			}
			else return 0;
		}
		i++;
	}
	if(top!=0)return 0;
	else return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	scanf("%s",c);
	if(judge(c))printf("True\n");
	else printf("False\n");
	}
	return 0;
}