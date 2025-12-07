#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		int min_i=i;
//选择排序要记录索引而不是立即交换 —— 等找到真正的最小值后再一次性交换
		for(int j=i+1;j<n;j++){
			    if(arr[j]<arr[min_i]){
			    	min_i=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[min_i];
		arr[min_i]=temp;
	}
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}