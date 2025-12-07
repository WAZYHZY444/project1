#include <stdio.h>
//int main()
//{
//	long long N,digit=0,ret=0;
//	scanf("%lld",&N);
//	if(N>=0){
//		while(N>0){
//			digit=N%10;
//			ret=ret*10+digit;
//			N/=10;
//		}
//		printf("%lld\n",ret);
//	}
//	if(N<0){
//		int T=-N;
//		while(T>0){
//		digit=T%10;
//		ret=ret*10+digit;
//		T/=10;
//	}
//	printf("-%lld\n",ret);
//	}
//	return 0;
//}


long long test(long long num)
{
	long long digit=0,ret=0;
	if(num>=0){
		while(num>0){
			digit=num%10;
			ret=ret*10+digit;
			num/=10;
		}
	}
		return ret;
}
int main()
{
	long long N,ret;
	scanf("%lld",&N);
	if(N>=0){
		ret=test(N);
	}else{
		ret=-test(-N);
	}
		printf("%lld\n",ret);
	return 0;	
}














