#include <iostream>

using namespace std;

int solve(int T,int M,int t[],int v[])
{
	int m[M+1][T+1];
	for(int i=0;i<T+1;i++){
		m[0][i]=0;
	}
	
	for(int i=1;i<=M;i++){
		for(int j=0;j<=T;j++){
			if(t[i]<=j){
				m[i][j]=max(m[i-1][j],m[i-1][j-t[i]]+v[i]);
			}
			else{
				m[i][j]=m[i-1][j];
			}
		}
	}
	return m[M][T];
}

int main()
{
	int T,M;
	cin>>T>>M;
	int t[M+1],v[M+1];
	for(int i=1;i<=M;i++){
		cin>>t[i]>>v[i];
	}
	cout<<solve(T,M,t,v)<<endl;
	return 0;
}