#include <stdio.h>
double test(int arr[],int m)
{
	double sum=0.0;
	int max=arr[0],min=arr[0];
	for(int i=0;i<m;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
		sum+=arr[i];
	}
	if(m<=2){
		return 0.0;
	}
	return (sum-max-min)/(m-2);
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	double brr[n];
	for(int i=0;i<n;i++){
		brr[i]=test(arr[i],m);
	}
	double max=brr[0];
	for(int i=0;i<n;i++){
		if(brr[i]>max){
			max=brr[i];
		}
	}
	printf("%.2f\n",max);
	return 0;
}