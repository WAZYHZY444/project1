typedef struct BiTNode
{
	ElemType data;
	struct BiTNode* LeftChild;
	struct BiTNode* RightChild;
}BiTNode;

//先序遍历
void PreOrder(BiTNode* T)
{
	if(T!=NULL){
		visit(T);
		PreOrder(T->LeftChild);
		PreOrder(T->RightChild);
	}
}

//中序遍历
void InOrder(BiTNode* T)
{
	if(T!=NULL){
		InOrder(T->LeftChild);
		visit(T);
		InOrder(T->RightChild);
	}
}

//后序遍历
void PostOrder(BiTNode* T)
{
	if(T!=NULL){
		PostOrder(T->LeftChild);
		PostOrder(T->RightChild);
		visit(T);
	}
}

//层序遍历
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
	return Q->front==Q->rear;
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
void LevelOrder(BiTNode* T)
{
	LinkQueue Q;
	InitQueue(&Q);
	//将根节点入队
	EnQueue(&Q,T);
	while(!isEmpty(Q)){
		//队头结点出队
		BiTNode* p=DeQueue(&Q);
		//访问当前节点
		printf("%d ",p->data);
		//左子节点入队
		if(p->LeftChild!=NULL){
			EnQueue(&Q,p->LeftChild);
		}
		//右子节点入队
		if(p->RightChild!=NULL){
			EnQueue(&Q,p->RightChild);
		}
	}
	printf("\n");
	free(Q);
	
}