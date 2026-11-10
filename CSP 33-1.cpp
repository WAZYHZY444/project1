#include <iostream>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int res[m+1]={0};
	int count[m+1]={0};
	
	for(int i=0;i<n;i++){
		int sum;
		cin>>sum;
		int word[sum];
		for(int j=0;j<sum;j++){
			cin>>word[j];
		}
		bool visited[m+1]={false};
		for(int j=0;j<sum;j++){
			res[word[j]]++;
			if(visited[word[j]]==false){
				count[word[j]]++;
				visited[word[j]]=true;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<count[i]<<" "<<res[i]<<endl;
	}
	return 0;
}