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
		for(int j=(i+1);j<n;j++){
			if(arr[i]==arr[j]){
				arr[j]=0; //题目说明了每个整数不等于0
			}
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i]!=0){
			printf("%d ",arr[i]);
		}
	}
	return 0;
}