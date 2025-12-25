#include <stdio.h>
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	int arr[N][M];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int j=0;j<M;j++){
		int i=0;
		while(i<N){
			int mark=0;
			printf("%d",arr[i][j]);
			if(arr[i][j]==arr[N-1][j]){
				mark=1;
			}
			if(!mark){
				printf(" ");
			}
			i++;
		}
		printf("\n");
	}
	return 0;
}
