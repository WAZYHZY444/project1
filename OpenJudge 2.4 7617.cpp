#include <iostream>
#include <algorithm>

using namespace std;

void threep(int a[],int &p,int &r)
{
	int temp=a[p];
	int k=p+1;
	while(k<=r){
		if(a[k]==temp) k++;
		else if(a[k]>temp) swap(a[k++],a[p++]);
		else swap(a[r--],a[k]);
	}
}

int quickSearch_k(int a[],int start,int end,int k)
{
	if(start==end) return a[start];
	if(start>end) return -1;
	
	int i=start,j=end;
	threep(a,i,j);
	
	if(k>=i&&k<=j) return a[i];
	else if(k<i) return quickSearch_k(a,start,i-1,k);
	else return quickSearch_k(a,j+1,end,k);
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	int res=quickSearch_k(a,0,n-1,k-1);
	sort(a,a+k);   //找到第k大的数后，将0~k-1之间进行排序
	for(int i=k-1;i>=0;i--){
		cout<<a[i]<<endl;
	}
	return 0;
}