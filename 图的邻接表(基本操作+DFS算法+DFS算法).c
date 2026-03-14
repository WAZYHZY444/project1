#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100   //定点最多数量
#define VertexType int       //便于修改存储的数据的类型

//边表节点（邻接表的“链表节点”）
typedef struct ArcNode{
	int adjvex;            //存储这条边指向的顶点下标
	struct ArcNode* next;  //指向下一条边的指针（下一个节点）
	int weight;            //边的权值
}ArcNode;

//顶点表节点
typedef struct VNode{
	VertexType data;    //顶点信息
	ArcNode* first;     //指向顶点第一条边的指针（链表的头指针）
}VNode,AdjList[MAX_VERTEX_NUM];  //相当于一个数组中每个元素的类型是VNode，然后把这个数组取别名为AdjList

//图的定义
typedef struct{
	AdjList vertices;  //相当于VNode vertices[MAX_VERTEX_NUM];
	int vexnum;        //当前顶点数量
	int arcnum;        //当前边的数量
	int graphType;     //0表示是无向图，1表示是有向图
}ALGraph;


//初始化图
void InitGraph(ALGraph* G,int vexnum,int type)   //type取值0或1，决定是无向图还是有向图
{
	G->vexnum=vexnum;
	G->arcnum=0;
	G->graphType=type;
	//初始化顶点表
	for(int i=0;i<vexnum;i++){   //数组的每一个元素都是VNode结构体类型
		G->vertices[i].data=i;   //默认顶点编号为索引值，从0开始
		G->vertices[i].first=NULL;
	}
}

//创建新边节点
ArcNode* CreateArcNode(int adjvex,int weight)  //创建的每条边有所指向下个顶点的下标，以及该条边的权值
{
	ArcNode* node=(ArcNode*)malloc(sizeof(ArcNode));
	if(!node){   //节点创建失败，返回NULL
		return NULL;
	}
	node->adjvex=adjvex;
	node->weight=weight;
	node->next=NULL;
	return node;
}

//求顶点的第一个邻接点
//返回顶点v的第一个邻接点的下标，如果没有邻接点返回-1
int FirstNeighbor(ALGraph* G,int v)
{
	if(v<0||v>=G->vexnum){
		return -1;
	}
	ArcNode* p=G->vertices[v].first;
	if(p!=NULL){
		return p->adjvex;
	}
	return -1;
}

//求顶点的下一个邻接点
//返回顶点v的下一个邻接点的下标，如果没有返回-1
int NextNeighbor(ALGraph* G,int v,int w)  //v-当前顶点，w-当前邻接点
{
	if(v<0||v>=G->vexnum||w<0||w>=G->vexnum){
		return -1;
	}
	ArcNode* p=G->vertices[v].first;
	while(p!=NULL&&p->adjvex!=w){
		p=p->next;
	}
	//跳出循环，p->adjvex==w
	if(p!=NULL&&p->next!=NULL){  //找到了w,w后面还有节点
		return p->next->adjvex;
	}
	return -1;
}

//获取边(v,w)的权值
int GetWeight(ALGraph* G,int v,int w)
{
	if(v<0||v>=G->vexnum||w<0||w>=G->vexnum){
		return -1;
	}
	ArcNode* p=G->vertices[v].first;
	while(p!=NULL){
		if(p->adjvex==w){
			return p->weight;
		}
		p=p->next;
	}
	return -1;
}

//插入边
void AddEdge(ALGraph* G,int start,int end,int weight)  //start、end表示边两端所连接的顶点的下标
{
	if(start<0||start>=G->vexnum||end<0||end>=G->vexnum){  //顶点编号从0开始，顶点下标最大值比顶点总数小1
		return;
	}
	//头插法插入边
	ArcNode* newnode=CreateArcNode(end,weight);
	if(!newnode){
		return;
	}
	newnode->next=G->vertices[start].first;
	G->vertices[start].first=newnode;
	//无向图还需要记录反向边
	if(G->graphType==0){   //无向图
		ArcNode* newnode2=CreateArcNode(start,weight);
		newnode2->next=G->vertices[end].first;
		G->vertices[end].first=newnode2;
		G->arcnum+=2;    //增加存储的边数，不是增加概念上的边数
	}else{               //有向图
		G->arcnum++;
	}
}

//删除边
void RemoveEdge(ALGraph* G,int start,int end)
{
	if(start<0||start>=G->vexnum||end<0||end>=G->vexnum){
		return;   //函数返回类型是void，所以就不能写return -1;
	}
	ArcNode* prev=NULL;  //前驱指针
	ArcNode* curr=G->vertices[start].first;  //当前指针指向头节点
	while(curr!=NULL&&curr->adjvex!=end){    //注意这里的判断条件
		prev=curr;
		curr=curr->next;
	}
	//执行if后面的代码，跳出循环，执行if后面的代码，表明当前指针指向的就是要删除的节点
	if(curr!=NULL){
		if(prev!=NULL){
			prev->next=curr->next;
		}else{   //prev=NULL,说明要删除的是第一个节点
			G->vertices[start].first=curr->next;
		}
		free(curr);
		G->arcnum--;  //边数少1
	}
	//如果是无向图，需要删除反向边
	if(G->graphType==0){
		prev=NULL;
		curr=G->vertices[end].first;
		while(curr!=NULL&&curr->adjvex!=start){
			prev=curr;
			curr=curr->next;
		}
		if(curr!=NULL){
			if(prev!=NULL){
				prev->next=curr->next;
			}else{
				G->vertices[end].first=curr->next;
			}
			free(curr);
			G->arcnum--;
		}
	}
}                                                                                                                                                               

//查找边是否存在
bool HasEdge(ALGraph* G,int start,int end)
{
	ArcNode* curr=G->vertices[start].first;  //查的是连接该节点的一条边，所以指针应该指向头节点
	while(curr!=NULL){
		if(curr->adjvex==end){
			return true;
		}
		curr=curr->next;  //遍历链表，查找是否有要判断的边
	}
	return false;
}

//获取顶点的度
int GetDegree(ALGraph* G,int vertex)
{
	if(vertex<0||vertex>=G->vexnum){
		return -1;
	}
	int degree=0;
	ArcNode* curr=G->vertices[vertex].first;
	//统计邻接表的边数
	while(curr!=NULL){
		degree++;
		curr=curr->next;
	}
	//对于有向图，还可以统计入度（循环遍历）
	if(G->graphType==1){
		for(int i=0;i<G->vexnum;i++){
			if(i!=vertex){     //排除顶点自己指向自己的情况
				ArcNode* temp=G->vertices[i].first;
				while(temp!=NULL){
					if(temp->adjvex==vertex){
						degree++;
					}
					temp=temp->next;
				}
			}
		}
	}
	return degree;
}

//深度优先遍历(DFS算法)
//类似树的先序遍历
void DFS(ALGraph* G,int start,bool visited[])
{
	visited[start]=true;  //标记当前节点已经被访问
	printf("%d ",G->vertices[start].data);  //访问当前顶点
//	ArcNode* curr=G->vertices[start].first;
//	while(curr!=NULL){
//		if(!visited[curr->adjvex]){  //当前顶点的邻接点还没有访问
//			DFS(G,curr->adjvex,visited);
//		}
//		curr=curr->next;  //移动到下一条边
//	}
	for(int w=FirstNeighbor(G,start);w>=0;w=NextNeighbor(G,start,w)){  //w表示当前邻接点
		if(!visited[w]){
			DFS(G,w,visited);
		}
	}
}

void DFS_Traverse(ALGraph* G)  //traverse遍历
{
	bool visited[MAX_VERTEX_NUM]={false};   //false表示顶点没有被访问
	for(int i=0;i<G->vexnum;i++){
		if(!visited[i]){   //如果遍历找到该顶点没有被访问，就从它开始DFS
			DFS(G,i,visited);
		}
	}
}

//广度优先遍历(BFS算法)
//类似树的层序遍历
typedef struct{
	int data[MAX_VERTEX_NUM];
	int rear;
	int front;
}Queue;

void InitQueue(Queue* q)
{
	q->front=q->rear=0;
}

bool isEmpty(Queue* q)
{
	return q->front==q->rear;
}
//入队
void EnQueue(Queue* q,int value)
{
	q->data[q->rear++]=value;
}

//出队
int DeQueue(Queue* q)
{
	return q->data[q->front++];
}

void BFS(ALGraph* G,int start,bool visited[])
{
	Queue q;
	InitQueue(&q);
	visited[start]=true;
	printf("%d ",G->vertices[start].data);
	EnQueue(&q,start);  //入队的是顶点的下标
	while(!isEmpty(&q)){
		int v=DeQueue(&q);  //队首顶点出队
		for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){  //w表示当前邻接点
			if(!visited[w]){
				visited[w]=true;
				EnQueue(&q,w);
			}
		}
	}
}

void BFS_Traverse(ALGraph* G)
{
	bool visited[MAX_VERTEX_NUM]={false};
	for(int i=0;i<G->vexnum;i++){
		if(!visited[i]){
			BFS(G,i,visited);
		}
	}
}

int main()
{
	ALGraph G;
	InitGraph(&G,5,0);   //5个顶点的无向图
	//添加边
	AddEdge(&G,0,1,1);
	AddEdge(&G,0,2,1);
	AddEdge(&G,1,3,1);
	AddEdge(&G,2,4,1);
	//遍历
	printf("DFS遍历：");
	DFS_Traverse(&G);
	printf("\n");
	printf("BFS遍历：");
	BFS_Traverse(&G);
	printf("\n");
	
	return 0;
}