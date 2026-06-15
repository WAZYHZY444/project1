#include <iostream>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

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
int Evaluate(const string &expression)
{
	stack<char> operators;    //声明一个运算符栈
	stack<int> operands;       //声明一个操作数栈
	
	for(int i=0;i<expression.length();i++){
		char c=expression[i];
		
		//1.数字
		if(isdigit(c)){                    //判断是否是十进制数字0~9
			int num=0;
			while(i<expression.length()&&isdigit(expression[i])){  //处理操作数是多位数
				num=num*10+(expression[i]-'0');
				i++;
			}
			i--;                           //for循环会自增，while循环里也自增了，避免跳过
			operands.push(num);  //将字符转换成数字，压入操作数栈
		}
		//2.左括号
		else if(c=='('){
			operators.push(c);
		}
		//3.右括号
		else if(c==')'){
			//把)到(之间的所有运算符弹出栈
			while(!operators.empty()&&operators.top()!='('){
				char Operator=operators.top();    //弹出运算符
				operators.pop();
				//stack容器弹出元素不会返回元素，所以需要先用.top()取出栈顶元素，在.pop()弹出
				int b=operands.top();
				operands.pop();
				int a=operands.top();
				operands.pop();
				operands.push(Apply(a,b,Operator));
			}
			operators.pop();    //弹出左括号
		}
		//4.运算符
		else if(c=='+'||c=='-'||c=='*'||c=='/'){
			//处理优先级更高的运算符
			while(!operators.empty()&&Priority(operators.top())>=Priority(c)&&operators.top()!='('){
				char Operator=operators.top();
				operators.pop();
				int b=operands.top();
				operands.pop();
				int a=operands.top();
				operands.pop();
				operands.push(Apply(a,b,Operator));
			}
			operators.push(c);  //把当前运算符压入栈中
		}
	}
	
	//处理剩余的运算符
	while(!operators.empty()){
		char Operator=operators.top();
		operators.pop();
		int b=operands.top();
		operands.pop();
		int a=operands.top();
		operands.pop();
		operands.push(Apply(a,b,Operator));
	}
	return operands.top();
}

int main()
{
	string expression="3+4*2/(1-5)";
	int result=Evaluate(expression);
	cout<<expression<<"="<<result<<endl;
	return 0;
}