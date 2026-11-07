#include <iostream>
#include <algorithm>

using namespace std;

int DP(char s[],char t[],int m,int n)
{
	
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++) dp[i][0]=0;
	for(int j=0;j<=n;j++) dp[0][j]=0;
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	return dp[m][n];
}

int main()
{
	int m,n;
	cin>>m>>n;
	char s[m+1],t[n+1];
	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	int res=DP(s,t,m,n);
	cout<<res<<endl;
	return 0;
}