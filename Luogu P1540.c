#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int m,n;
typedef struct Queue{
	int data[100];
	int front;
	int rear;
	int size;
}Queue;

void Init(Queue* q)
{
	q->front=0;
	q->rear=0;
	q->size=0;
}

bool isFull(Queue* q)
{
	return q->size==m; 
}

bool isEmpty(Queue* q)
{
	return q->size==0;
}

void Enqueue(Queue* q,int val)
{
	if(!isFull(q)){
		q->data[q->rear]=val;
		q->rear=(q->rear+1)%100;
		q->size++;
	}
	return;
}

int Dequeue(Queue* q){
	if(!isEmpty(q)){
		int val=q->data[q->front];
		q->front=(q->front+1)%100;
		q->size--;
		return val;
	}
	return -1;
}

bool Match(Queue* q,int val)
{
	for(int i=0;i<q->size;i++){
		int index=(q->front+i)%100;
		if(q->data[index]==val){
			return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d %d",&m,&n);
	int arr[n];
	int count=0;
	Queue q;
	Init(&q);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		if(!Match(&q,arr[i])){
			if(isFull(&q)){
				Dequeue(&q);
			}
			Enqueue(&q,arr[i]);
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}