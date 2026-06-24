//单源最短路径算法，计算的是给定的起点到任意点的路径；多源运行一次，计算的任意两个点之间的路径。
//即使给定起点终点，只会影响最终输出的结果，不会影响代码运行所执行的次数

//BFS
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

const int MAXN=100;

//Dijkstra算法需要计算最短的边（与Prim类似），因为他一般处理的是有权图，而BFS处理的是无权图，只需要判断graph是否等于1（通路）即可，不需要找最小

void printPath(int prev[],int n,int start,int target)
{
	
	if(start==target){
		cout<<start;
                return;
	}
	if(prev[target]==-1) return;
	printPath(prev,n,start,prev[target]);
	cout<<"->"<<target;
	
}

void bfs(int graph[MAXN][MAXN],int n,int start)
{
	int dist[MAXN];
	int prev[MAXN];
	bool visited[MAXN]={false};
	for(int i=0;i<n;i++){
		dist[i]=INT_MAX;
		prev[i]=-1;
	}
	
	queue<int> q;
	dist[start]=0;
	visited[start]=true;
	q.push(start);
	
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		//假设指定了终点target
//		if(cur==target) reutrn dist[cur];
		for(int i=0;i<n;i++){
			if(!visited[i]&&graph[cur][i]==1){
				dist[i]=dist[cur]+1;
				prev[i]=cur;
				visited[i]=true;
				q.push(i);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		if(dist[i]==INT_MAX) continue;
		printPath(prev,n,start,i);
                cout<<"\n";
	}
		
}

int main()
{
	int n;
	cin>>n;
	int graph[MAXN][MAXN];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	int start=0;
	bfs(graph,n,start);
	return 0;
}


#include <iostream>
#include <climits>

using namespace std;

const int MAXN=100;

void printPath(int prev[],int n,int start,int target)
{
	if(target==start){
		cout<<start;
		return;
	}
	if(prev[target]==-1) return;
	printPath(prev,n,start,prev[target]);
	cout<<"->"<<target;
}

int minKey(bool visited[],int dist[],int n)
{
	int min=INT_MAX;
	int min_index=-1;
	for(int i=0;i<n;i++){
		if(!visited[i]&&dist[i]<min){
			min=dist[i];
			min_index=i;
		}
	}
	return min_index;
}

void Dijkstra(int graph[MAXN][MAXN],int n,int start)
{
	int dist[MAXN];
	int prev[MAXN];
	bool visited[MAXN]={false};
	for(int i=0;i<n;i++){
		dist[i]=INT_MAX;
		prev[i]=-1;
	}
	
	dist[start]=0;   //注意：Dijksra初始化时不需要将visited[start]=true,避免循环时跳过start
	
	for(int i=0;i<n-1;i++){
		int u=minKey(visited,dist,n);
		if(u==-1) break;
		visited[u]=true;
		for(int j=0;j<n;j++){
			if(!visited[j]&&graph[u][j]!=-1&&dist[u]+graph[u][j]<dist[j]){
				dist[j]=dist[u]+graph[u][j];
				prev[j]=u;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		if(dist[i]==INT_MAX) continue;
		printPath(prev,n,start,i);
		cout<<"\n";
	}
}


int main()
{
	int n;
	cin>>n;
	int graph[MAXN][MAXN];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	int start=0;
	Dijkstra(graph,n,start);
	return 0;
}


//Floyd算法(权重可以为负，所以就只能用INT_MAX来表示不连通
#include <iostream>
#include <climits>

using namespace std;
const int MAXN=100;

void printPath(int i,int j,int mid[MAXN][MAXN])
{
	if(mid[i][j]==-1){
		cout<<"->"<<j;
		return;
	}
	int p=mid[i][j];
	printPath(i,p,mid);  //打印i->p的路径
	printPath(p,j,mid);  //打印p->j的路径
}

void Floyd(int graph[MAXN][MAXN],int n)
{
	int dist[MAXN][MAXN];  //存储最终最短路径的矩阵
	int mid[MAXN][MAXN];  //存储中转顶点
	bool visited[MAXN]={false};
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dist[i][j]=graph[i][j];
			mid[i][j]=-1;
		}
	}
	
	for(int k=0;i<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX&&dist[i][k]+dist[k][j]<dist[i][j])
				dist[i][j]=dist[i][k]+dist[k][j];
				mid[i][j]=k;  //表示i与j之间的中间点为k
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j&&dist[i][j]!=INT_MAX){
				printPath(i,j,mid);
				cout<<"\n";
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int graph[MAXN][MAXN];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	Floyd(graph,n);
	return 0;
}