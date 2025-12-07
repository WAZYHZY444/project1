
#include <stdio.h>
#include <math.h>
int	main()
{
	int a,b,c;
	double left=0.0,right=1000.0,mid;
	scanf("%d %d %d",&a,&b,&c);
	while(fabs(left-right)>1e-6){
		mid=(left+right)/2;
		if(a*mid*mid*mid-b*exp(-c*mid)<0){
			left=mid;
		}else{
			right=mid;
		}
	}
	printf("%.3f",mid);
	return 0;
}





























