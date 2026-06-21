#include <iostream>
#include <queue>
#include <climits>

using namespace std;

const int MAX_VERTICES=6;

void bfsShortestPath(int graph[MAX_VERTICES][MAX_VERTICES],int dist[],int prev[],int start)
{
	queue<int> q;
	//初始化距离和前驱顶点
	for(int i=0;i<MAX_VERTICES;i++){
		dist[i]=INT_MAX;
		prev[i]=-1;
	}
	
	//起点初始化
	dist[start]=0;
	q.push(start);
	while(!q.empty()){
		int cur=q.front();   //获取队首元素
		q.pop();
		for(int i=0;i<MAX_VERTICES;i++){
			if(graph[cur][i]==1&&dist[i]==INT_MAX){ //有边且未被访问
				dist[i]=dist[cur]+1;
				prev[i]=cur;
				q.push(i);
			}
		}
	}
}

//打印最短路径
void printPath(int prev[],int start,int target)
{
	if(target==start){
		cout<<start;
		return;
	}
	if(prev[target]==-1){
		cout<<"无路径\n";
		return;
	}
	printPath(prev,start,prev[target]);
	cout<<"->"<<target;
}

int main()
{
	int graph[MAX_VERTICES][MAX_VERTICES]={
	    {0,1,1,0,0,0},
	    {1,0,0,1,1,0},
	    {1,0,0,0,1,0},
	    {0,1,0,0,0,1},
	    {0,1,1,0,0,1},
	    {0,0,0,1,1,0}
	};
	
	//需要两个数组：记录当前顶点到开始顶点的最短距离；记录当前顶点的前驱顶点
	int dist[MAX_VERTICES];
	int prev[MAX_VERTICES];
	//开始顶点
	int start=0;
	bfsShortestPath(graph,dist,prev,start);
	printPath(prev,start,5);  //0->5的最短单源路径
	
	return 0;
}