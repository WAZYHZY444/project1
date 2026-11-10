#include <iostream>

using namespace std;

int main()
{
	int n,m,p,q;
	cin>>n>>m>>p>>q;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int b[n*m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[i*m+j]=a[i][j];
		}
	}
	for(int i=0;i<n*m;i++){
		cout<<b[i]<<" ";
		if((i+1)%q==0) cout<<endl;	
	}
	return 0;
}