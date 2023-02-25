#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define N 1000005
int hash(char *s){//哈希运算
  int len=strlen(s);
  int ret=0;
  for(int i=0;i<len;i++)ret=(ret+s[i]*(i+1))%N;
  return ret;
}

typedef struct node{
  char *s;
  struct node *nextnode;
}NODE;//建立哈希链表
NODE *a[N];//初始化一张哈希数组，每个数组元素都是一个链表头的指针
NODE *findspace(NODE *head){
  if(head->nextnode!=NULL)
    head=findspace(head->nextnode);
  return head;
}//找到这张链表的尾巴以创立新节点
NODE *createROOT(char s[])//根据这个字符串创造根节点
{
  NODE *A=malloc(sizeof(NODE));
  A->nextnode=NULL;//尾巴还是空节点
  A->s=malloc((strlen(s)+5)*sizeof(char));
  strcpy(A->s,s);//把新的字符抄进去
  return A;//返回节点所在地址
}
int find(char st[]){//用来找需要的字符，先hash看看有没有，再顺着链表找重复的
  int flag=0;
  NODE *i=a[hash(st)];
  if(strcmp(i->s,st)==0)return 1;//如果表头就是迅速返回
  for(;i!=NULL;i=i->nextnode)
  {
    if(strcmp(i->s,st)==0)return 1;
  }
  return flag;
}
void create(NODE *p,char *s)
{
  if(find(s))
    return;
  NODE *in=malloc(sizeof(NODE));
  in->s=malloc((strlen(s)+5)*sizeof(char));
  strcpy(in->s,s);
  NODE *cut=findspace(p);
  in->nextnode=NULL;
  cut->nextnode=in;
  return;
}//在一个链表后面添加节点

int main(){
  int m,q;
  scanf("%d%d",&m,&q);
  char *stringl;
  for(int i=1;i<=m;i++)
  {
    stringl=malloc(1000*sizeof(char));
    scanf("%s",stringl);
    int place=hash(stringl);
    if(a[place]==NULL)
      a[place]=createROOT(stringl);//该哈希值暂未使用过，故创造新的根结点
    else  create(a[place],stringl);//有使用过就在后面加一个节点
    free(stringl);
  }
  char *st;
  for(int i=1;i<=q;i++)
  {
    st=malloc(1000*sizeof(char));
    scanf("%s",st);
    int ans=hash(st);
    if(a[ans]==NULL)
        printf("No\n");
    else {	
    if(strcmp(a[ans]->s,st)==0)printf("Yes\n");
    	else if(find(st))printf("Yes\n");
      else printf("No\n");
    }
    free(st);
  }
  return 0;
}