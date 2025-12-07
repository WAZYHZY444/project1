#include <stdio.h>
#include <math.h>
float test(float x,long long n)
{
	if(n==0){
		return 1;
	}else{
		return pow(x,n)+test(x,(n-1));
	}
}
int main()
{
	float x;
	long long n;
	scanf("%f %lld",&x,&n);
	float num=test(x,n);
	printf("%.2f",num);
	return 0;
}