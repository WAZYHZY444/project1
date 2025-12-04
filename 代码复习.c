//0到100的素数
/*
#include <stdio.h>
int main()
{
	for(int i=2;i<=100;i++){
		int mark=1;
		for(int j=2;j*j<=i;j++){   //重大发现：j*j要<=i(不要忘记=）
			if(i%j==0){  //不是素数
				mark=0;
				break;
			}
		}
		if(mark){
			printf("%d ",i);
		}
	}
	return 0;
}
*/

//前50个素数
/*
#include<stdio.h>
int main()
{
//	int count=0;
//	for(int i=2;i<=1000;i++){
//		int mark=1;
//		for(int j=2;j*j<=i;j++){
//			if(i%j==0){
//				mark=0;
//				break;
//			}
//		}
//		if(mark){
//			printf("%d ",i);
//			count++;
//		}
//		if(count==50)break;
//	}

//调整版
	int count=0;
	for(int i=2;count<50;i++){
		int mark=1;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				mark=0;
				break;
			}
		}
		if(mark){
			printf("%d ",i);
			count++;
		}
	}
	return 0;
}
*/

//九九乘法表
/*
#include <stdio.h>
int main()
{
	for(int i=1;i<10;i++){
		for(int j=1;j<=i;j++){
			printf("%d*%d=%-2d   ",i,j,i*j);
		}
		printf("\n");
	}
	return 0;
}
*/

//整数的分解
/*
#include <stdio.h>
void test(int x)
{
	if(x>9){  //递归优先考虑递归条件，思考什么样的条件需要重复调用函数，当不满足条件是需要做什么
		test(x/10);  
	}
	printf("%d ",x%10);
	
}
int main()
{
	int x;
	scanf("%d",&x);
	test(x);
	return 0;
}
*/

//斐波那契数列
#include <stdio.h>
int test(int n)
{
	if(n>3){
		return 
	}
}
int main()
{
	int n;
	scanf("%d",&n);
}