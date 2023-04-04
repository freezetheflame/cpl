#include<stdio.h>
#include<string.h>
char life[1005],cp[1005];
int main(){
	int n,flag=0,len;
	scanf("%d",&n);
	scanf("%s",life);
	len=strlen(life);    
    strncpy(cp,life,len);
    life[0]='.';
    life[1]='.';
    life[2]='.';
    for(int i=3;i<=len+2;i++)
    	life[i]=cp[i-3];
    strncpy(cp,life,len+3);
	for(int i=1;i<=n;i++)
	{  
		if(!flag)
		{
			for(int j=3;j<=len+2;j++)
		    {    if(life[j]=='.')
				{	
					int num1=0,num2=0;
					for(int m=j-3;m<=j+3;m++)
						{
							if(life[m]=='A')num1++;
							if(life[m]=='B')num2++;
						}
					if((num1>=2)&&(num1<=4)&&(num2==0))cp[j]='A';
					else if((num2>=2)&&(num2<=4)&&(num1==0))cp[j]='B';
					else cp[j]='.';

				}
				else if(life[j]=='A'){
					int num1=0,num2=0;
					for(int m=j-3;m<=j+3;m++)
						{
							if(life[m]=='A')num1++;
							if(life[m]=='B')num2++;
						}
					if((num2>0)||(num1>=6)||(num1<=2))cp[j]='.';
					else cp[j]='A';
				}
				else if(life[j]=='B'){
					int num1=0,num2=0;
					for(int m=j-3;m<=j+3;m++)
						{
							if(life[m]=='A')num1++;
							if(life[m]=='B')num2++;
						}
					if(num1>0||num2>=6||num2<=2)cp[j]='.';
				    else cp[j]='B';
				}
			}flag=1;
		}
	    else 
			{for(int j=3;j<=len+2;j++)
			{    
				if(cp[j]=='.')
				{	
					int num1=0,num2=0;
					for(int m=j-3;m<=j+3;m++)
						{
							if(cp[m]=='A')num1++;
							if(cp[m]=='B')num2++;
						}
					if((num1>=2)&&(num1<=4)&&(num2==0))life[j]='A';
					else if(num2>=2&&num2<=4&&num1==0)life[j]='B';
					else life[j]='.';
				}
				 else if(cp[j]=='A'){

					int num1=0,num2=0;
					for(int m=j-3;m<=j+3;m++)
						{
							if(cp[m]=='A')num1++;
							if(cp[m]=='B')num2++;
						}
					if(num2>0||num1>=6||(num1<=2))life[j]='.';
					else life[j]='A';
				    
				}
				else if(cp[j]=='B'){
					int num1=0,num2=0;
					for(int m=j-3;m<=j+3;m++)
						{
							if(cp[m]=='A')num1++;
							if(cp[m]=='B')num2++;
						}
					if(num1>0||num2>=6||num2<=2)life[j]='.';
					else life[j]='B';
				    
				}
			}flag=0;
	}
	}
	if(flag)
		{
			for(int i=3;i<=len+2;i++)
			printf("%c",cp[i]);
	}
	else {
			for(int i=3;i<=len+2;i++)
			printf("%c",life[i]);
		}

}