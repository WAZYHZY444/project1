#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double D=b*b-4*a*c;
	double result1,result2;
	if(D>0){
		result1=(-b+sqrt(D))/(2*a);
		result2=(-b-sqrt(D))/(2*a);
		printf("x1=%.5f;x2=%.5f\n",result1,result2);
	}else if(D==0){
		result1=-b/(2*a);
		result2=-b/(2*a);
		printf("x1=%.5f;x2=%.5f\n",result1,result2);
	}else if(D<0){
		result1=-b/(2*a);
		if(fabs(b)<1e-7){         //避免输出-0.00000
			result1=0.0;
		}
		result2=sqrt(-D)/(2*a);
		printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n",result1,result2,result1,result2);
	}
	return 0;
}