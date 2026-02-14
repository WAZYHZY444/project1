#include <stdio.h>
#include <stdbool.h>

//带头结点
//定义节点结构
typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}LinkNode;

//定义队列结构
typedef struct
{
	LinkNode* rear;
	LinkNode* front;
}LinkQueue;

//初始化
void InitQueue(LinkQueue* Q)
{
	Q->front=Q->rear=malloc(sizeof(LinkNode));
	Q->front->next=NULL;
}

//判断队列是否为空
bool isEmpty(LinkQueue Q)
{
	return Q->front==Q->rear;
}

//入队
void EnQueue(LinkQueue* Q,int e)
{
	LinkNode* s=malloc(sizeof(LinkNode));
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;       //新节点插入到队尾
	Q->rear=s;             //修改队尾指针
}

//出队
void DeQueue(LinkQueue* Q,int* e)
{
	if(isEmpty(*Q)){
		return false;
	}
	LinkNode* p=Q->front->next;   //p指向队头元素
	e=p->data;
	Q->front->next=p->next;       //修改头节点next指针
	if(Q->rear==p){               //最后一个节点出队
		Q->rear=Q->front;
	}
	free(p);
	return true;
}

//不带头结点
void InitQueue_2(LinkQueue* Q)
{
	Q->front=NULL;
	Q->rear=NULL;
}

bool isEmpty_2(LinkQueue Q)
{
	return Q->front==NULL;
}

void EnQueue_2(LinkQueue* Q,int e)
{
	LinkNode* s=malloc(sizeof(LinkNode));
	s->data=e;
	s->next=NULL;
	if(Q->front==NULL){   //在空队列中插入第一个元素
		Q->front=s;
		Q->rear=s;
	}else{
		Q->rear->next=s;
		Q->rear=s; 
	}
}

void DeQueue_2(LinkQueue* Q,int* e)
{
	if(isEmpty(*Q)){
		return false;
	}
	LinkNode* p=Q->front;          //p指向此次出队的节点
	e=p->data;
	Q->front=p->next;             //修改头节点next指针
	if(Q->rear==p){               //最后一个节点出队
		Q->rear=NULL;
		Q->front=NULL;
	}
	free(p);
	return true;
}