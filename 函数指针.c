/*
#include <stdio.h>
int Add(int x,int y)
{
	return x+y;
}
int main()
{
	int(*pf)(int,int)=&Add;
	int ret=pf(2,3);
	printf("%d\n",ret);
	return 0;
}
*/

/*
#include <stdio.h>
int Add(int x,int y)
{
	return x+y;
}
int calc(int(*pf)(int,int))
{
	int a=3;
	int b=5;
	int ret=pf(a,b);
	printf("%d\n",ret);
}
int main()
{
	calc(Add);
	return 0;
}
*/

//计算器
#include <stdio.h>
void menu()
{
	printf("******************************\n");
	printf("******  1.add  2.sub  ********\n");
	printf("******  3.mul  4.div  ********\n");
	printf("******  0.exit        ********\n");
	printf("******************************\n");
}
int Add(int x,int y)
{
	return x+y;
}
int Sub(int x,int y)
{
	return x-y;
}
int Mul(int x,int y)
{
	return x*y;
}
int Div(int x,int y)
{
	return x/y;
}

void calc(int (*pf)(int,int))  //回调函数
{
	int x=0;
	int y=0;
	int ret=0;
	
	printf("请输入两个操作符:>");
	scanf("%d %d",&x,&y);
	ret=pf(x,y);
	printf("%d\n",ret);	
}

int main()
{
	int input=0;
	do
	{
		menu();
		printf("请选择>");
		scanf("%d",&input);
		
		switch(input)
		{
		case 1:
			calc(Add);
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Mul);
			break;
		case 4:
			calc(Div);
			break;
		case 0:
			printf("退出计算器\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	}while(input);
	return 0;
}




















