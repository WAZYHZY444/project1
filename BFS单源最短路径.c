#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_VERTICES 6

typedef struct{
	int data[MAX_VERTICES];
	int front;
	int rear;
}Queue;

void initQueue(Queue* q)
{
	q->front=q->rear=0;
}
bool isEmpty(Queue* q)
{
	return q->front==q->rear;
}
bool isFull(Queue* q)
{
	return q->rear==MAX_VERTICES;
}
void enQueue(Queue* q,int val)
{
	q->data[q->rear++]=val;
}
int deQueue(Queue* q)
{
	return q->data[q->front++];
}

//BFS求单源最短路径
void bfsShortestPath(int graph[MAX_VERTICES][MAX_VERTICES],int dist[MAX_VERTICES],int prev[MAX_VERTICES],int start)
{
	Queue q;
	initQueue(&q);
	//初始化距离和前驱顶点
	for(int i=0;i<MAX_VERTICES;i++){
		dist[i]=INT_MAX;
		prev[i]=-1;
	}
	//起点初始化
	dist[start]=0;
	enQueue(&q,start);
	while(!isEmpty(&q)){
		int cur=deQueue(&q);
		for(int i=0;i<MAX_VERTICES;i++){
			if(graph[cur][i]==1&&dist[i]==INT_MAX){ //有边且未被访问
				dist[i]=dist[cur]+1;
				prev[i]=cur;
				enQueue(&q,i);
			}
		}
	}
}

//打印最短路径
void printPath(int prev[],int start,int target)
{
	if(target==start){
		printf("%d",start);
		return;
	}
	if(prev[target]==-1){
		printf("无路径\n");
		return;
	}
	printPath(prev,start,prev[target]);
	printf("->%d",target);
}

int main()
{
	int graph[MAX_VERTICES][MAX_VERTICES]={0};
	//邻接矩阵表示图
	graph[0][1]=graph[1][0]=1;
	graph[0][2]=graph[2][0]=1;
	graph[1][4]=graph[4][1]=1;
	graph[1][3]=graph[3][1]=1;
	graph[2][4]=graph[4][2]=1;
	graph[3][5]=graph[5][3]=1;
	graph[4][5]=graph[5][4]=1;
	
	//需要两个数组：记录当前顶点到开始顶点的最短距离；记录当前顶点的前驱顶点
	int dist[MAX_VERTICES];
	int prev[MAX_VERTICES];
	//开始顶点
	int start=0;
	bfsShortestPath(graph,dist,prev,start);
	printPath(prev,start,5);
	return 0;
}

//留一个问题：怎么优化代码实现打印出所有的单源最短路径？