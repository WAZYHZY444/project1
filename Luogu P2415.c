#include <stdio.h>
#include <math.h>
int main()
{
	int n,count=0;
	long long sum=0;
	do{
        if(scanf("%d",&n)==1){
            sum+=n;
            count++;
        }
    }while(getchar()!='\n');  // 检查是否换行
    
	long long SUM=sum*(long long)pow(2.0,count-1);
	printf("%lld\n",SUM);
	return 0;
}
//对于每个数都有选和不选两种选择，对于含有n个元素的集合，所有子集个数为2^n(初中集合知识)
//每个元素在所有集合中出现的次数是总集合数的一半2^n-1
//总和等于所有元素的和2^n−1
 