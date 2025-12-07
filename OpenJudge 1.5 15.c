#include <stdio.h>
int main()
{
	int R,Y;
	long long M;
	scanf("%d %lld %d",&R,&M,&Y);
	double m=(double)M;   //类型转化要在输入值之后在进行，若M还未赋值，则包含随机值
	for(int i=0;i<Y;i++){
		m*=(1.0+R/100.0);
	}
	long long money=(long long)m;  //%.0f->si四舍五入  想要只输出整数部分，就采取类型转换
	printf("%lld\n",money);
	return 0;
}