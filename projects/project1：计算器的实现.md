## project1：计算器的实现

#### 1.工作分块

+ ***词法分析器与存储词法段***

     + 函数token——>将各个字符存储到tokens字符串之中

     + 规则：

       >  bonus1:实现带有负数的算术表达式的求值（如何区分负数和减法）
       >
       >   bonus2:浮点数支持（使用union联合体类型，一次只用一个类型的值，如为浮点数自动覆盖）
       >
       >  1.变量 (variable)：由字⺟、数字、下划线组成，但不能以数字开头。
       >
       >  2.整数（integer）：由数字组成，不能含有前导 0（⽐如 002 ）。
       >
       >  3. 运算符（operator）： +, -, *, /, (, ), = 。
       >
       >  4. 浮点数（float）：由数字、⼩数点 '.' 和数字连接⽽成，其中前后的数字必须出现且合法，例如 3.2 和 0.03 都是合法的浮点数，⽽ 00.1 和 .233333 和 22. 均不是合法的浮点数。请注意这个定义，这和 C 语⾔中不同。
       >
       >     上⾯的定义已经保证，⼀个字符串最多可以被解释为⼀种合法的 token 。
       >
       >     

+ ***语法分析器***

     + 分出表达式expr的归纳定义：

       > <integer>⼀个数是表达式 | 
       >
       > <variable>⼀个变量也是表达式
       >
       >  "(" <expr> ")" #在表达式两边加个括号也是表达式 
       >
       >  <expr>  "+" <expr>  两个表达式相加也是表达式 
       >
       > "-"  # 接下来你全懂了 "*" "/" 

  + 使用BNF（即巴科斯范式）解析分析出来的词，这是描述上下文无关理论的一种具体方法---->BNF重要规则：优先级高的优先计算

  + expr的求值：——>建立一个递归函数eval(l,r)，边界是错误或者返回单个数字或者变量,l,r,分别是对应表达式左右下标
  + 附加一个报错和判断函数check_parentheses()正如字面意思，需要考虑括号的匹配与否问题，并且在求解表达式的时候需要把括号去除

  > eval(l,r){//main part
  >
  > if (l > r) {
  >
  > /*wrong*/
  >
  > }
  >
  > else if(l == r){
  >
  > /*single token **return** the value of a number or a variable*/
  >
  > }
  >
  > else if(check_parentheses(l,r) == 1){
  >
  > /*the expression is surrounded by a matched pair of  parentheses*/
  >
  > /*throw away*/
  >
  > }else 
  >
  > {
  >
  > operator = op()        /*calculate the main operator*/
  >
  > val1=eval(l,op-1);
  >
  > val2=eval(op+1,r);
  >
  > }
  >
  >  switch (op_type)
  >
  > }

+ ***赋值语句块***
          + 命名为assignment   ::=  <variable> "=" <expr>
          + 首先需要检验variable的合法性，合法之后存入一个名为assignment的结构体数组中去
          + 注：之后使用变量的值需要查找，所以建议用一个find
          + 总结来说，还要考虑a=b=c=d=1这种连续赋值类型，所以赋值语句也要有返回值

#### 2.数据结构概览

程序整体分为：输入、处理、输出

故可以考虑对程序进行重构，由于每一个输入都对应着输出（赋值除外）所以可以做一个struct存储输出，

> typedef struct value {
>
> enum {
>
> INT,
>
> FLOAT,
>
> ERROR
>
> }type;
>
> union {
>
> int iVal;
>
> double fVal;
>
> }val;
>
> }Value;



这样，我们在使⽤ eval() 函数的过程中就可以直接返回⼀个 type "' ERROR 的 Value ，⽐如

Value eval(l,r) {

if(l>r)return error;

}

并且为了支持负号，需要在eval中加入一个函数在优先级的最后加负号

(自己写)

>Value meetValue(Value v1, Value v2, Op op) 
>
>{
>
> if (v1.type == ERROR "&&v2.type == ERROR)
>
> { return ……}/*经过这一层代码现在 v1 和 v2 都不为 ERROR 了*/

> if (v1.type "+ v2.type) { 
>
> // 类型提升
>
>  }
>
>  switch (op) { ……}
>
> }

#### 总思路

scanf ("%s",……)输入，并且一次进行词法分析，存入结构体（全局）tokens,其中需要有union类型的值，方便类型转化,在输入的过程之中，要考虑error 首先存入答案