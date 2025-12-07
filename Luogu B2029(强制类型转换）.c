#include <stdio.h>
#include <math.h>
int main()
{
	int h,r;
	scanf("%d %d",&h,&r);
	double V0=3.14*r*r*h;
	double n=20*1000/V0;
	int a=(int)n;
	printf("%d",a+1);
	return 0;
}