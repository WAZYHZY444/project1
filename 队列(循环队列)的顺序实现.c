#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10

typedef struct
{
	ElemType data[MAXSIZE];
	int front;   //队头指针，指向队头元素
	int rear;    //队尾指针，指向队尾元素的后一个位置(下一个元素插入的位置)
}SqQueue;

//队列元素个数：(rear+MAXSIZE-front)%MAXSIZE

//队列的初始化
void InitQueue(SqQueue* Q)
{
	Q->front=0;
	Q->rear=0;
}

//判断队列是否为空
bool isEmpty(SqQueue* Q)
{
	return Q->front==Q->rear;
}

//判断队列是否已满
bool isFull(SqQueue* Q)
{
	return (Q->rear+1)%MAXSIZE==Q->front;  //循环队列(会浪费一个ElemType类型的空间)
}

//入队
bool EnQueue(SqQueue* Q,ElemType x)
{
	if(isFull(Q)){
		return false;
	}
	Q->data[Q->rear]=x;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return true;
}

//出队
bool DeQueue(SqQueue* Q,ElemType* x)
{
	if(isEmpty(Q)){
		return false;
	}
	*x=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return true;
}

//获取队头元素
bool DeQueue(SqQueue* Q,ElemType* x)
{
	if(isEmpty(Q)){
		return false;
	}
	*x=Q->data[Q->front];
	return true;
}

//判断队列已满/已空
/*
1.循环队列
已空：Q->front==Q->rear
已满：(Q->rear+1)%MAXSIZE==Q->front

2.
typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
	int size;   //初始化size=0
}SqQueue;
插入成功size++；删除成功size--
已空：size==0
已满：size==MAXSIZE

3.typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
	int tag;   //初始化tag=0
}SqQueue;
每次删除成功，都令tag=0；每次插入成功，都令tag=1
(只有删除操作，才可能导致队空；只有插入操作，才可能导致队满)
已空：front==rear&&tag==1
已满：front==rear&&tag==0
*/