#include <iostream>

using namespace std;

int main()
{
	int n,N;
	cin>>n>>N;
	int a[n+2];
	a[0]=0;
	a[n+1]=N;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=0;
	for(int i=1;i<n+2;i++){
		sum+=(a[i]-a[i-1])*(i-1);
	}
	cout<<sum;
	return 0;
}