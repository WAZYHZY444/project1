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
	int brr[10001]={0};  //一维数组 1<=L<=10000
	for(int i=0;i<M;i++){
		for(int j=arr[i][0];j<=arr[i][1];j++){
			brr[j]=1;
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