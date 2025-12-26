#include <stdio.h>
/*
//__FILE__  进行编译的源文件
//__LINE__  文件当前的行号
//__DATE__  文件被编译的日期
//__TIME__  文件被编译的时间
//__STDC__  //如果编译器遵循ANSI C(标准C),其值为1，否则未定义
int main()
{
	for (int i = 0; i < 10; i++) {
		printf("file:%s line:%d date:%s time:%s i=%d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);
	}
	return 0;
}
*/

/*
#define DOUBLE(X) ((X)+(X))  //宏不能递归
int main()
{
	int r=10*DOUBLE(3);
	printf("%d\n",r);
	return 0;
}
*/

/*
#define PRINT(N) printf("the value of "#N" is %d \n",N)
//#N-->"a" , 当#N替换为"a"时，这时可以把"the value of "#N" is %d \n"看作三段字符串，可以连续打印出来
//#号可以把参数转换成对应的字符串
int main()
{
	int a=10;
	PRINT(a);
	return 0;
}
*/

/*
#define PRINT(N,FORMAT) printf("the value of "#N" is "FORMAT"\n",N);
int main()
{
	int a=10;
	PRINT(a,"%d");
	float b=3.14f;
	PRINT(b,"%lf");
	return 0;
}
*/

/*
#define CAT(Class,Num) Class##Num  //##可以把位于它两边的符号合成一个符号
int main()
{
	int Class25=100;
	printf("%d\n",CAT(Class,25));
	return 0;
}
*/

/*
//带副作用的宏参数
#define MAX(x,y) ((x)>(y)?(x):(y))
int main()
{
	int a=5,b=4;
	int m=MAX(a++,b++); //MAX(a++,b++)--->((a++)>(b++)?(a++):(b++))
	printf("m=%d\na=%d\nb=%d\n",m,a,b);
	return 0;
}
*/

/*
#define M 3
//如果一个宏没有被#define定义过，那么它在#if或#elif中会被当作0来处理。#if M < 5 变成了 #if 0 < 5，这个条件为真，因此会执行第一个分支。(如果把#define注释掉的话)
int main()
{
#if M<5
	printf("hehe\n");
#elif M==5
	printf("haha");
#else
	printf("heihei\n");
#endif

#if defined(M)       //#if !defined(M)
//#ifdef M           //#ifndef M
	printf("xixi\n");
#endif
	return 0;
}
*/

//防止头文件多次重复包含(写在.h文件里)
//方案一
#ifndef __TEST_H__
#define __TEST_H__
int Add(int x,int y);
#endif

//方案二
#pragma once
int Add(int x,int y);