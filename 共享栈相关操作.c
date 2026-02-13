#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10

typedef struct
{
	int data[MAXSIZE];
	int top1;   //栈1的栈顶指针(栈底->栈顶)
	int top2;   //栈2的栈顶指针(栈顶->栈底)
}ShareStack;

//栈的初始化

void InitStack(ShareStack* S)
{
	S.top1=-1;
	S.top2=MAXSIZE;
}

//判断栈是否已满
bool isFull(ShareStack* S)
{
	return S.top1+1=S.top2;
}

//判断栈1是否为空
bool isEmpty1(ShareStack* S)
{
	return tpo1=-1;
}

//判断栈1是否为空
bool isEmpty2(ShareStack* S)
{
	return tpo2=MAXSIZE;
}

//栈1入栈
bool push1(ShareStack* S,int value)
{
	if(isFull(S)){
		return false;
	}
	S.data[++S.top1]=value;
	return true;
}

//栈2入栈
bool push2(ShareStack* S,int value)
{
	if(isFull(S)){
		return false;
	}
	S.data[--S.top2]=value;
	return true;
}

//栈1出栈
bool pop1(ShareStack* S,int* value)
{
	if(isEmpty1(S)){
		return false;
	}
	*value=S.data[S.top1--];
	return true;
}

//栈1出栈
bool pop2(ShareStack* S,int* value)
{
	if(isEmpty2(S)){
		return false;
	}
	*value=S.data[S.top2++];
	return true;
}

//获取栈1栈顶元素
bool GetTop1(ShareStack* S,int* value)
{
	if(isEmpty1(S)){
		return false;
	}
	*value=S.data[S.top1];
	return true;
}

//获取栈2栈顶元素
bool GetTop2(ShareStack* S,int* value)
{
	if(isEmpty2(S)){
		return false;
	}
	*value=S.data[S.top2];
	return true;
}