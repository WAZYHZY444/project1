#include <stdio.h>
long long MIN(long long arr[]){
	int min=arr[0];     //假设第一个元素是最小值
	for(int i=1;i<3;i++){
		if(arr[i]<min){
			min=arr[i];
		}
	}
	return min;
}

int main()
{	
	long long n,num1,mon1,num2,mon2,num3,mon3;
 	scanf("%lld %lld %lld %lld %lld %lld %lld",&n,&num1,&mon1,&num2,&mon2,&num3,&mon3);
 	long long M1,M2,M3;
 	if(n<=num1){
 		M1=mon1;
	}else{
	 	M1=(n+num1-1)/num1*mon1;
	}
	if(n<=num2){
 		M2=mon2;
	}else{
	 	M2=(n+num2-1)/num2*mon2;
	}
	if(n<=num3){
 		M3=mon3;
	}else{
	 	M3=(n+num3-1)/num3*mon3;
	}
	long long num[]={M1,M2,M3};
	long long min=MIN(num);    //函数的调用
	printf("%lld\n",min);
	return 0;
}