#include<stdio.h>
int main()
{
	int r,h;
	scanf("%d %d",&r,&h);
	int V=3.14*r*r*h;
	int n=(2E+7 +V)/V;
	printf("%d",n);
	return 0;
}