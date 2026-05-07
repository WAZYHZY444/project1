#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5 //途中顶点数量

int minKey(int key[],bool mstSet[])
{
	int min_index;
	int min=INT_MAX;
	for(int v=0;v<V;v++){
		if(mstSet[v]==false&&key[v]<min){  //只访问还未被访问的，且与新加入的节点连接
			min=key[v];  //更新min值，当再次循环时就可以更新比上一轮权值更小的顶点
			min_index=v;
		}
	}
	return min_index;
}

//打印MST
void printMST(int parent[],int graph[V][V])
{
	printf("边\t权值\n");
	for(int i=1;i<V;i++){
		printf("%d - %d\t%d\n",parent[i],i,graph[i][parent[i]]);
	}
}

void primMST(int graph[V][V])
{
	int parent[V]; //存储MST
	int key[V];    //存储每个顶点到MST的最小权值
	bool mstSet[V]; //标记顶点是否已包含在MST中
	
	//初始化
	for(int i=0;i<V;i++){
		key[i]=INT_MAX;  //每个顶点距离最小生成树无穷远
		mstSet[i]=false; //所有顶点还未访问
	}
	
	//从第0个顶点开始
	key[0]=0;
	parent[0]=-1;
	
	//构建MST
	for(int count=0;count<V-1;count++){
		//选择未包含在MST中且权值最小的顶点
		int u=minKey(key,mstSet);
		mstSet[u]=true;  //标记当前顶点u已被访问
		
		//更新相邻顶点的权值和父节点
		for(int v=0;v<V;v++){
			//遍历所有还未加入MST的顶点，如果其中有顶点v到新加入的顶点u的权值小于该顶点当前记录的权值，
			//则该顶点的加入是与先加入的顶点u相连接，u是v的父节点
			if(graph[u][v]&&mstSet[v]==false&&graph[u][v]<key[v]){
				parent[v]=u;
				key[v]=graph[u][v];
			}
		}
	}
	printMST(parent,graph);
}

int main()
{
	//邻接矩阵表示图
	int graph[V][V]={
		{0,2,0,6,0},
		{2,0,3,8,5},
		{0,3,0,0,7},
		{6,8,0,0,9},
		{0,5,7,9,0}
	};
	primMST(graph);
	return 0;
}