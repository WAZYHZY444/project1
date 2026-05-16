#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_VERTICES 100
//打印最短路径
void printPath(int parent[],int i)
{
	if(parent[i]==-1){
		printf("%d",i);
		return;
	}
	printPath(parent,parent[i]);
	printf(" ->%d",i);
}

//打印源点到其他顶点的最短距离和路径
void printResult(int dist[],int parent[],int vertices,int start)
{
	printf("顶点\t 距离\t\t路径\n");
	for(int i=0;i<vertices;i++){
		if(i==start){
			printf("%d -> %d\t %d\t\t%d\n",start,i,dist[i],i);
		}else if(dist[i]!=INT_MAX){
			printf("%d -> %d\t %d\t\t",start,i,dist[i]);
			printPath(parent,i);
			printf("\n");
		}else{
			printf("%d -> %d\t INF\t\t没有路径\n",start,i);
		}
	}
}

//查找距离最短的未访问的顶点
int findMinDistance(int dist[],bool visited[],int vertices)
{
	int min=INT_MAX;
	int min_index=-1;
	for(int v=0;v<vertices;v++){
		if(!visited[v]&&dist[v]<=min){
			min=dist[v];
			min_index=v;
		}
	}
	return min_index;
}

//Dijkstra算法实现
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES],int start,int vertices)
{
	int dist[MAX_VERTICES];  //存储从源点到各顶点的最短距离
	int parent[MAX_VERTICES];  //存储最短路径树（当前顶点的前驱）
	bool visited[MAX_VERTICES];  //标记顶点是否被处理过
	
	//初始化
	for(int i=0;i<vertices;i++){
		dist[i]=INT_MAX;
		parent[i]=-1;
		visited[i]=false;
	}
	//源点到自身的距离为0
	dist[start]=0;
	
	for(int count=0;count<vertices-1;count++){
		//选择距离最小的未处理的顶点
		int u=findMinDistance(dist,visited,vertices);
		if(u==-1) break;  //剩余所有顶点都不可到达
		
		visited[u]=true;
		
		//更新相邻顶点的距离（与Prim算法相似）
		for(int v=0;v<vertices;v++){
			if(!visited[v]&&graph[u][v]!=INT_MAX&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v]){
				dist[v]=dist[u]+graph[u][v];
				parent[v]=u;
			}
		}
	}
	
	//打印结果
	printResult(dist,parent,vertices,start);
}

int main()
{
	int vertices=5;
	int graph[MAX_VERTICES][MAX_VERTICES];
	//初始化邻接矩阵
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			if(i==j)
				graph[i][j]=0;
			else
				graph[i][j]=INT_MAX;
		}
	}
	graph[0][1]=10;
    graph[0][3]=5;
    graph[1][2]=1;
    graph[1][3]=2;
    graph[2][4]=4;
    graph[3][1]=3;
    graph[3][2]=9;
    graph[3][4]=2;
    graph[4][2]=6;
    graph[4][0]=7;
    
    dijkstra(graph,0,vertices);
    return 0;
}