#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const string& a,const string& b)
{
	return a+b>b+a;
}

int main()
{
	int n;
	cin>>n;
	string a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	string res;
	for(int i=0;i<n;i++){
		res+=a[i];
	}
	cout<<res;
	return 0;
}