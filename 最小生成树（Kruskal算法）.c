#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Kruskal算法主要操作：
//  1.提取所有边的信息，将边根据权重排序
//  2.判断权值较小的变得两个端点是否与当前集合连通（避免生成环），不连通则加入集合

#define V 5  //顶点数量

//边的结构体（用于存储从邻接矩阵中提取到的边）
typedef struct{
	int src;    //源顶点
	int dest;      //目标顶点
	int weight; //权重
}Edge;

int extractEdges(int graph[V][V],Edge edges[])
{
	int edgeCount=0;
	for(int i=0;i<V;i++){
		for(int j=i+1;j<V;j++){
			if(graph[i][j]!=0){
				edges[edgeCount].src=i;
				edges[edgeCount].dest=j;
				edges[edgeCount].weight=graph[i][j];
				edgeCount++;
			}
		}
	}
	return edgeCount;
}

int find(int parent[],int i)
{
	if(parent[i]!=i){
		parent[i]=find(parent,parent[i]);
	}
	return parent[i];
}

void unionSet(int parent[],int rank[],int x,int y)
{
	int rootX=find(parent,x);  //找到x的根节点
	int rootY=find(parent,y);  //找到y的根节点
	//把较浅的树合并到较深的树上，避免树退化成链表
	if(rank[rootX]<rank[rootY]){
		parent[rootX]=rootY;
	}else if(rank[rootX]>rank[rootY]){
		parent[rootY]=rootX;
	}else{
		//深度相同
		parent[rootY]=rootX;
		rank[rootX]++;
	}
}

//qsort排序函数
int compareEdges(const void* e1,const void* e2)
{
	return ((Edge*)e1)->weight-((Edge*)e2)->weight;
}

void kruskalMST(int graph[V][V])
{
	//无向完全图的边数为V*(V-1)/2
	int maxEdges=V*(V-1)/2;
	Edge edges[maxEdges]; //存储所有边
	Edge result[V-1];     //存储MST的边（最小生成树有V-1条边）
	
	//从邻接矩阵中提取所有的边存储到edges中
	int edgeCount=extractEdges(graph,edges);
	
	//按权重升序排序所有的边
	qsort(edges,edgeCount,sizeof(Edge),compareEdges);
	
	//初始化并查集
	int parent[V]; //父节点数组
	int rank[V];   //记录树的深度
	for(int i=0;i<V;i++){
		parent[i]=i;  //初始化所有顶点都是根
		rank[i]=0;    //每棵树初始深度为0
	}
	
	int resultCount=0;  //已选中的边数
	int i=0;
	while(resultCount<V-1&&i<edgeCount){
		Edge currentEdge=edges[i++]; //取出当前最小权重的边
		
		//查找边的两个端点所在集合
		int rootSrc=find(parent,currentEdge.src);
		int rootDest=find(parent,currentEdge.dest);
		//两个顶点不在同一个集合，可以加入
		if(rootSrc!=rootDest){
			result[resultCount++]=currentEdge;  //将边加入MST
			unionSet(parent,rank,rootSrc,rootDest);  //合并两个集合
		}
	}
	
	//输出MST
	printf("边\t权值\n");
	int totalWeight=0;
	for(int i=0;i<resultCount;i++){
		printf("%d - %d\t%d\n",result[i].src,result[i].dest,result[i].weight);
		totalWeight+=result[i].weight;
	}
	printf("总权值：%d\n",totalWeight);
	if(resultCount<V-1){
		printf("图不连通，生成的是森林！\n");
	}
}

int main()
{
	int graph[V][V]={
		{0,2,0,6,0},
		{2,0,3,8,5},
		{0,3,0,0,7},
		{6,8,0,0,9},
		{0,5,7,9,0}
	};
	kruskalMST(graph);
	return 0;
}

//为什么需要rank数组来记录树的深度？
//  因为这里的parent数组在初始化时parent[i]=i，就确定了根节点parent数组记录的是自己本身，
//  不能记录集合的定点数量，所以需要额外一个数组来专门记录树的高度，方面unionSet操作