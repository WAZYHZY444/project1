#include <stdio.h>
#include <math.h>
double f(int a,int b,int c,double x)               //把方程表达式进行函数声明，可以简化后面的代码，避免表达式重复出现
{
	return a*x*x*x-b*exp(-c*x);
}

double test(int a,int b,int c,double left,double right){
	double mid=(left+right)/2;
	double f_mid=f(a,b,c,mid);                      //注意变量的定义不能有括号！
	if(fabs(left-right)<1e-6||fabs(f_mid)<1e-6){    //递归终止条件
		return mid;
	}
	if(f_mid<0){
		return test(a,b,c,mid,right);               //只需要改变传参的顺序，不需要做if判断
	}else{
		return test(a,b,c,left,mid);
	}
}

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	double result=test(a,b,c,0.0,1000.0);        //参数列表里可以是变量，也可以是常量
	printf("%.3f",result);
	return 0;
}