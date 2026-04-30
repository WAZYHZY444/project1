#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 100

typedef struct{
	int vertices[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //邻接矩阵
	int numVertices;  //顶点数
	int numEdges;  //边数
}Graph;

//初始化图
void InitGraph(Graph* g,int vertices)
{
	g->numVertices=vertices;
	g->numEdges=0;
	for(int i=0;i<MAX_VERTEX_NUM;i++){
		for(int j=0;j<MAX_VERTEX_NUM;j++){
			g->vertices[i][j]=0;
		}
	}
}

//插入边（无向图）
void AddEdge(Graph* g,int start,int end)  //start、end表示边两端所连接的顶点的下标
{
	if(start<0||start>=g->numVertices||end<0||end>=g->numVertices){
		return;
	}
	g->vertices[start][end]=1;
	g->vertices[end][start]=1;
	g->numEdges++;
}
//添加边（有向图）
void addDirectedEdge(Graph* g,int start,int end)
{
	if(start<0||start>=g->numVertices||end<0||end>=g->numVertices){
		return;
	}
	g->vertices[start][end]=1;
	g->numEdges++;
}

//打印邻接矩阵
void printGraph(Graph* g)
{
	printf("\n");
	for(int i=0;i<g->numVertices;i++){
		for(int j=0;j<g->numVertices;j++){
			printf("%d ",g->vertices[i][j]);
		}
		printf("\n");
	}
}


//队列相关操作
typedef struct{
	int data[MAX_VERTEX_NUM];
	int rear;
	int front;
}Queue;

//初始化队列
void InitQueue(Queue* q)
{
	q->front=q->rear=0;
}

bool isFull(Queue* q)
{
	return q->rear==MAX_VERTEX_NUM;
}

bool isEmpty(Queue* q)
{
	return q->front==q->rear;
}

//入队
void enqueue(Queue* q,int val)
{
	if(!isFull(q)){
		q->data[q->rear++]=val;
	}
}

//出队
int dequeue(Queue* q)
{
	if(!isEmpty(q)){
		return q->data[q->front++];
	}
	return -1;
}

//DFS算法
void DFS_Traverse(Graph* g,int vertex,bool visited[])
{
	visited[vertex]=true;
	printf("%d ",vertex);
	for(int i=0;i<g->numVertices;i++){
		if(g->vertices[vertex][i]==1&&!visited[i]){
			DFS_Traverse(g,i,visited);
		}
	}
}

void DFS(Graph* g,int vertex)
{
	bool visited[MAX_VERTEX_NUM]={false};  //visited数组只初始化一次
	DFS_Traverse(g,vertex,visited);
	printf("\n");
}

//BFS算法
void BFS(Graph* g,int start)
{
	bool visited[MAX_VERTEX_NUM]={false};
	Queue q;
	InitQueue(&q);
	visited[start]=true;
	enqueue(&q,start);
	while(!isEmpty(&q)){
		int v=dequeue(&q);
		printf("%d ",v);
		for(int i=0;i<g->numVertices;i++){
			if(g->vertices[v][i]==1&&!visited[i]){
				visited[i]=true;
				enqueue(&q,i);
			}
		}
	}
	printf("\n");
}

int main()
{
	Graph g;
	InitGraph(&g,4);
	addDirectedEdge(&g,0,1);
	addDirectedEdge(&g,0,2);
	addDirectedEdge(&g,1,2);
	addDirectedEdge(&g,2,3);
	printGraph(&g);
	printf("------------\n");
	DFS(&g,0);
	printf("------------\n");
	BFS(&g,0);
	return 0;
}