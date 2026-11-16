#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int dp[n+1];
	int pre[n+1]={0};
	dp[0]=0;
	for(int i=1;i<=n;i++) dp[i]=1;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[j]<a[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
				pre[i]=j;
			}
		}
	}
	int res=1,pos=1;
	for(int i=1;i<=n;i++){
		if(res<dp[i]){
			res=dp[i];
			pos=i;
		}
	}
	vector<int> v;
	while(pos!=0){
		v.push_back(a[pos]);
		pos=pre[pos];
	}
	//输出最长上升子序列
	for(int i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";
	cout<<endl;
	//输出最长上升子序列长度
	cout<<res<<endl;
	return 0;
}