#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[2*n][m];  //变长数组
	int brr[n][m];
	for(int i=0;i<2*n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			brr[i][j]=arr[i][j]+arr[i+n][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",brr[i][j]);
		}
		printf("\n");
	}
	return 0;
}