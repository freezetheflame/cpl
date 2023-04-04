#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int p;
	scanf("%x",&p);
	printf("%d\n",p);
	printf("%u\n",p);
	float pp;
	memcpy(&pp,&p,sizeof(pp));
	printf("%.6f\n",pp);
	printf("%.4e\n",pp);
	return 0;
}