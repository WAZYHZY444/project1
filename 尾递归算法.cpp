/*
尾递归：一个函数调用自身后不再执行任何其他操作，
编译器会覆盖当前的栈帧，大大减少栈空间的使用，提高运行效率
*/

#include <iostream>

using namespace std;

//n的阶乘
int func(int n,int res)
{
	if(n==1) return res;
	return func(n-1,n*res);
}

//斐波那契数列
int solve(int n,int a,int b)
{
	if(n==1) return a;
	if(n==2) return b;
	return solve(n-1,b,a+b);
}
int main()
{
	int res=func(5,1);
	int res2=solve(5,1,1);
	
	cout<<res<<endl;
	cout<<res2<<endl;
	return 0;
}