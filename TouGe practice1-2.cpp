#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<a[0];
		return 0;
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if(i==0){
			if(a[i]>a[i+1]){
				sum+=a[i];
			}
		}
		if(i!=0&&i!=n-1&&a[i]>a[i-1]&&a[i]>a[i+1]){
			sum+=a[i];
		}
		if(i!=0&&i!=n-1&&a[i]<a[i-1]&&a[i]<a[i+1]){
			sum-=a[i];
		}
		if(i==n-1){
			if(a[i]>a[i-1]){
				sum+=a[i];
			}
		}
	}
	cout<<sum;
	return 0;
}