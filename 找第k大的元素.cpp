//利用快速排序找第k大的元素

#include <iostream>

using namespace std;

int quickSearch_k(int arr[],int start,int end,int k)
{
	if(start==end) return arr[start];
	if(start>end) return -1;
	
	int i=start,j=end;
	int temp=arr[start];
	while(i<j){   //从区间两端交替向中间扫描，直到i=j
		while(j>i&&arr[j]<=temp) j--;
		arr[i]=arr[j];
		
		while(i<j&&arr[i]>=temp) i++;
		arr[j]=arr[i];
	}
	arr[i]=temp;
	
	if(i==k) return arr[i];
	else if(i>k) return quickSearch_k(arr,start,i-1,k);
	else return quickSearch_k(arr,i+1,end,k);
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	int res=quickSearch_k(arr,0,n-1,k-1);
	cout<<res<<endl;
	return 0;
}