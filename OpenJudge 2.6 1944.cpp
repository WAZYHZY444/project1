#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int f[n];
	f[1]=1,f[2]=2;
	if(n==1||n==2){
		cout<<f[n]<<endl;
		return 0;
	}
	for(int i=3;i<=n;i++){
		f[i]=f[i-1]+f[i-2];
	}
	cout<<f[n]<<endl;
	return 0;
}