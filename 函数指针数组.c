/*
#include <stdio.h>
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

int main()
{
//	int (*pf)(int int)=&Add;    //pf是函数指针
	int (*arr[4])(int,int)={Add,Sub,Mul,Div}; //arr是函数指针数组
	for(int i=0;i<4;i++){
		int ret=arr[i](8,4);
		printf("%d\n",ret);
	}
	return 0;
}
*/

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

int main()
{
	int input=0;
	int x=0;
	int y=0;
	int ret=0;
	
	//函数指针数组
	//转移表
	int (*arr[5])(int,int)={0,Add,Sub,Mul,Div}; //0的作用是把后面的函数地址往后挤一位，让数组的下标从1开始与函数地址一一对应
	
	do
	{
		menu();
		printf("请选择>");
		scanf("%d",&input);
		if(input==0){
			printf("退出计算器\n");
		}
		else if(input>=1&&input<=4){
			printf("请输入两个操作数:>");
			scanf("%d %d",&x,&y);
			ret=arr[input](x,y);
			printf("%d\n",ret);	
		}
		else{
			printf("选择错误\n");
		}
	}while(input);
	
	return 0;
}





