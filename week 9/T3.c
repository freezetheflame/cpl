#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int flag2;
int main(){					//strchr(s, *(p))search
	char *s=malloc(1029*sizeof(char));
	char temp,k;
	scanf("%s",s);
	int argument=0;
	int len=strlen(s);
	char *p=malloc(1029*sizeof(char));
	char *ans=malloc(10290*sizeof(char));
	memset(ans,'\0',strlen(ans));
	char *name=malloc(1029*sizeof(char));
	scanf("%s",name);
	strcat(ans,name);
	strcat(ans,"\n");
	while(scanf("%s",p)!=EOF)
	{
		if(argument==0){      //第一种情况，不是待输入参数，直接判断是否为2,3
			int lenth=strlen(p);
			if(*p=='-'){			//参数情况，不是就无视
				char *position=strchr(s,*(p+1));
				if(position==NULL){
					flag2=1;
					k=*(p+1);
					printf("%s: invalid option -- '%c'",name,k);
					return 0;
				}
				if(*(position+1)==':'){
					argument=1;
					temp=*position;				//准备拿参数
					strcat(ans,p+1);
					strcat(ans,"=");
				}else {
					strcat(ans,p+1);
					strcat(ans,"\n");   
				}

			}
			
			}
			else {
				strcat(ans,p);
				strcat(ans,"\n");
				argument=0;
		}
         free(p);
         p=malloc(1029*sizeof(char));
	}
	if(argument==1)
	{
		printf("%s: option requires an argument -- '%c'",name,temp);
		return 0;
	}	
	else printf("%s",ans);
	free(ans);free(p);
	return 0;
}