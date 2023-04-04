#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
  char name[50];
  struct node *father;
  struct node *nextnode[2];//二叉状的链表
}NODE;
NODE *FileRecv;
NODE *createNODE(char name[])
{
  NODE *node=(NODE*)malloc(sizeof(NODE));//定义普通节点并分配地址
  strcpy(node->name,name);
  node->father=NULL;
  node->nextnode[0] = NULL;
  node->nextnode[1]=NULL;//结束创建
  return node;
}
NODE *find(NODE *node,char s[])
{
  if(node==NULL)return NULL;//节点为空
  if(strcmp(node->name,s)==0)
    return node;
  NODE *a1=find(node->nextnode[0],s);
  NODE *a2=find(node->nextnode[1],s);
  return a1!=NULL?a1:a2;
}
int num(NODE *node)
{
  if(node==NULL)return 0;
  else return num(node->nextnode[0])+num(node->nextnode[1])+1;
}
void insert(NODE* Son,NODE* Father) {
  if(Father->nextnode[0]==NULL)Father->nextnode[0]=Son;
  else if(Father->nextnode[1]==NULL)Father->nextnode[1]=Son;
  Son->father=Father;
  return;
}
void delete(NODE *head)
{
  if(head==NULL)return;
  delete(head->nextnode[0]);
  delete(head->nextnode[1]);
  free(head);
}
int main()
{	int n,q;
  scanf("%d%d",&n,&q);
  FileRecv=createNODE("~~~");//建立链表,存储头
  for(int i=1;i<=n;i++)
  {	char a[10],b[10];
    scanf("%s%s",a,b);
    NODE *FATHER=find(FileRecv,b);
    insert(createNODE(a),FATHER);
    //printf("done!\n");
  }
  for(int i=1;i<=q;i++)
  {	char temp1[112],temp2[112];
    scanf("%s%s",temp1,temp2);
    if(strcmp(temp1,"query")==0)
    {
      NODE *ans=find(FileRecv,temp2);
      int answer=num(ans);
      printf("%d\n",answer);
    }
    else {
      NODE *place=find(FileRecv,temp2);
      NODE *a=place->father;
      if (a->nextnode[0]==place)
                  {
                        a->nextnode[0]= NULL;
                  }
                  else if (a->nextnode[1] ==place)
                  {
                        a->nextnode[1] = NULL;
                  }
       delete(place);
    }
  }
  return 0;
}
/*
4 6
a ~~~
bb a
cc a
ddd bb
query a
query ddd
remove ddd
query a
remove bb
query a
4 4
a ~~~
bb a
cc a
ddd bb
query a
query ddd 
remove ddd
query a
*/
//->father->nextnode[0]