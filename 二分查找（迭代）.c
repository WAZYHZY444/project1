#include <stdio.h>
#include <string.h>
int test(int arr[],int sz,int num)
{
	int mid,left=0,right=sz-1;
	while(right>=left){
		mid=(left+right)/2;
		if(num==arr[mid]) return mid;
		if(num>arr[mid]) left=mid+1;
		else right=mid-1;
	}
	return -1;
}
int main()
{
	int num=3;
	int arr[7]={1,2,3,5,7,8,9};
	int sz=sizeof(arr)/sizeof(arr[0]);
	printf("%d\n",test(arr,sz,num));
}