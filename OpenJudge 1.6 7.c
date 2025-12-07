#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	scanf("%d",&n);
	int brr[n];
	int arr[n-1];
	for(int i=0;i<n;i++){
		scanf("%d",&brr[i]);
	}
	if(n==1){
		printf("Jolly\n");
		return 0; //注意
	}
	for(int i=0;i<n-1;i++){
		arr[i]=abs(brr[i]-brr[i+1]);
	}
	for(int i=0;i<n-2;i++){
		for(int j=0;j<n-i-2;j++){
			if(arr[j]>arr[j+1]){
				int ret=0;
				ret=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=ret;
			}
		}
	}
	int a=1;
	for(int i=0;i<n-1;i++){
		if(arr[i]!=i+1){
			a=0;
			break;
		}
	}
	if(a==1){
		printf("Jolly\n");
	}else{
		printf("Not jolly\n");
	}
	return 0;
}