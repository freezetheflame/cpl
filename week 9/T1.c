#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *ans=NULL;
char *rsv="const\0int\0float\0double\0long\0static\0void\0char\0extern\0return\0break\0enum\0struct\0typedef\0union\0goto";
char *opr="+\0-\0*\0/\0=\0==\0!=\0>=\0<=\0>\0<";
char *f="float";
char *in="integer";
int flag=0;
int compare1(char* p){//mention:*p isn't  changed,we only make a comparation
	int kk=0;//表示是否有匹配的reserved
	char *pre;
	pre=rsv;
	for(int num=1;num<=16;num++)
	{	
		if(strcmp(p,pre)==0)
			kk=1;
		while(*pre!='\0')
		{
			pre++;
		}
		pre++;
	}
	return kk;
}
int IsLetter(char ch) { 		//判断是否为字母
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))return 1;
	else return 0;
}

int IsDigit(char ch)  {			//判断是否为数字
	if (ch >= '0'&&ch <= '9') return 1;
	else return 0;
}
char *processnum(char *num){
	int len=strlen(num);
	int count=0;
	for(int i=1;i<=len-1;i++)
	{
		if(IsDigit(*(num+i))==0&&*(num+i)!='.')return NULL;
		if(*(num+i)=='.')count++;
		if(count>1)return NULL;
	}
	if(count==1)return f;
	else if(count==0)return in;
}
int judge_var(char *p){
	int len=strlen(p);
	for(int i=1;i<=len-1;i++)
	{
		if(IsLetter(*(p+i))==0&&*(p+i)!='_'&&IsDigit(*(p+i))==0)
			return 0;
	}
	return 1;
}
int opre(char *p)
{
	int kk=0;//表示是否有匹配的operator
	char *pre=malloc(100*sizeof(char));
	pre=opr;
	for(int num=1;num<=11;num++)
	{	
		if(strcmp(p,pre)==0)
			kk=1;
		while(*pre!='\0')
		{
			pre++;
		}
		pre++;
	}
	return kk;
}
void process(char *p){
	if(*p=='\0') 
		return;
	int isthere=0;
	if(*(p+strlen(p)-1)==';'){
		*(p+strlen(p)-1)='\0';
		isthere=1;
	}
	if(*p=='-'&&strcmp(p,"-")==0)
		{
			strcat(ans,"operator");
			if(isthere==1)strcat(ans,"\n");
			else strcat(ans," ");
		}

	else if(IsLetter(*p)==1)/*letter initial's posibilities:reserved,variable;
										not containing operater*/
	{
		if(compare1(p)==1)
		{
			strcat(ans,"reserved");//判断是否为保留字，无异议
			if(isthere==1)strcat(ans,"\n");
			else strcat(ans," ");
			return;
		}
		else if(judge_var(p)==1)
		{
			strcat(ans,"variable");/*判断是否为变量，此处缺少下划线
			                        开头情况‘’‘’,无需判断数字开头,因为已经确定字母开头*/
			if(isthere==1)strcat(ans,"\n");
			else strcat(ans," ");
			return;
		}
	}
	else if(*p=='_')
	{
		if(judge_var(p)==1)
		{
			strcat(ans,"variable");//判断是否为变量，此处补全下划线开头情况‘’‘’
			if(isthere==1)strcat(ans,"\n");
			else strcat(ans," ");
			return;
		}
	}
	else if(IsDigit(*p)==1)
	{
		if(processnum(p)==NULL){
			flag=1;
			return;
		}
		else {
			strcat(ans,processnum(p));
			
			if(isthere==1)strcat(ans,"\n");
			else strcat(ans," ");
			return;
		}
	}
	else if(opre(p)==1)
	{
		strcat(ans,"operator");
		if(isthere==1)strcat(ans,"\n");
		else strcat(ans," ");
		return;
	}
	  else flag=1;
	return;
}
int main(){
	char *s=malloc(409700*sizeof(char));
	ans=(char*)malloc(100005*sizeof(char));
	memset(ans,'\0',strlen(ans)+1);
	while (scanf("%s",s) != EOF) {				//process word by word
  		char *position = strchr(s, ';');   // if there's no ';' in s, it returns NULL.
  		if (position == NULL) //分两类处理，一类是含；，另一类不含
  				process(s);
  		else if(strcmp(s,";")==0)strcat(ans,"\n");
  		else  { *position='\0';
    			process(s);
    			strcat(ans,"\n");
    			int ha=0;
    			while(*(s+ha)!='\0')ha++;
    			ha++;
    			process(s+ha);
 			 }
 		free(s);
 		s=malloc(409700*sizeof(char));
	}
	if(flag==0)printf("%s",ans);//no compile error
 	else printf("Compile Error\n");
 	free(ans);//clear the useless place
 	return 0;
}