#include<stdio.h>
int main()
{
    double t;
	int n;
	scanf("%lf",&t);
	scanf("%d",&n);
	double ret=t/n;
	printf("%.3f\n",ret);
	printf("%d",2*n);
	return 0;
}