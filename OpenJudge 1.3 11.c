#include <stdio.h>
int main()
{
	double a,b;
	scanf("%lf %lf",&a,&b);
	double y=a/b;
	long x=(long)y;  //将浮点型数据转化为整形数据，会截断小数点部分，只保留整数部分
	double T=a-(x*b);
	printf("%g",T);
	return 0;
}
