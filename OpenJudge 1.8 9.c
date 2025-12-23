#include <stdio.h>
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int arr[n][m];
	int brr[m][k];
	int crr[n][k];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<k;j++){
			scanf("%d",&brr[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int A=0,B=0;
			crr[i][j]=0;   //记得累加累乘必须要初始化哦
			while(A<m&&B<m){
				crr[i][j]+=arr[i][A]*brr[B][j];
				A++;
				B++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			printf("%d ",crr[i][j]);
		}
		printf("\n");
	}
	return 0;
}