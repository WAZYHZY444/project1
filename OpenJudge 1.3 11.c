#include <stdio.h>
int main()
{
	double a,b;
	scanf("%lf %lf",&a,&b);
	double y=a/b;
	long x=(long)y;
	double T=a-(x*b);
	printf("%g",T);
	return 0;
}
