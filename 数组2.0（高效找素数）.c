//在支持C99的编译器下，可以使用变长数组，但要注意的是变长数组不能初始化，需要手动初始化（遍历），也可以用宏定义来替换变长数组的大小的那个未知量
//在不支持C99的编译器下，需要在终端输入数组大小，只能使用动态分配

#include <stdio.h>
#define number 10
int isPrime(int x,int knownPrimes[],int numberofkownPrimes);
int main()
{
	int prime[number]={2};     //新发现：可变数组不能初始化
	int count=1;  //计数器
	int i=3;      //已知2是素数，从3开始判断
	while(count<number){    //循环条件
		if(isPrime(i,prime,count)){    //在main函数调用后面的isPrime函数，判断i是否是素数
		prime[count++]=i;     //如果是素数，存入数组并计数
		}
		i+=2;   //只判断奇数，更加高效
	}
	for(i=0;i<number;i++){
		printf("%d",prime[i]);
		if((i+1)%5)printf("\t");     //每5个换行，其他用制表符分隔
		else printf("\n");
	}
	return 0;

}

//逻辑函数：遍历已知素数数组，如果x能被任何一个已知素数整除，则x不是素数，返回0，否则返回1
int isPrime(int x,int knownPrimes[],int numberofkownPrimes)     //knownPrimes[]已知数素的数组  numberofkownPrimes  已知素数的个数
{
	int ret=1;
	int i;
	for(i=0;i<numberofkownPrimes;i++){
		// 优化：如果已知素数的平方大于x，停止检查
        if(knownPrimes[i]*knownPrimes[i]>x){
            break;
        }
		if(x%knownPrimes[i]==0){
			ret=0;
			break;
		}
	}
	return ret;
}