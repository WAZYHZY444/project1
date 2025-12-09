#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	for(int k=1; ;k++){
		//52*(7x+21k)=364x+1092k
		int temp=N-1092*k;
		if(temp%364==0){  //确保x是正整数
			int x=temp/364;
			printf("%d\n%d\n",x,k);
			return 0;
		}
	}
	return 0;
}