#include <stdio.h>
int gcd(long a,long b)
{
	while(b!=0){
		int temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}
int main()
{
	long long arr[3];
	for(int i=0;i<3;i++){
		scanf("%lld",&arr[i]);
	}
	long long max=arr[0];
	long long min=arr[0];
	for(int j=0;j<3;j++){
		if(arr[j]>max){
			max=arr[j];
		}
		if(arr[j]<min){
			min=arr[j];
		}
	}
	long long x=gcd(min,max);
	printf("%lld/%lld\n",min/x,max/x);
	return 0;
}