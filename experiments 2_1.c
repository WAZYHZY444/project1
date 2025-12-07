#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n][m];
	
//计算非最后一行的最后一列元素的值
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m-1;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<n-1;i++){
		int row_sum=0;  
//每进行一次外循环，row_sum就要赋值为0，开始下一行的累加
		for(int j=0;j<m-1;j++){
			row_sum+=arr[i][j];
		}
		arr[i][m-1]=row_sum;
//要在外层循环里进行arr[i][m-1]的赋值，只需要赋值n-1次；
//若在内层循环中进行，则赋值了（n-1）（m-1）次
	}
	
//计算最后一行非最后一列的值
	for(int j=0;j<m;j++){
		int col_sum=0;
		for(int i=0;i<n-1;i++){
			col_sum+=arr[i][j];
		}
		arr[n-1][j]=col_sum;
	}
	
//输出结果
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}










