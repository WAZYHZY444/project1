#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

typedef struct{
	long long data[MAX_SIZE];
	int top;
}Stack;

void InitStack(Stack* s)
{
	s->top=-1;
}

void Push(Stack* s,int val)
{
	s->data[++s->top]=val;
}

long long Pop(Stack* s)
{
	return s->data[s->top--];
}

long long GetTop(Stack* s)
{
	return s->data[s->top];
}

long long Apply(long long a,long long b,char ch)
{
	switch(ch){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			if(b==0){
				exit(1);
			}
			return a/b;
		default:
			return 0;
	}
}

int Calculate(char str[])
{
	Stack s;
	InitStack(&s);
	long long num=0;
	for(int i=0;str[i]!='@';i++){
		char c=str[i];
		if(isdigit(c)){
			num=num*10+(c-'0');
		}
		else if(str[i]=='.'){
			Push(&s,num);
			num=0;
		}
		else if(c=='+'||c=='-'||c=='*'||c=='/'){
			long long b=Pop(&s);
			long long a=Pop(&s);
			Push(&s,Apply(a,b,c));
		}
	}
	return Pop(&s);
}

int main()
{
	char str[MAX_SIZE];
	scanf("%s",str);
	printf("%d\n",Calculate(str));
	return 0;
}