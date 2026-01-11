#include <stdio.h>
int main()
{
	int L,M;
	int count=0;
	scanf("%d %d",&L,&M);
	int arr[M][2];
	for(int i=0;i<M;i++){
		for(int j=0;j<2;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int brr[10001]={0};  //先把没有移除之前的数组的所有元素初始化为0
	for(int i=0;i<M;i++){
		for(int j=arr[i][0];j<=arr[i][1];j++){
			brr[j]=1;    //在移除的区间的数组元素赋值为1
		}
	}
	for(int i=0;i<=L;i++){
		if(brr[i]==0){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
//错误解题思路：在所给的M个区间，找到最小值和最大值，建立一个新的大区间
//移除的树并不是这个区间的所有树，因为不能保证所给的M个数组区间叠加等于这个大区间，很有可能是不连续的