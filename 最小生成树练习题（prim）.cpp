/*
(最小生成树)
输入:包含1~100个数据集，最后一行为0，每个数据集第一行为村落数目n，1<n<27，依次用字母表的前n个字母标记。接下来有n-1行，
每行的第一个数据便是按字母顺序排列的村子编号（不包括最后一个村庄）。每个村庄后面的数据k代表该村庄通往编号在其之后的村庄的道路数目，
如 A 2 B 12 I 25，代表A村庄有2个编号在A之后的村庄和其相连。若k大于0，k后面会依次给出这k个村庄的编号以及各自到起始村庄的道路维修费用，
如 A 2 B 12 I 25，代表A和B之间道路维修费用为12，A和I之间道路维修费用为25（维修费用为不超过100的正整数），路的总数目不超过75条，
每个村庄不会有超过15条路（包括编号在其之前和之后）。
输出：每个数据集有一个输出：根据最小生成树，输出最少总的维修费用
样例输入：
9
A 2 B 12 I 25
B 3 C 10 H 40 I 8
C 2 D 18 G 55
D 1 E 44
E 2 F 60 G 38
F 0
G 1 H 35
H 1 I 35
3
A 2 B 10 C 40
B 1 C 20
0

输出：
216
30
*/

#include <iostream>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;

const int MAXN=30;  //最多27个村庄

int minKey(int n,int key[],bool visited[])
{
	int min_index=-1;
	int min=INT_MAX;
	for(int i=0;i<n;i++){
		if(!visited[i]&&key[i]<min){
			min=key[i];
			min_index=i;
		}
	}
	return min_index;
}

int primMST(int graph[MAXN][MAXN],int n)
{
	int parent[MAXN];  //记录与i连接的那个顶点
	int key[MAXN];     //记录i到已经加入MST的顶点的最短距离
	bool visited[MAXN];//标记i是否已经加入到MST了
	
	//初始化
	for(int i=0;i<n;i++){
		visited[i]=false;
		key[i]=INT_MAX;
	}

	parent[0]=-1;  //从0开始，0是第一个加进MST的
	key[0]=0;

	for(int i=1;i<n;i++){
		int u=minKey(n,key,visited);  //在还未加入MST的顶点中找到最小权值的顶点u
		visited[u]=true;

		for(int j=0;j<n;j++){
			if(graph[u][j]&&visited[j]==false&&graph[u][j]<key[j]){
				key[j]=graph[u][j];
				parent[j]=u;
			}
		}
	}

	int sum=0;
	for(int k=0;k<n;k++){
		sum+=key[k];
	}
	return sum;
}

int main()
{
	vector<int> result;  //存储每一组的结果
	int n;
	
	//不同组（n）就需要全新的邻接矩阵
	while(cin>>n&&n!=0){
		int graph[MAXN][MAXN];
		//初始化邻接矩阵为0
		memset(graph,0,sizeof(graph));
		
		//读取n-1行
		for(int i=0;i<n-1;i++){
			char village;
			int k;
			cin>>village>>k;   //读取每行的第一个村庄和道路数量
			
			int u=village-'A';  //将字母转换成索引
			
			for(int j=0;j<k;j++){
				char neighbor;
				int cost;
				cin>>neighbor>>cost;
				
				int v=neighbor-'A';
				graph[u][v]=cost;
				graph[v][u]=cost;
			}
		}
		result.push_back(primMST(graph,n));
	}
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<"\n";
	}
	return 0;
}