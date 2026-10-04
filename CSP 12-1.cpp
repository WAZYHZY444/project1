#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int temp=0;
	int minN=a[1]-a[0];
	for(int i=1;i<n-1;i++){
		temp=min((a[i]-a[i-1]),(a[i+1]-a[i]));
		if(temp<minN) minN=temp;
	}
	cout<<minN;
	return 0;
}