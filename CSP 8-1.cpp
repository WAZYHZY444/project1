#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int res=0;
	for(int i=1;i<n;i++){
		int temp=abs(a[i]-a[i-1]);
		res=max(res,temp);
	}
	cout<<res<<endl;
	return 0;
}