#include<stdio.h>
int main(){
	int a[10][10] = {0};
	for(int i=1;i<=9;i++)//i是行，j是列
		for(int j=1;j<=9;j++)
		{   scanf("%d",&a[i][j]);
		    if(a[i][j]>9||a[i][j]<1){
				printf("NO");
				return 0;
			}
		}
	for(int i=1;i<=9;i++){
	//i是行，j是列
		int pan[10]={0};
		for(int j=1;j<=9;j++)
		{
			pan[a[i][j]]++;
			if(pan[a[i][j]]>=2){
				printf("NO");
				return 0;
			}
		}
	}	
	for(int j=1;j<=9;j++){
	//i是行，j是列
		int pan[10]={0};
		for(int i=1;i<=9;i++)
		{
			pan[a[i][j]]+=1;
			if(pan[a[i][j]]>=2){
				printf("NO");
				return 0;
			}
		}
	}
	for(int m=1;m<=7;m+=3)
	    {
	    	
	    	for(int n=1;n<=7;n+=3)
	    	{	int pan[10]={0};
	    		pan[a[m][n]]++; pan[a[m][n+1]]++; pan[a[m][n+2]]++;
	    		pan[a[m+1][n]]++; pan[a[m+1][n+1]]++; pan[a[m+1][n+2]]++;
	    		pan[a[m+2][n]]++; pan[a[m+2][n+1]]++; pan[a[m+2][n+2]]++;
	    		for(int i=1;i<=9;i++)
	    		{   
	    			if(pan[i]>1){
	    				printf("NO");
	    				return 0;
	    			}
	    		}
	    	}
	    }	
	printf("YES");
	return 0;
}