#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10

typedef struct
{
	ElemType data[MAXSIZE];
	int top;  //计数
}SqStack;

//栈的初始化
void InitStack(SqStack* S)
{
	S.top=-1;
}

bool StackEmpty(SqStack S)
{
	if(S.top==-1){
		return true;
	}else{
		return false;
	}
}

//新元素压栈
bool Push(SqStack* S,ElemType x)
{
	if(S.top==MAXSIZE-1){
		return false;
	}
	S.top=S.top+1;
	S.data[S.top]=x;
	//S.data[++S.top]=x;
	return true;
}

//获取栈顶元素值
bool Push(SqStack* S,ElemType* x)
{
	if(S.top==MAXSIZE-1){
		return 0;
	}
	*x=S.data[S.top];
	return true;
}

//出栈
bool Pop(SqStack* S,ElemType* x) //数据还残留在内存中，只是逻辑上删除了
{
	if(S.top==MAXSIZE-1){
		return 0;
	}
	*x=S.data[S.top];
	S.top=S.top-1;
	//int x=S.data[S.top--];
	return true;
}