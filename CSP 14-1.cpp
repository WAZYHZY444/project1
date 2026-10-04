#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v1(n);
	vector<int> v2(n);
	for(int i=0;i<n;i++){
		cin>>v1[i];
	}
	v2[0]=(v1[0]+v1[1])/2;
	v2[n-1]=(v1[n-2]+v1[n-1])/2;
	
	for(int i=1;i<n-1;i++){
		v2[i]=(v1[i-1]+v1[i]+v1[i+1])/3;
	}
	
	for(int i=0;i<n;i++){
		cout<<v2[i]<<" ";
	}
	return 0;
}