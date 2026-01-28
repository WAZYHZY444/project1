//计算多项式f(x)=a0+a1+···+an-1x^(n-1)+anx^n
#include <stdio.h>
#include <math.h>
double f(int n,double a[],double x)
{
	double p=a[0];
	for(int i=1;i<=n;i++){
		p+=(a[i]*pow(x,i));
	}
	return p;
}

double F(int n,double a[],double x)
{
	//f(x)=a0+x(a1+x(···(an-1+x(an))···))
	double p=a[n];
	for(int i=n;i>0;i--){
		p=a[i-1]+x*p;
	}
	return p;
}
int main()
{
	int n;
	double x;
	scanf("%d %lf",&n,&x);
	double a[n];
	for(int i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	double result1=f(n,a,x);
	double result2=F(n,a,x);
	printf("%f\n%f\n",result1,result2);
	return 0;
}