#include <stdio.h>
int main()
{
	double r,pi=3.14;
	scanf("%lf",&r);
	double V=4.0/3*pi*r*r*r;     //4/3是整数除法，结果为1
	printf("%.2f",V);
	return 0;
}