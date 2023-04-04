#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char *S=malloc(100005*sizeof(char));
	char *T=malloc(100005*sizeof(char));
	//int *much=malloc(100*sizeof(int)),count=0;
	scanf("%s%s",S,T);
	int len1=strlen(S),len2=strlen(T);
	for(int k=0;k<=len1-1;k++){
		int m=k,j=0;
		while(*(S+m)==*(T+j)&&m<=len1-1&&j<=len2-1){
			j++;m++;
			//printf("s%d%ds",j,m);
		}
		if(j==len2)
			printf("%d ",k);			
	}
	return 0;
}