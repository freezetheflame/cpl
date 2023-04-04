#include<stdio.h>
int main()
{
    int n,num,space=0,h=0,max;
    char str[1001]={0};
    int counter[1001]={0};

    scanf("%d",&n);
    scanf("%s",str);

    for(int i=0;i<n;i++)
    {
        num=str[i];
        counter[num]++;
    }
    max=counter[65];
    
    for(int i=65;i<123;i++)
    {
        if(max<counter[i])
        max=counter[i];//计算最高频的字母
    }
    for(int j=max;j>0;j--)
    {

        for(int i=65;i<91;i++)
        {
            if(counter[i]!=0 && counter[i+32]!=0)//大小写都有
            {   if (counter[i+32]>=j )printf("=");//①小写可以
                else printf(" ");//②小写不行
                if (counter[i]>=j)printf("=");//③大写可以
                else printf(" ");//④大写不行
                printf(" ");
            }
            if(counter[i]!=0 && counter[i+32]==0)//小写没有
            {   
                if (counter[i]>=j )printf("=");//⑤大写可以
                else printf(" ");//⑥大写不行
                printf(" ");
            }
            if(counter[i]==0 && counter[i+32]!=0)//大写没有
            {
                if (counter[i+32]>=j)printf("=");//⑦小写可以
                else printf(" ");//⑧小写不行
                printf(" ");
            }
            //⑨即全不行的情况
        }
        printf("\n");
    }
    for(int i=65;i<123;i++)
    {
        if(counter[i]>0)
        {
            h=h+counter[i]-1;
        }
    }
    for (int b=65;b<91;b++)
    {
        if (counter[b]!=0 && counter[b+32]!=0)
        {
            space++;
        }
    }
    int t=2*(n-h)-space-1;

    for(int i=0;i<t;i++)
    {
        printf("-");
    }
    printf("\n");
    for(int i=65;i<91;i++)
    {
        if(counter[i]!=0 && counter[i+32]!=0)//①大小写都有
        {
            printf("%c%c ",i+32,i);//输出==‘ ’
        }
        if(counter[i]!=0 && counter[i+32]==0)
        {
            printf("%c ",i);
        }
        if(counter[i]==0 && counter[i+32]!=0)
        {
            printf("%c ",i+32);
        }
     
        
    }
    return 0;

}