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
	if(n%2==0&&a[n/2-1]==a[n/2]){
		cout<<a[n/2];
	}
	if(n%2!=0&&a[n/2]!=a[n/2-1]&&a[n/2]!=a[n/2+1]){
		cout<<a[n/2];
	}
	else{
		cout<<-1;
	}
	return 0;
}