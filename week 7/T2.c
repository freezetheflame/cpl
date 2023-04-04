/*
循环实现的题目，则分块考虑，且由于其定性特征，for实现会更加合理（while或许也适合哈，但是这里
边界应该都可以求出来的,需要仔细分析空格、斜边、直边之间的关系，并且把侧面的影响分化到每一行，
比如，顶面的奇数行，考虑侧面的‘+’与‘ ’
现在考虑没有中间部位的情况，我们简化成三块，一个是2c+1>i时候一直打印到最左边，数量为a+b-空格
数目，持续2c+1行，都是|结尾另一个就是高度不够了，且顶面没有结束只打印c组，持续2b-1行，最后一
行收尾，中间考虑奇数偶数

*/
#include<stdio.h>
void PrintSquare(int a,int b,int c)
{	if(c>=b)
	{
	for(int i=1;i<=2*b+1;i++)
	{
		for(int j=2*b+1-i;j>0;j--)
			printf(" ");
		if(i%2==1)
		{
			int Temporary=a,Instant=1;
			while(Temporary>=1)//和for 效果一样，但仅仅是用于计数罢了
			{
				printf("+-");
				Temporary--;
			}
			while(i/2+1-Instant>=0)
			{
				printf("+ ");
				Instant++;
			}
			printf("\n");
		}
		else {
			int Temporary=a,Instant=1;
			while(Temporary>=1)
			{
					printf("/ ");
					Temporary--;
			}
			while(i/2-Instant>=0)
			{
				printf("/|");
				Instant++;
			}
			printf("\n");
		}
	}//头，含最后一行
for(int i=1;i<=2*(c-b);i++)
	{
		if(i%2==0)
		{
			int Temporary=a,Instant=b;
			while(Temporary>=1)//和for 效果一样，但仅仅是用于计数罢了
			{
				printf("+-");
				Temporary--;
			}
			while(Instant>=1)
			{
				printf("+ ");
				Instant--;
			}
			printf("+");
			printf("\n");
		}
		else {
			int Temporary=a,Instant=b;
			while(Temporary>=1)
			{
					printf("| ");
					Temporary--;
			}
			printf("|");
			while(Instant>=1)
			{
				printf("/|");
				Instant--;
			}
			printf("\n");
		}
	}//中间部位
for(int i=1;i<=2*b;i++)
	{
		if(i%2==0)
		{
			int Temporary=a,Instant=b-i/2+1;
			while(Temporary>=1)//和for 效果一样，但仅仅是用于计数罢了
			{
				printf("+-");
				Temporary--;
			}
			while(Instant>=1)
			{
				printf("+ ");
				Instant--;
			}
			printf("\n");
		}
		else {
			int Temporary=a,Instant=b-i/2;
			while(Temporary>=1)
			{
					printf("| ");
					Temporary--;
			}
			while(Instant>=1)
			{
				printf("|/");
				Instant--;
			}
			printf("\n");
		}
	}
	}
else { 
	for(int i=1;i<=2*(b+c)+1;i++)
	{	if(i<=2*b)
		for(int j=2*b+1-i;j>0;j--)
			printf(" ");
		int Space=2*b+1-i;
		if(i%2==1)
		{
		int Temporary=a;
		while(Temporary>=1)//和for 效果一样，但仅仅是用于计数罢了
			{
				printf("+-");
				Temporary--;
			}
		if(2*c+1>=i){
			for(int j=(i-1)/2+1;j>0;j--)
			printf("+ ");
			}
		else if(i<=2*b+1)
		{
			for(int j=c;j>=0;j--)
				printf("+ ");
		}
		else {
			for(int j=c+Space/2;j>=1;j--)
				printf("+ ");
			printf("+");
		}
		printf("\n");
		}
		else
		{
			int Temporary=a,Instant=b;

			if(2*b>=i){
			while(Temporary>=1)
			{
					printf("/ ");
					Temporary--;
			}
		}else while(Temporary>=1)
		    {
			 printf("| ");
			Temporary--;
			 }
			
			if(2*c>=i)
			{
				for(int j=1;j<=i/2;j++)
					printf("/|");
				/*if(2*b<=i)
				printf("/");
			    else printf("|"); */
			}
			else if(i<=2*b)
			{
				for(int j=1;j<=c;j++)
					printf("/|");
				if(2*b>=i)
				printf("/");
			    else printf("|"); 
			}
			else {if(2*b>=i)
				{
				for(int j=c+Space/2+1;j>=2;j--)
					printf("/|");
				printf("/");
			}
				else {for(int j=c+Space/2+1;j>=2;j--)
					printf("|/");
					} 
			}

			printf("\n");
		 
		}

		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int sb=1;sb<=n;sb++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		PrintSquare(a,b,c);
	}
	return 0;
}
/*
              +-+-+-+-+-+-+-+
             / / / / / / / /|
            +-+-+-+-+-+-+-+ +
           / / / / / / / /|/|
          +-+-+-+-+-+-+-+ + +
         / / / / / / / /|/|/
        +-+-+-+-+-+-+-+ + + 
       / / / / / / / /|/|/
      +-+-+-+-+-+-+-+ + +
     / / / / / / / /|/|/
    +-+-+-+-+-+-+-+ + +
   / / / / / / / /|/|/
  +-+-+-+-+-+-+-+ + +
 / / / / / / / /|/|/
+-+-+-+-+-+-+-+ + +
| | | | | | | |/|/
+-+-+-+-+-+-+-+ +
| | | | | | | |/
+-+-+-+-+-+-+-+
    +-+-+-+-+-+-+
   / / / / / / /|
  +-+-+-+-+-+-+ +
 / / / / / / /|/
+-+-+-+-+-+-+ +
| | | | | | |/
+-+-+-+-+-+-+
*/