#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n-1;i++){
		scanf("%d",&arr[i]);
	}
	int number=0;
	for(int i=0;i<n-1;i++){
		number+=arr[i];
	}
	int a=(n-2)*180;
	printf("%d",a-number);
	return 0;
}

//另一种不用数组的方法

/*
#include <stdio.h>
int main()
{
	int n,number;
	int N=0;    //必须初始化为0才开始累加   //未初始化的局部变量包含随机值，直接使用会导致错误结果
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d",&number);
		N+=number;
	}
	int a=(n-2)*180;
	printf("%d",a-N);
	return 0;
}
*/