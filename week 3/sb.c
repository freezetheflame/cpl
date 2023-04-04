#include<stdio.h>


int main()
{
    int N,len,i,SUM;
    scanf("%d %d",&len,&N);
    char s[100];
    int a[100];
    SUM=0;
    
    for(i=len-1;i>=0;i--)
    {   
        scanf("%c",&s[i]);
        if(48<=s[i]&&s[i]<=57)
        {
            a[i]=s[i]-48;
        }
        else if(s[i]>=65)
        {a[i]=s[i]-55;}
    }
    
    for(i=0;i<=len-1;i++)
    {
        if(a[i]>=N)
        {
          printf("Error");
          return 0;      
        }
        else 
        {
            SUM=(a[i]+SUM)*N;
        }
        
    }
     
     printf("%d",SUM);



    return 0;
}