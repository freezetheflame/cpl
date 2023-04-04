/*
calculater
注：所有Value里面，即答案里面的type都被修改为type
几个重要的结构体和枚举类：op存有(oper)的位置信息，并不需要那么多
Type表示expr类型，整数、浮点、运算符、变量分别为1.2.3.4
tokens用Type类型存储expr类型，用字符串存储内容
Value结构体所创造的ans存储答案(union类型)以及答案的格式，含有error报告
value结构用于存储中间值以及变量，结构体成员包括tqype(enum)和val(union,ival和fval)
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>
int length;
enum Type{
   integer=1,floating=2,operator=3,variable=4//提高代码可读性但是别人可能意识不到（
};
typedef struct value //value里面两个内容，一个是type，一个是val
{
	enum {
	  INT,
	  FLOAT,
	  ERROR
	}type;
	union
	{
		int iVal;
		double fVal;
	}val;
}Value;
Value error;
int IsLetter(char ch) //checked
{ 		//判断是否为字母
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))return 1;
	else return 0;
}
int IsDigit(char ch)  //checked
{			//判断是否为数字
	if (ch >= '0'&&ch <= '9') return 1;
	else return 0;
}
int judge_var(char p[])
{
	int len=strlen(p);
	for(int i=1;i<=len-1;i++)
	{
		if(IsLetter(p[i])==0&&p[i]!='_'&&IsDigit(p[i])==0)
			return 0;
	}
	return 1;
}
int processnum(char num[]){
    if(strlen(num)==1&&num[0]=='0')return 1;
    int len=strlen(num);
    int count=0,place;
    for(int i=1;i<=len-1;i++)
    {
        if(IsDigit(num[i])==0&&num[i]!='.')return 0;
        if(*(num+i)=='.')
            {
                count++;
                place=i;
            }
        if(count>1)return 0;
    }
    if(count==1){
        if(num[0]=='0')
        {
            if(num[1]=='.'&&num[place+1]!='\0')return 2;
            else return 0;
        }
        else if(num[place+1]=='\0')return 0;
        else return 2;
    }
    else if(num[0]!='0'&&count==0)return 1;//无小数点，那么只要满足第一位不是0就行
}
int type_analysis(char s[]){
	if(IsLetter(s[0])==1||s[0]=='_')//字母、下划线开头的情况只可能是变量
	{
		if(judge_var(s)==1)return variable;
		else return 0;
	}
	else if(IsDigit(s[0])==1)//数字开头必是两种数字
	{
		if(processnum(s)==1)return integer;
		else if(processnum(s)==2)return floating;
		else return 0;
	}
	else if(strlen(s)==1&&(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'||s[0]=='='||s[0]=='('||s[0]==')'))
	{
		return operator;
	}
	else return 0;
} 
typedef struct token{
	enum Type type;//类型，错误就直接寄
	char val[32];
}Token;
Token tokens[10008];
int find_equal(int l,int r)
{
	for(int i=l;i<=r;i++) {
    if(tokens[i].val[0]=='=')return i;
  }
  return 0;
}
typedef struct assignment{
	char name[32];
	Value value;
}Ass;
//int total;
Ass assign[10005];//统一存储所有的赋值内容
int assignlen=1;
//int num[12500];不可行，只能现存
Value find_variable(char s[])
{
	for(int i=1;i<=assignlen;i++)
	{
		if(strcmp(s,assign[i].name)==0)
			return assign[i].value;
	}
	return error;
}
char *total;
int seek_op(int l,int r)//key：要忽略一切括号内的事务，所以处理方式近似于匹配括号
//utilize it to 'search' the main operator(=,+,-,*/)(solved)
{	
	int i=l;
	int top=0;
	int flag=0,num=0;//flag标记前面有没有可以操作的数字或者变量，避开负号
	for(i=l;i<=r;i++){
		
		if(tokens[i].type!=operator)
		{	flag=1;
			continue;
		}
		char c=tokens[i].val[0];
		if(c=='(')top++;
		if(c==')')
			{	if(top==0)return 0;//报错
				top--;flag=1;//前面的数字形成一个体系
			}			
		if(top!=0)continue;
		if(c!='+'&&c!='-'&&c!='*'&&c!='/')continue;//还有左括号且尚未出现运算符，所以继续清理括号
		else if(c=='+'||(c=='-'&&flag))
		//保证不是负号而是减号，右侧优先
		{		
				num=i;
		}
		else if((c=='*'||c=='/')&&(num==0||tokens[num].val[0]=='*'||tokens[num].val[0]=='/'))num=i;
		flag=0;//前面是符号，可能是负号
	}
	if (top!=0)return 0;
	return num;
}	

int check_minus(int l,int r)//(solved)用于抉择“表面”有无负号，并且需要补充判断
{	int i=l,flag=1,top=0;//flag为记录可以是负号状态
	if(tokens[l].val[0]!='-')return 0;//第一位不是负号
	for(i=l;i<=r;i++) {
    if(tokens[i].type!=operator){
      flag=0;//不是运算符，那么就是可操作的数字，就不能有负号（暂时）
      continue;
    }
    char c=tokens[i].val[0];
    if(c=='(')top++;
    if(c==')')
    {
      if (top==0)return 0;
      top--;
      flag=0;
    }
    if(top!=0)continue;
    if(c!='+'&&c!='-'&&c!='*'&&c!='/')continue;//还在清理括号中
	 else if(c=='+'||c=='*'||c=='/')return 0;
	else if(c=='-'&&!flag)return 0;//
		flag=1;//遇到符号，可能是负号
	}
  return 1;

	//(solved)
}
void reload_assign(char name[],Value ass)//存储变量
{
	
	int flag=0;//先找一下有没有用过
	for(int i=1;i<=assignlen;i++)
	{
		if(strcmp(name,assign[i].name)==0){
      flag=1;
      assign[i].value=ass;//更新数值
      break;
    }
	}
	if(flag==0)
	{
		strcpy(assign[assignlen].name,name);
		assign[assignlen].value=ass;
		assignlen++;
   }
   
   return;
}
Value check_assign(char name[])//赋值过返回，没有返回;
{
	int flag=0;//找一下有没有赋值
	for(int i=1;i<=assignlen;i++)
	{
		if(strcmp(name,assign[i].name)==0){
      return assign[i].value;
    }
	}
	return error;
}
int check_parentheses(int l,int r)//确认两端有无合适括号组（必须是一组不能是两个分离的）
{
	int top=0,i=l,flag=0;
	char c1=tokens[l].val[0],c2=tokens[r].val[0];
	if((c1!='('||tokens[l].type!=operator)||(c2!=')'||tokens[r].type!=operator))return 0;//两端无括号
	for(i=l;i<=r;i++)
	{
		if(tokens[i].val[0]=='(')top++;
		if(tokens[i].val[0]==')'){
			if(top==1&&i!=r)return 0;//两头不是一个括号组
			if(top==0)return 0;//不匹配
			top--;			
		}
	}
	if(top!=0)return 0;
	else return 1;
}
int match_parentheses(int l,int r)//括号匹配问题
{	int top=0;
	for(int i=l;i<=r;i++)
	{	
		if(tokens[i].val[0]=='(')top++;
		else if(tokens[i].val[0]==')')
		{
			if(top==0)return 0;//不匹配
			     top--;			
		}
	}
	if(top>0)return 0;
	else return 1;
}
Value meetValue(Value v1,Value v2,int op)//done
//表示一个表达式的值，无论数据类型，无论expr有无error都可以操作
{ 
	char c=tokens[op].val[0];
	if(c=='=')return error;
   if (v1.type==ERROR||v2.type==ERROR) {
    return error;
    } 
    if(v1.type!=v2.type){
        if(v1.type==FLOAT){
            v2.val.fVal=(double)v2.val.iVal;
            v2.type=FLOAT;
        }else{
            v1.val.fVal=(double)v1.val.iVal;
            v1.type=FLOAT;//类型提升
        }       
    }
    Value v3;
    if(v1.type==INT)
    { v3.type=INT;
    //if(c=='/'&&v2.val.iVal==0)return error;
    switch (c){
    case '+': v3.val.iVal=v1.val.iVal+v2.val.iVal;return v3;
   case '-': v3.val.iVal=v1.val.iVal-v2.val.iVal;return v3;
   case '*': v3.val.iVal=v1.val.iVal*v2.val.iVal;return v3;
   case '/': v3.val.iVal=v1.val.iVal/v2.val.iVal;return v3;
   default : return error;
    }
        }
        else {v3.type=FLOAT;
       // if(c=='/'&&v2.val.fVal==0)return error;
    switch (c){
    case '+': v3.val.fVal=v1.val.fVal+v2.val.fVal;return v3;
   case '-': v3.val.fVal=v1.val.fVal-v2.val.fVal;return v3;
   case '*': v3.val.fVal=v1.val.fVal*v2.val.fVal;return v3;
   case '/': v3.val.fVal=v1.val.fVal/v2.val.fVal;return v3;
   default : return error;
    }
        }
}

//得到的是Value类型的
Value oppsite(Value needed)//注意参数传递(done)
{	
	Value temp=needed;
	if(needed.type==ERROR)return error;
	else if(needed.type==FLOAT){
		temp.type=FLOAT;temp.val.fVal=-needed.val.fVal;return temp;
	}
	else {
		temp.type=INT;temp.val.iVal=-needed.val.iVal;return temp;
	}
}
Value num(Token numm)
{
	Value v3;
	if(numm.type==integer)v3.type=INT;
	else v3.type=FLOAT;
	if(v3.type==FLOAT){
		sscanf(numm.val,"%lf",&v3.val.fVal);
       }
	else if(v3.type==INT)sscanf(numm.val,"%d",&v3.val.iVal);
	else return error;
	return v3;
}
Value getval(Token required)//根据它是变量还是数字取值
{
	if(required.type==variable)return find_variable(required.val);
		else return num(required);
}
Value eval(int l,int r)//solved
{			
if(l>r)return error;
if(find_equal(l,r)!=0)return error;
if(match_parentheses(l,r)==0)
{
return error;//括号不匹配
}
else if(l == r){//当只剩下一个元素，如果是变量或者数
	if(tokens[l].type==operator)return error;//寄
		return getval(tokens[l]);//求得这个变量或者数的值
}
else if(check_parentheses(l,r)==1){
			return eval(l+1,r-1);//直接去除括号
}
else if(check_minus(l,r)==1)//是否存在前置的负号（群）
{	//printf("qufuhao");		
	return oppsite(eval(l+1,r));//可以递归去除负号,并且得到一个负val的value结构体
}
else{
int opposition = seek_op(l,r);   /*calculate the main operator*/
if(opposition==0)return error;         //op寻找不到就返回错误
Value val1,val2;						//根据高优先级的运算符分块
val1=eval(l,opposition-1);
val2=eval(opposition+1,r);
return meetValue(val1,val2,opposition);
	}

}
void printValue(Value answer)
{	
	switch(answer.type)
	{
	case INT:printf("%d\n",answer.val.iVal);break;
	case FLOAT:printf("%.6lf\n",answer.val.fVal);break;
	case ERROR:printf("Error\n");break;
	default:assert(0);
	}
	return;
}
Value process(int l,int r)//赋值语句的处理，第一个等号必须在第二位
{	
	int place=find_equal(l,r);
	if(l>r)return error;
	if(place==0) {
		return eval(l,r);
	}
	if(place!=l+1||tokens[l].type!=variable)//一个如上所言，另一个指的是左半边不是变量
		return error;
	Value v3=process(place+1,r);
	if(v3.type!=ERROR)
		reload_assign(tokens[l].val,v3);
	return v3;
}

int main()
{
	error.type=ERROR;//创建一个error类型的Value结构体用于函数返回
	total=malloc(1024*sizeof(char));
	while(gets(total)!=NULL)
{  char *p=total;
   int flagg=0;  
	int j=1;
		while(*total!='\0')
		{	
			int ii=0;
			while(*total!=' '&&*total!='\0')
			{		tokens[j].val[ii++]=*total;
					total++;
			}
			tokens[j].val[ii]='\0';
			if(*total!='\0')total++;
			j++;
	   } 
	  	for(int i=1;i<j;i++)
	  	{	
		int k=type_analysis(tokens[i].val);
		if( k!= 0)
			tokens[i].type=k;
		else {
			flagg=1;
	}
}
	if(flagg==1)
	{
		printf("Error\n");
	}
	//因此此时j-1就是句长
	else {
		length=j-1;
	   printValue(process(1,length));
	}
	    total=p;
	    free(total);
	    total=malloc(1026*sizeof(char));
	 
	}
	

	return 0;

}
//( 2 + 3 ) * ( 3 - 2 )
//( 1 + 2 ) - ( 3 * 4 ) )
//( - 4 + 5 ) * 4 - - ( 9 - - 5 )