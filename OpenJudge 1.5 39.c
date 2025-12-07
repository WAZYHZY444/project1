#include <stdio.h>
#include <math.h>
long long test(int x)
{
	long long i,num;//i为long long型，避免i*i结果溢出
	long long X=0;
	for(i=1;i<=x;i++){
		int ISseven=0;  //每次经过while，ISseven都要重新赋值为0
		if(i%7==0)continue; //continue跳出本次循环
		int temp=i; //使用临时变量，避免修改循环变量
		while(temp>0){
			num=temp%10;
			if(num==7){
				ISseven=1;//因为使用的是临时变量，所以需要引入ISseven,来判断那些i进行平方和计算
				break;
			}
			temp/=10;
		}
		if(ISseven==0){
		X+=i*i;
    	}
	}
	return X;
}
int main()
{
	int n;
	scanf("%d",&n);
	long long sum=test(n);
	printf("%lld\n",sum);
	return 0;
}