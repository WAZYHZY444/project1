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
	int max=0,min=0;
	for(int i=0;i<n;i++){
		max+=a[i];
		if(i>0&&a[i]==a[i-1]) min+=0;
		else min+=a[i];
	}
	cout<<max<<endl;
	cout<<min<<endl;
	return 0;
}