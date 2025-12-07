#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	double time_1=0.0,time_2=0.0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){ //不需要利用数组来存储数据
		double x,y;
		int people;
		scanf("%lf %lf %d",&x,&y,&people); //注意题目要求坐标是实数，就不能用int类型了
		time_1+=2.0*sqrt(x*x+y*y)/50.0;
		time_2+=people*(1.0+0.5);
	}
	printf("%.0f",ceil(time_1+time_2));  //浮点数向上取整用ceil，整数向上取整用（a+b-1)/b
}