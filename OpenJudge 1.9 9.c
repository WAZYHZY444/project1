#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int max=arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	int brr[max+1];
	for(int i=0;i<(max+1);i++){
		int count=0;
		for(int j=0;j<n;j++){
			if(arr[j]==i){
				count++;
			}
		}
		brr[i]=count;
	}
	for(int i=0;i<(max+1);i++){
		printf("%d\n",brr[i]);
	}
	return 0;
}