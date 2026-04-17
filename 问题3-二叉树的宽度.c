#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//二叉树节点
typedef struct BiTNode{
	char data;
	struct BiTNode* left;
	struct BiTNode* right;
}BiTNode,*Tree;

//定义节点结构
typedef struct LinkNode
{
	BiTNode* data;    //存树节点指针
	struct LinkNode* next;
}LinkNode;

//定义队列结构
typedef struct
{
	LinkNode* front;
	LinkNode* rear;
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
	return Q.front==Q.rear;
}

//入队
void EnQueue(LinkQueue* Q,BiTNode* T)
{
	LinkNode* newnode=(LinkNode*)malloc(sizeof(LinkNode));
	newnode->data=T;
	newnode->next=NULL;
	Q->rear->next=newnode;
	Q->rear=newnode;
}

//出队
BiTNode* DeQueue(LinkQueue* Q)
{
	if(isEmpty(*Q)){
		return NULL;
	}
	LinkNode* temp=Q->front->next;
	BiTNode* p=temp->data;
	Q->front->next=temp->next;
	if(Q->rear==temp){
		Q->rear=Q->front;
	}
	free(temp);
	return p;
}

int maxWidth(Tree T)
{
	if(T==NULL) return 0;
	LinkQueue Q;
	InitQueue(&Q);
	//将根节点入队
	EnQueue(&Q,T);
	int max_width=0;
	while(!isEmpty(Q)){
		//当前层的节点个数
		int level_size=0;
		LinkNode* p=Q.front->next;
		//计算这一层有多少个节点
		while(p!=NULL){
			level_size++;
			p=p->next;
		}
		//更新最大宽度
		if(level_size>max_width) max_width=level_size;
		//当前层的孩子节点入队（下一层）
		for(int i=0;i<level_size;i++){
			//队头结点出队
			BiTNode* cur=DeQueue(&Q);
			//左子节点入队
			if(cur->left!=NULL)
				EnQueue(&Q,cur->left);
			//右子节点入队
			if(cur->right!=NULL)
				EnQueue(&Q,cur->right);
		}
	}
	return max_width;
	
}

//创建二叉树
int i=0;
void createTree(Tree* T,char str[])  //递归
{
	char ch=str[i++];  //先使用后改变
	if(ch=='#'){
		*T=NULL;
	}else{
		*T=(BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data=ch;  //根节点

		//递归创建左子树
		createTree(&((*T)->left),str);
		//递归创建右子树
		createTree(&((*T)->right),str);
	}
}

int main()
{
	Tree T;
	char* str="AB#D##C##";
	createTree(&T,str);
	int width=maxWidth(T);
	printf("二叉树最大宽度：%d\n",width);
	return 0;
}