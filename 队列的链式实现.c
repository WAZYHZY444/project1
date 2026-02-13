#include <stdio.h>
#include <stdbool.h>

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

void InitQueue(LinkQueue* Q)
{
	Q->front=Q->rear=malloc(sizeof(LinkNode));
	Q->front->next=NULL;
}