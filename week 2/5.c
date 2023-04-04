#include<stdio.h>
#include<math.h>
int main(){
	int x,y,fx,fy,sbx,sby,posx,posy;
	scanf("%d%d%d%d%d%d",&x,&y,&fx,&fy,&sbx,&sby);
	int sum=0;
	posx=x;posy=y;
	char mov[4]={'U','D','L','R'};
	if(x!=fx&&y!=fy)
	{
		sum=abs(x-fx)+abs(y-fy);
		printf("%d\n",sum);
		if(x==sbx) {
			for(int i=1;i<=abs(x-fx);i++){
				if(x<fx)printf("%c",mov[3]);
				else printf("%c",mov[2]);
			}
			for(int i=1;i<=abs(y-fy);i++){
				if(y<fy)printf("%c",mov[0]);
				else printf("%c",mov[1]);
			}
		}
		else if(y==sby){
			for(int i=1;i<=abs(y-fy);i++){
				if(y<fy)printf("%c",mov[0]);
				else printf("%c",mov[1]);
			}
			for(int i=1;i<=abs(x-fx);i++){
				if(x<fx)printf("%c",mov[3]);
				else printf("%c",mov[2]);
			}
		}
		if(fx!=sbx&&fy!=sby){
			for(int i=1;i<=abs(x-fx);i++){
				if(x<fx)printf("%c",mov[3]);
				else printf("%c",mov[2]);
			}
			for(int i=1;i<=abs(y-fy);i++){
				if(y<fy)printf("%c",mov[0]);
				else printf("%c",mov[1]);
			}

		}
		else if(fx==sbx){for(int i=1;i<=abs(y-fy);i++){
				if(y<fy)printf("%c",mov[0]);
				else printf("%c",mov[1]);
			}for(int i=1;i<=abs(x-fx);i++){
				if(x<fx)printf("%c",mov[3]);
				else printf("%c",mov[2]);
			}}
			else if(fy==sby){for(int i=1;i<=abs(x-fx);i++){
				if(x<fx)printf("%c",mov[3]);
				else printf("%c",mov[2]);
			}
		for(int i=1;i<=abs(y-fy);i++){
				if(y<fy)printf("%c",mov[0]);
				else printf("%c",mov[1]);
			}
		}
	}

	if(y == fy &&y == sby)
	{   if((fx<x&&x<sbx)||(fx>x&&x>sbx)||(fx<x&&sbx<fx)||(fx>x&&sbx>fx)){
		sum= abs(x-fx+y-fy);printf("%d\n",sum);
		for(int i=1;i<=sum;i++){if(fx>x)printf("%c",mov[3]);
	                             else printf("%c",mov[2]);}
	    return 0;
	}
		sum = abs(x-fx+y-fy) + 2;
		if(posx<fx){
			printf("%d\n%c",sum,mov[0]);
			for(int i=1;i<=abs(x-fx+y-fy);i++)
				printf("%c",mov[3]);
			printf("%c",mov[1]);
	}
	else {printf("%d\n%c",sum,mov[0]);
			for(int i=1;i<=abs(x-fx+y-fy);i++)
				printf("%c",mov[2]);
			printf("%c",mov[1]);
		}}
	if(x == fx &&x == sbx)
	{ if((fy<y&&y<sby)||(fy>y&&y>sby)||(fy<y&&sby<fy)||(fy>y&&sby>fy)){
		sum= abs(x-fx+y-fy);printf("%d\n",sum);
		for(int i=1;i<=sum;i++){if(fy>y)printf("%c",mov[0]);
	                             else printf("%c",mov[1]);}
	     return 0;
	}
		sum = abs(x-fx+y-fy) + 2;
		if(posy<fy){
			printf("%d\n%c",sum,mov[3]);
			for(int i=1;i<=abs(x-fx+y-fy);i++)
				printf("%c",mov[0]);
			printf("%c",mov[2]);
	}
	else {printf("%d\n%c",sum,mov[3]);
			for(int i=1;i<=abs(x-fx+y-fy);i++)
				printf("%c",mov[1]);
			printf("%c",mov[2]);
		}

}
if(x==fx&&sbx!=x){
		sum= abs(x-fx+y-fy);printf("%d\n",sum);
		for(int i=1;i<=sum;i++){if(fy>y)printf("%c",mov[0]);
	                             else printf("%c",mov[1]);}
	     return 0;
	}
if(y==fy&&y!=sby){
		sum= abs(x-fx+y-fy);printf("%d\n",sum);
		for(int i=1;i<=sum;i++){if(fx>x)printf("%c",mov[3]);
	                             else printf("%c",mov[2]);}
	                     }

		return 0; 			
	}
