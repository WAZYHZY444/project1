#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int ThisSum;
	int MinSum=0;  //记得MinSum在累加之前需要初始化
	for(int i=0;i<m;i++){
		MinSum+=arr[i];
	}
	for(int i=0;i<=n-m;i++){
		ThisSum=0;
		for(int j=i;j<i+m;j++){
			ThisSum+=arr[j];
		}
		if(ThisSum<MinSum){
			MinSum=ThisSum;
		}
	}
	printf("%d\n",MinSum);
	return 0;
}