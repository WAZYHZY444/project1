#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100

//直接使用图的邻接表(基本操作+DFS算法+BFS算法)现有的数据结构和接口

void calculateInDegree(ALGraph* G,int inDegree[])
{
	//初始化入度数组
	for(int i=0;i<G->vexnum;i++){
		inDegree[i]=0;
	}
	//遍历每个顶点的邻接表，统计入度
	for(int i=0;i<G->vexnum;i++){
		ArcNode* p=G->vertices[i].first;
		while(p!=NULL){
			inDegree[p->adjvex]++;   //顶点p->adjvex的入度加1
			p=p->next;
		}
	}
}

//Kahn算法(使用队列)
void TopologicalSort_Kahn(ALGraph* G)
{
	if(G->graphType!=1){     //拓扑排序只能用于有向图
		return;
	}
	int inDegree[MAX_VERTEX_NUM];  //存储当前节点的入度
	int result[MAX_VERTEX_NUM];   //存储排序的结果
	int count=0;            //记录当前已经输出的顶点数
	
	//计算入度
	calculateInDegree(G,inDegree);
	
	//创建队列
	Queue q;
	InitQueue(&q);
	
	//将所有入度为0的顶点入队
	for(int i=0;i<G->vexnum;i++){
		if(inDegree[i]==0){
			EnQueue(&q,i);
		}
	}
	
	//处理队列中的顶点
	while(!isEmpty(&q)){
		int vertex=DeQueue(&q);
		result[count++]=vertex;  //将顶点加入结果序列
		//遍历当前顶点的所有邻接点
		ArcNode* p=G->vertices[vertex].first;
		while(p!=NULL){
			int adjVertex=p->adjvex;
			inDegree[adjVertex]--;   //邻接点入度减1
			if(inDegree[adjVertex]==0){
				EnQueue(&q,adjVertex);  //入度变为0，入队
			}
			p=p->next;
		}
	}
	
	//检查换是否存在
	if(count!=G->vexnum){
		printf("图中存在环，不能进行拓扑排序！\n");
		printf("成功排序的顶点数:%d,总顶点数:%d\n",count,G->vexnum);
		return;
	}
	
	//输出拓扑排序的结果
	for(int i=0;i<count;i++){
		printf("%d ",G->vertices[result[i]].data);
	}
	printf("\n");
}

//基于DFS的拓扑排序(栈实现)
//栈的数据结构定义
typedef struct
{
	int data[MAX_VERTEX_NUM];
	int top;
}Stack;

void InitStack(Stack* s)
{
	s->top=-1;
}

bool isEmpty(Stack* s)
{
	return s->top==-1;
}

bool isFull(Stack* s)
{
	return s->top==MAX_VERTEX_NUM-1;
}
bool push(Stack* s,int value)
{
	if(isFull(s)){
		return false;
	}
	s->data[++s->top]=value;
	return true;
}

int pop(Stack* s)
{
	if(isEmpty(s)){
		return -1;
	}
	return s->data[s->top--];
}

int GetTop(Stack* s)
{
	return s->data[s->top];
}

bool TopologicalSort_DFS(ALGraph* G)
{
	if(G->graphType!=1){
		return false;
	}
	bool visited[MAX_VERTEX_NUM]={false};   //顶点是否已访问
	bool onStack[MAX_VERTEX_NUM]={false};   //顶点是否在当前递归栈上(用于检测环)
	Stack result;                           //结果栈
	bool hasCycle=false;                    //是否有环
	
	InitStack(&result);  //初始化结果栈
	void DFS(int v)   //当前顶点的下标
	{
		visited[v]=true;
		onStack[v]=true;  //标记当前顶点在递归栈上
		
		//遍历所有邻接点
		for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
			if(!visited[w]){
				DFS(w);
				if(hasCycle) return;  //检测到环
			}else if(onStack[w]){  //如果w已访问却还在栈中，说明存在环
				hasCycle=true;
				return;
			}
		}
		
		//当前顶点处理完，将其压入结果栈
		push(&result,v);
		onStack[v]=false;  //标记已经从递归栈中移除
	}
	
	//对每个未访问的顶点进行DFS(其他的连通分量)
	//有向无环图有可能会有多个连通分量
	for(int i=0;i<G->vexnum;i++){
		if(!visited[i]){
			DFS(i);
			if(hasCycle) break;
		}
	}
	
	if(hasCycle){
		printf("图中存在环，不能进行拓扑排序！\n");
		return false;
	}
	
	//将结果栈中的元素转移到临时栈
	Stack tempStack;
	InitStack(&tempStack);
	while(!isEmpty(&result)){
		int v=pop(&result);
		push(&tempStack,v);
	}
	//从临时栈输出(为了正序输出)
	while(!isEmpty(&tempStack)){
		printf("%d ",GetTop(&tempStack));
		pop(&tempStack);
	}
	printf("\n");
	
	return true;
}


// 基于DFS的拓扑排序(使用数组模拟栈)
bool TopologicalSort_DFS_Simple(ALGraph* G){
    if(G->graphType!=1){
        return false;
    }
    bool visited[MAX_VERTEX_NUM]={false};
    bool onStack[MAX_VERTEX_NUM]={false};
    int result[MAX_VERTEX_NUM];  //用数组模拟栈
    int top=-1;                 //栈顶指针
    bool hasCycle=false;
    
    void DFS(int v){
        visited[v]=true;
        onStack[v]=true;
        
        for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
            if(!visited[w]){
                DFS(w);
                if(hasCycle) return;
            }else if(onStack[w]){
                hasCycle=true;
                return;
            }
        }
        
        result[++top]=v;  // 入栈
        onStack[v]=false;
    }
    
    //对每个未访问的顶点调用DFS
    for(int i=0;i<G->vexnum;i++){
        if(!visited[i]){
            DFS(i);
            if(hasCycle) break;
        }
    }
    
    if(hasCycle){
        printf("图中存在环，不能进行拓扑排序！\n");
        return false;
    }
    
    // 输出结果（从栈顶到栈底）
    printf("拓扑排序结果:");
    for(int i=top;i>=0;i--){
        printf("%d ",result[i]);
    }
    printf("\n");
    
    return true;
}

// 测试函数
void TestTopologicalSort(){
    ALGraph G;
    InitGraph(&G,6,1);  // 6个顶点，有向图
    
    // 添加边：构建一个DAG
    AddEdge(&G,0,1,1);
    AddEdge(&G,0,2,1);
    AddEdge(&G,1,3,1);
    AddEdge(&G,2,3,1);
    AddEdge(&G,3,4,1);
    AddEdge(&G,4,5,1);
    
    printf("原图邻接表：\n");
    PrintGraph(&G);
    
    printf("\n");
    TopologicalSort_Kahn(&G);
    
    printf("\n");
    TopologicalSort_DFS(&G);
    
    printf("\n");
    TopologicalSort_DFS_Simple(&G);
    
    DestoryGraph(&G);
}