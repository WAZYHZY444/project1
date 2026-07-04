/*两点之间是否有路径
问题描述：输入一个有向图，问是否存在一条从u点到v点的路径
输入形式：
第一行输入节点个数n(1<=n<=1000)，边的条数m(1<=m<=10000)，和u,v的组数q(1<=q<=1000);
下面m行输入m条边的起点和终点，起点终点都在范围之内，不存在重边。
下面q行输入q组（u,v),u,v都在范围之内。
输出形式：
按照q组输入的顺序，依次输出所有的（u,v）是否存在路径
样例输入：
3 3 2
1 2
2 3
1 3
1 2
2 1
样例输出:
YES
NO
样例说明：
点1到2之间存在路径，点2到1之间不存在路径。
提示：
本题可以基于floyd算法建立一个bool型的connect矩阵，如果connect[i][k]&&connect[k][j]则connect[i][j]为真。
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	
	int graph[n][n];
	vector<string> result;
	
	for(int i=0;i<m;i++){
		int from,to;
		cin>>from>>to;
		graph[from][to]=1;	
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(graph[i][k]==1){
				for(int j=1;j<=n;j++){
					if(graph[k][j]==1){
						graph[i][j]=1;
					}
				}
			}
		}
	}
	
	for(int j=0;j<q;j++){
		int u,v;
		cin>>u>>v;
		if(graph[u][v]==1){
			result.push_back("YES");
		}else{
			result.push_back("NO");
		}
	}
	
	for(string s:result){
		cout<<s<<endl;
	}
	return 0;
}