#include<stdio.h>
int crime[100005];
int find(int x){
   if(crime[x]==x){
   	return x;
   }
   else{
     return find(crime[x]);
  }
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&crime[i]);
	for(int i=1;i<=n;i++)
		{
			crime[i]=find(i);
			printf("%d ",crime[i]);
		}
	return 0;

}