#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAXN 10

//clock(): 捕捉从程序开始运行到clock()被调用时所耗费的时间。时间单位是clock tick，即“时钟打点”
//常数CLK_TCK: 机器时钟每秒所走的时钟打点数

//计算多项式f(x)=a0+a1+···+an-1x^(n-1)+anx^n
double f1(int n,double a[],double x)
{
	double p=a[0];
	for(int i=1;i<=n;i++){
		p+=(a[i]*pow(x,i));
	}
	return p;
}

double f2(int n,double a[],double x)  //秦九韶算法
{
	//f(x)=a0+x(a1+x(···(an-1+x(an))···))
	double p=a[n];
	for(int i=n;i>0;i--){
		p=a[i-1]+x*p;
	}
	return p;
}

void clock_test(double (*func)(int,double*,double),int n,double a[],double x)
{
	clock_t start,stop;
	double duration;
	start=clock();   //开始计时
	func(n,a,x);
	stop=clock();    //停止计时
	duration=((double)(stop-start))/CLK_TCK;
	printf("时钟滴答数：%f\n",(double)(stop-start));
	printf("运行时间：%6.2e\n",duration);
}

int main()
{
	double x;
	scanf("%lf",&x);
	double a[MAXN];
	for(int i=0;i<MAXN;i++){
		scanf("%lf",&a[i]);
	}
	
	/*
	clock_t start,stop;  //clock_t是clock()函数返回的变量类型
	double duration;     //记录被测函数运行时间，以秒为单位

	start=clock();   //开始计时
	f1(MAXN,a,x);
	stop=clock();    //停止计时
	duration=((double)(stop-start))/CLK_TCK;
	printf("ticks1=%f\n",(double)(stop-start));
	printf("duration1=%6.2e\n",duration);   //①6:最小字段宽度，输出至少占6个字符位置;②.2:小数部分精度，小数点后保留2位数字;③e:科学计数法格式

	start=clock();
	f2(MAXN,a,x);
	stop=clock();
	duration=((double)(stop-start))/CLK_TCK;
	printf("ticks2=%f\n",(double)(stop-start));  //ticks时钟滴答数
	printf("duration2=%6.2e\n",duration);
	*/
	
	clock_test(f1,MAXN, a, x);
	clock_test(f2,MAXN, a, x);
	return 0;
}