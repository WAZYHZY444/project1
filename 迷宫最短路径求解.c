#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct{
	int x,y;
	int step;  //从起点到该位置的步数
}Point;

typedef struct{
	Point data[MAX*MAX];
	int front,rear;
}Queue;

//用于记录前驱坐标
typedef struct{
	int x,y;
}PreNode;

PreNode prev[MAX][MAX]; //记录每个点的前一个结点

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
	return q->rear==MAX*MAX;
}

void enQueue(Queue* q,Point p)
{
	if(isFull(q)) return;
	q->data[q->rear++]=p;
}

Point deQueue(Queue* q)
{
	return q->data[q->front++];
}

//方向数组：上、下、左、右
int dx[]={-1,1,0,0};  //行坐标变化
int dy[]={0,0,-1,1};  //列坐标变化

int bfs(int maze[MAX][MAX],int n,int m,Point start,Point end,Point path[],int* pathLen)
{
	bool visited[MAX][MAX]={false};  //访问标记数组
	Queue q;
	initQueue(&q);
	
	//起点初始化
	start.step=0;
	enQueue(&q,start);  //起点入队
	visited[start.x][start.y]=true;
	prev[start.x][start.y]=(PreNode){-1,-1};  //起点前驱为(-1,-1)  [强制类型转换]
	
	//BFS
	while(!isEmpty(&q)){
		Point cur=deQueue(&q);
		
		//找到终点
		if(cur.x==end.x&&cur.y==end.y){
			int count=0;
			int x=end.x;
			int y=end.y;
			//循环回溯，直到回到起点
			while(x!=-1&&y!=-1){
				//记录当前点
				path[count].x=x;
				path[count].y=y;
				count++;
				//获得前驱点坐标
				int tx=prev[x][y].x;
				int ty=prev[x][y].y;
				x=tx;
				y=ty;
			}
			//path中存储的顺序是：终点->...->起点
			//反转
			for(int i=0;i<count/2;i++){
				Point temp=path[i];
				path[i]=path[count-1-i];
				path[count-1-i]=temp;
			}
			*pathLen=count;  //返回路径长度
			return cur.step; //返回最短步数
		}
		
		//未找到终点
		for(int i=0;i<4;i++){  //遍历四个方向
			int nx=cur.x+dx[i];
			int ny=cur.y+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&maze[nx][ny]==0){
				visited[nx][ny]=true;
				prev[nx][ny]=(PreNode){cur.x,cur.y};  //记录前驱
				
				Point next;
				next.x=nx;
				next.y=ny;
				next.step=cur.step+1;
				enQueue(&q,next);
			}
		}
	}
	return -1;
}

int main()
{
	int m,n;
	scanf("%d %d",&n,&m);
	int maze[MAX][MAX]; //存储迷宫的地图
	//0可走，1障碍
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&maze[i][j]);
		}
	}
	Point start,end;
	scanf("%d %d",&start.x,&start.y);  //起点的坐标
	scanf("%d %d",&end.x,&end.y);  //钟点的坐标
	
	if(maze[start.x][start.y]==1||maze[end.x][end.y]==1){
		printf("起点或终点是障碍物，无法求解\n");
		return 0;
	}
	
	Point path[MAX*MAX];  //存储路径的数组
	int pathLen=0;        //路径长度
	int steps=bfs(maze,n,m,start,end,path,&pathLen);
	
	if(steps!=-1){
		printf("最短路径长度为：%d\n",steps);
		for(int i=0;i<pathLen;i++){
			printf("(%d %d)",path[i].x,path[i].y);
			if(i!=pathLen-1){
				printf(" -> ");
			}
		}
		printf("\n");
	}
	return 0;
}