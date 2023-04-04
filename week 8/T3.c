#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char *p=malloc(4500*sizeof(char));
	while(scanf("%s",p)==1&&*p!="\n")
	{	int len=strlen(p);
		if(*p<='z'&&*p>='a'){
			*p=*p-32;			
		}printf("%c",*p);
		for(int i=1;i<=len-1;i++){
			if(*(p+i)>='A'&&*(p+i)<='Z')*(p+i)=*(p+i)+32;
			printf("%c",*(p+i));
		}
		printf(" ");		
	}
	//free(p);
	return 0;
}