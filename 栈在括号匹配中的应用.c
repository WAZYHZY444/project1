#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXSIZE 10

typedef struct
{
	char data[MAXSIZE];
	int top;
}SqStack;

void InitStack(SqStack* S)
{
	S->top=-1;
}

bool StackEmpty(SqStack S)
{
	return S.top==-1;
}

bool StackFull(SqStack S)
{
	return S.top==MAXSIZE-1;
}

bool Push(SqStack* S,char c)
{
	if(StackFull(*S)){
		return false;
	}
	S->data[++S->top]=c;
	return true;
}

bool Pop(SqStack* S,char* c)
{
	if(StackEmpty(*S)){
		return false;
	}
	*c=S->data[S->top--];
	return true;
}

bool bracketCheak(char str[],int len)
{
	SqStack S;
	InitStack(&S);
	for(int i=0;i<len;i++){
		if(str[i]=='('||str[i]=='{'||str[i]=='['){
			if(!Push(&S,str[i])){  //检查站是否已满
				return false;
			}
		}
		else if(str[i]==')'||str[i]=='}'||str[i]==']'){
			if(StackEmpty(S))
				return false;
			char topelem;
			Pop(&S,&topelem);
			if(str[i]==')'&&topelem!='(')
				return false;
			if(str[i]=='}'&&topelem!='{')
				return false;
			if(str[i]==']'&&topelem!='[')
				return false;
		}
	}
	return StackEmpty(S);  //最后还要验证栈空，确保所有的都配对了
}
int main()
{
	char str[10]={0};
	scanf("%9s",str);
	int len=strlen(str);
	bool x=bracketCheak(str,len);
	if(!x){
		printf("匹配失败！\n");
	}else{
		printf("匹配成功！\n");
	}
}