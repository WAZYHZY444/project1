#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		if(arr[i] < 2){
            continue;  // 跳过，不是素数
        }
		int mark=1;	
		for(int j=2;j*j<=arr[i];j++){
			if(arr[i]%j==0){
				mark=0;
				break;
			}
		}
		if(mark){
			printf("%d ",arr[i]);
		}       
	}
	return 0;
}