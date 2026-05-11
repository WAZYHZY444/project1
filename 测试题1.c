/*
	题目：
		依次读入序列元素1,2,…n进栈，每进一个元素，机器可要求下一个元素进栈成弹栈，如此进行。给定一个输入序列，
		判断栈空时弹出的元表构成的序列是否可能等于给定的序列，如果是则输出栈的操作过程，否则输出"NO"
	输入
		输入分两行
		第一行为n的值（即序列元素个数）
		第二行为给定的输入序列（序列元素均为整型）
	输出
		如果输入序列能够由题目规定的操作得到，则输出对钱的操作过程，否则直接输出"NO"
*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

static int stack[MAX], top=-1;

void push(int val){stack[++top]=val;}
int pop(){return stack[top--];}
int isEmpty(){return top==-1;}
int stackTop(){return stack[top];}

int main()
{
	int n;
	scanf("%d",&n);
	int out[MAX];
	for(int i=0;i<n;i++){
		scanf("%d",&out[i]);
	}
	int op[2*MAX][2];  //保存操作过程
	int count=0;         //操作计数
	int num=1,index=0;
	while(num<=n||!isEmpty()){
		//如果栈顶等于当前输出，则弹出
		if(!isEmpty()&&stackTop()==out[index]){
			op[count][0]=1;
			op[count][1]=pop();
			count++;
			index++;
		}
		//否则，还有元素可以压栈，则压入
		else if(num<=n){
			op[count][0]=0;
			op[count][1]=num;
			push(num++);
			count++;
		}
		else{
			printf("NO\n");
			return 0;
		}
	}
	for(int i=0;i<count;i++){
		printf("%s %d\n",op[i][0]?"POP":"PUSH",op[i][1]);
	}
	return 0;
}