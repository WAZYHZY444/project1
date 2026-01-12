#include <stdio.h>
//关键是容易忘记当x=6或x=7的情况，这两个情况要特殊一些
int main()
{
	int x,n;
	long long len;
	scanf("%d %d",&x,&n);
	int Dw=n/7;  //计算有多少个完整一周
	int Dr=n%7;
	int workdays=5*Dw; //无论从星期几开始，只要是完整的一周，每周都会有5天的工作时间
	for(int i=0;i<Dr;i++){  //注意索引的取值与取值范围来理解代码
		int ret=(x+i)%7; //判断剩余时间
		if(ret>=1&&ret<=5){
			workdays++;
		}
	}
	len=250*workdays;
	printf("%lld",len);
	return 0;
}

//如果用0-6表示星期：(x+n)%7
//如果用1-6表示星期：(x-1+n)%7+1