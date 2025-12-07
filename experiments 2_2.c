#include <stdio.h>
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int arr[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int k=0;k<m+n-1;k++){  //利用角标和为常数
		for(int i=0;i<m;i++){  //从n=0开始遍历，定位列
			int j=k-i;
			if(j<n&&j>=0){
				printf("%d\n",arr[i][j]);
			}
		}
	}
	return 0;
}