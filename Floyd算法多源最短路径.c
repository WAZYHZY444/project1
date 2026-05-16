#include <stdio.h>
#include <limits.h>
#define V 4

//打印路径
void printPath(int i,int j,int path[][V])
{
	if(path[i][j]==-1){  //没有中转顶点，直接相连
		printf(" -> %d",j);
		return;
	}
	int mid=path[i][j];
	printPath(i,mid,path); //打印i->mid的路径
	printPath(mid,j,path); //打印mid->j的路径
}

//floyd算法
void floyd(int graph[][V])
{
	int dist[V][V];  //存储最终最短路径的矩阵
	int path[V][V];  //存储中转顶点
	//初始化
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			dist[i][j]=graph[i][j];
			path[i][j]=-1;
		}
	}
	
	//Floyd算法的核心：三重循环
	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX&&dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=k;  //记录中间顶点
				}
			}
		}
	}
	
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(i!=j&&dist[i][j]!=INT_MAX){
				printf("%d到%d(距离=%d):%d",i,j,dist[i][j],i);
				printPath(i,j,path);
				printf("\n");
			}
		}
	}
}

int main()
{
	int graph[V][V]={
		{0,5,INT_MAX,10},
		{INT_MAX,0,3,INT_MAX},
		{INT_MAX,INT_MAX,0,1},
		{INT_MAX,INT_MAX,INT_MAX,0}
	};
	floyd(graph);
	return 0;
}