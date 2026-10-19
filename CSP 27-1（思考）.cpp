#include <iostream>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b[n]={0},c[n+1]={0};
	c[0]=1;
	for(int i=1;i<n+1;i++){
		c[i]=c[i-1]*a[i-1];
	}
	b[0]=(m%c[1])/c[0];
	int temp=0;
	for(int i=2;i<n+1;i++){
		temp+=b[i-2]*c[i-2];
		b[i-1]=(m%c[i]-temp)/c[i-1];
	}
	
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}