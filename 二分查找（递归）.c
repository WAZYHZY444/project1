#include <stdio.h>
#include <string.h>
int test(int arr[],int left,int right,int num)
{
	if(left>right)return -1;
	int mid;
	mid=(left+right)/2;
	if(num==arr[mid]) return mid;
	else if(num>arr[mid]) return test(arr, mid + 1, right, num);
	else return test(arr,left,mid-1,num);
}
int main()
{
	int num=3;
	int arr[7]={1,2,3,5,7,8,9};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int left=0;
	int right=sz-1;
	printf("%d\n",test(arr, left, right, num));
}