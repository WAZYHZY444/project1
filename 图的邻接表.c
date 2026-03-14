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
}AcrNode;

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
void InitGraph(AlGraph* G,int vexnum,int type)   //type取值0或1，决定是无向图还是有向图
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

//插入边
void AddEdge(ALGraph* G,int start,int end,int weight)  //start、end表示边两端所连接的顶点的下标
{
	if(start<0||start>=G->vexnum||end<0||end>=G->vexnum){  //顶点编号从0开始，顶点下标最大值比顶点总数小1
		printf("定点下标错误\n");
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
		newnode2->next=G->vertices[start].first;
		G->vertices[start].first=newnode2;
		G->arcnum+=2;    //增加存储的边数，不是增加概念上的边数
	}else{               //有向图
		G->arcnum++;
	}
}

//删除边
void RemoveEdge(ALGraph* G,int start,int end)
{
	if(start<0||start>=G->vexnum||end<0||end>=G->vexnum){
		printf("定点下标错误\n");
		return;
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
		curr=G->vertices[start].first;
		while(curr!=NULL&&curr->adjvex!=start){
			prev=curr;
			curr=curr->next;
		}
		if(curr!=NULL){
			if(prev!=NULL){
				prev->next=curr->next;
			}else{
				G->vertices[start].first=curr->next;
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
		return;
	}
	int degree=0;
	ArcNode* curr=G->vertices[start].first;
	//统计邻接表的边数
	while(curr!=NULL){
		degree++;
		curr=curr->next;
	}
	//对于有向图，还可以统计入度（循环遍历）
	if(G->graphType==1){
		for(int i=0;i<G->vexnum;i++){
			if(i!=vertex){     //排除顶点自己指向自己的情况
				ArcNode* temp=G->vertices[start].first;
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
	ArcNode* curr=G->vertices[start].first;
	while(curr!=NULL){
		if(!visited[curr->adjvex]){  //当前顶点的邻接点还没有访问
			DFS(G,curr->adjvex,visited);
		}
		curr=curr->next;  //移动到下一条边
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