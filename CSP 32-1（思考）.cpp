#include <iostream>

using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		bool print=false;
		for(int j=0;j<n;j++){
			int tag=1;
			for(int k=0;k<m;k++){
				if(a[j][k]<=a[i][k]){
					tag=0;
					break;
				}
			}
			if(tag==1){
				print=true;
				cout<<j+1<<endl;
				break;
			}
		}
		if(print==false) cout<<0<<endl;
	}
	return 0;
}