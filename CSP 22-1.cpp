#include <iostream>

using namespace std;

int main()
{
	int n,m,L;
	cin>>n>>m>>L;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int h[L]={0};
	int j=0;
	while(j<L){
		for(int i=0;i<n*m;i++){
			int count=0;
			if(a[i]==j){
				h[j]++;
			}
		}
		j++;
	}
	for(int k=0;k<L;k++){
		cout<<h[k]<<" ";
	}
	return 0;
}