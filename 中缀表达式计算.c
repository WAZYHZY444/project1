//后缀(逆波兰表达式)表达式计算：从左往右扫描，先出栈的是右操作数  
//中缀转后缀：左优先

//前缀(波兰表达式)表达式计算：从右往左扫描，先出栈的是左操作数
//中缀转前缀：右优先

/*
中缀表达式转后缀表达式（机算）
初始化一个栈，用于保存暂时还不能确定运算顺序的运算符。
从左到右处理各个元素，直到末尾。可能遇到三种情况：
1.遇到操作数。直接加入后缀表达式。
2.遇到界限符。遇到"("直接入栈；遇到")"则依次弹出栈内运算符并加入后缀表达式，直到弹出"("为止。注意："("不加入后缀表达式。
3.遇到运算符。依次弹出栈中优先级高于或等于当前运算符的所有运算符，并加入后缀表达式，若碰到"("或栈空则停止。之后再把当前运算符入栈。
按上述方法处理完所有字符后，将栈中剩余运算符依次弹出，并加入后缀表达式。

后缀表达式的计算（机算） 
用栈实现后缀表达式的计算：
1.从左往右扫描下一个元素，直到处理完所有元素
2.若扫描到操作数则压入栈，并回到1，否则执行3
3.若扫描到运算符，则弹出两个栈顶元素，执行相应运算，运算结果压回栈顶，回到1

中缀表达式的计算（用栈实现） 
用栈实现中缀表达式的计算：
初始化两个栈，操作数栈和运符栈
若扫描到操作数，压入操作数栈
若扫描到运算符或界限符，则按照"中缀转后缀"相同的逻辑压入运算符栈（期间也会弹出运算符，每当弹出一个运算符时，就需要再弹出两个操作数栈的栈顶元素并执行相应运算，运算结果再压回操作数栈）
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

//运算符栈
typedef struct{
	char data[MAX_SIZE];
	int top;
}CharStack;

//操作数栈
typedef struct{
	int data[MAX_SIZE];
	int top;
}IntStack;

//运算符栈操作
void InitCharStack(CharStack* S)
{
	S->top=-1;
}
void pushCharStack(CharStack* S,char c)
{
	
	S->data[++S->top]=c;
}
char popCharStack(CharStack* S)
{
	return S->data[S->top--];
}
char GetTopcharStack(CharStack* S)    //为什么要查看运算符栈的栈顶元素
{     
	return S->data[S->top];
}
int isEmptyCharStack(CharStack* S)
{
	return S->top==-1;
}

//操作数栈操作
void InitIntStack(IntStack* S)
{
	S->top=-1;
}
void pushIntStack(IntStack* S,int value)
{
	
	S->data[++S->top]=value;
}
int popIntStack(IntStack* S)
{
	return S->data[S->top--];
}
int isEmptyIntStack(IntStack* S)
{
	return S->top==-1;
}

//运算符优先级
int Priority(char Operator)
{
	switch(Operator){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return 0;
	}
}

//执行计算
int Apply(int a,int b,char Operator)
{
	switch(Operator){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			if(b==0){
				printf("除数不能等于0\n");
				exit(1);     //立即终止程序的执行  exit(0)程序正常结束
			}
			return a/b;
		default:
			return 0;
	}
}

//中缀表达式计算
int Evaluate(char* expression)
{
	CharStack operators;    //声明一个运算符栈
	IntStack operands;       //声明一个操作数栈
	
	//初始化栈
	InitCharStack(&operators);
	InitIntStack(&operands);
	
	for(int i=0;expression[i]!='\0';i++){
		char c=expression[i];
		
		//1.数字
		if(isdigit(c)){                    //判断是否是十进制数字0~9
			int num=0;
			while(isdigit(expression[i])){  //处理操作数是多位数
				num=num*10+(expression[i]-'0');
				i++;
			}
			i--;                           //for循环会自增，while循环里也自增了，避免跳过
			pushIntStack(&operands,num);  //将字符转换成数字，压入操作数栈
		}
		//2.左括号
		else if(c=='('){
			pushCharStack(&operators,c);
		}
		//3.右括号
		else if(c==')'){
			//把)到(之间的所有运算符弹出栈
			while(!isEmptyCharStack(&operators)&&GetTopcharStack(&operators)!='('){
				char Operator=popCharStack(&operators);
				int b=popIntStack(&operands);     //先出栈的是右操作数 
				int a=popIntStack(&operands);
				pushIntStack(&operands,Apply(a,b,Operator));
			}
			popCharStack(&operators);    //弹出左括号
		}
		//4.运算符
		else if(c=='+'||c=='-'||c=='*'||c=='/'){
			//处理优先级更高的运算符
			while(!isEmptyCharStack(&operators)&&Priority(GetTopcharStack(&operators))>=Priority(c)&&GetTopcharStack(&operators)!='('){
				char Operator=popCharStack(&operators);
				int b=popIntStack(&operands); 
				int a=popIntStack(&operands);
				pushIntStack(&operands,Apply(a,b,Operator));
			}
			pushCharStack(&operators,c);  //把当前运算符压入栈中
		}
	}
	
	//处理剩余的运算符
	while(!isEmptyCharStack(&operators)){
		char Operator=popCharStack(&operators);
		int b=popIntStack(&operands); 
		int a=popIntStack(&operands);
		pushIntStack(&operands,Apply(a,b,Operator));
	}
	return popIntStack(&operands);
}

int main()
{
	char expression[]="3+4*2/(1-5)";
	int result=Evaluate(expression);
	printf("%s=%d\n",expression,result);
	return 0;
}