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

//计算整数的位数
/*
#include <stdio.h>  //12345
int main()
{
	int n;
	int count=0;
	scanf("%d",&n);
	while(n>0){
		n/=10;
		count++;
	}
	printf("%d\n",count);
}
*/

//打印三角形
/*
#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	char c1=' ';
	char c2='*';
	for(int i=1;i<=n;i++){   //i表示行号
		int C1=n-i;
		int C2=2*i-1;
		while(C1>0){
			printf("%c",c1);
			C1--;
		}
		while(C2>0){
			printf("%c",c2);
			C2--;
		}
		printf("\n");
	}
	return 0;
}
*/

//二分法递归求解零点
/*
#include <stdio.h>
#include <math.h>
double f(double x)
{
	return x*x*x-exp(-x);
}

double test(double left,double right)
{
	double mid=(left+right)/2;
	if(fabs(right-left)<1e-6||fabs(f(mid))<1e-6){
		return mid;
	}
	if(f(mid)<0){
		return test(mid,right);
	}else{
		return test(left,mid);
	}
}
int main()
{
	double ret=test(0.0,1.0);
	printf("%.3f\n",ret);
	return 0;
}
*/

//二分查找  需要先排序
//迭代
/*
#include <stdio.h>
int test(int arr[],int key,int sz)
{
	int left=0,right=sz-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(key==arr[mid])return mid;
		if(key>arr[mid]){
			left=mid+1;
		}else right=mid-1;
	}
	return -1;
}
int main()
{
	int key=5;
	int arr[10]={2,4,5,6,7,8,9,10,12,13};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int ret=test(arr,key,sz);
	printf("%d\n",ret);
}
*/
//递归
/*
#include <stdio.h>
int test(int arr[],int key,int left,int right)
{
	int mid=(left+right)/2;
	if(key==arr[mid])return mid;
	if(key>arr[mid]){
		return test(arr,key,mid+1,right);
	}else return test(arr,key,left,mid-1);
	if(left>right)return -1;
}
int main()
{
	int key=5;
	int arr[10]={2,4,5,6,7,8,9,10,12,13};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int left=0,right=sz-1;
	int ret=test(arr,key,left,right);
	printf("%d\n",ret);
}
*/

//字符串中寻找最先出现的出现次数最多的字符
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[50];
	scanf("%s",arr);
	int len=strlen(arr);
	int dest[26]={0};
	for(int i=0;i<len;i++){
		int j=arr[i]-'a';
		dest[j]++;
	}
	int max=dest[0];
	for(int j=0;j<26;j++){
		if(dest[j]>max){
			max=dest[j];   //找出现的最大次数
		}
	}
	for(int j=0;j<26;j++){
		if(dest[j]==max){  //找最先出现最大次数所对应的字母
			printf("%c\n",j+'a');
			break;
		}
	}
	return 0;
}
//认识：花括号会创建一个新的作用域，在花括号里面定义的变量，除了花括号变量销毁，注意，不仅仅是函数，也可以是循环，
//所以在循环里面使用的变量需要在循环外面声明，并初始化，否则会返回初始值
//初始化变量
*/

#include <stdio.h>
int main()
{
	int arr[2][2]={{1,2},{3,4}};
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}










