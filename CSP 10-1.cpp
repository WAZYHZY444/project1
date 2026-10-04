#include <iostream>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0,count=0,i=0;
	while(i<n){
		sum+=a[i++];
		if(i==n&&sum<k) count++;
		if(sum>=k){
			count++;
			sum=0;
		}
	}
	cout<<count;
	return 0;
}