#include <stdio.h>
int main()
{
	long long k;
	scanf("%lld",&k);
	long long day_money,day=0,money=0;
	for(day_money=1;day<k;day_money++){  //day从0一直加到k-1,外层循环了k次
		for(int i=0;i<day_money;i++){  //若day<=k,当day=k时，进入内层循环，而++day>k,break停止
			if(++day>k)break;             //***++day必须在内层循环中执行，才会产生i个i的金币***
			money+=day_money;
		}
	}
	printf("%lld\n",money);
	return 0;
}