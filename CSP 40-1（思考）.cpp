#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<vector<int>> v1(m);
	for(int i=0;i<m;i++){
		int s;
		cin>>s;
		for(int j=0;j<s;j++){
			int index;
			cin>>index;
			v1[i].push_back(index);
		}
	}
	vector<vector<int>> v2(m);
	for(int i=0;i<m;i++){
		int s;
		cin>>s;
		for(int j=0;j<s;j++){
			int index;
			cin>>index;
			v2[i].push_back(index);
		}
	}
	vector<string> res;  //存储输出结果
	for(int i=0;i<m;i++){
		int f=0,t=0;
		for(int u=0;u<v1[i].size();u++){
			f^=a[v1[i][u]];
		}
		for(int v=0;v<v2[i].size();v++){
			t^=a[v2[i][v]];
		}
		bool isSame=(v1[i]==v2[i]);
		if(isSame){
			cout<<"correct\n";
		}
		else{
			if(f!=t) cout<<"correct\n";
			else cout<<"wrong\n";
		}
	}
	return 0;
}