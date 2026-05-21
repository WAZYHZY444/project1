#include <iostream>
#include <string>
#define MAXSIZE 100
using namespace std;

struct TreeNode{
	char data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};
//-----队列--------//
struct Queue{
	TreeNode* data[MAXSIZE];  //注意存储的TreeNode节点
	int front;
	int rear;
};
void initQueue(Queue* q)
{
	q->front=q->rear=0;
}
bool isQueueFull(Queue* q)
{
	return (q->rear+1)%MAXSIZE==q->front;
}
bool isQueueEmpty(Queue* q)
{
	return q->front==q->rear;
}
void enQueue(Queue* q,TreeNode* val)
{
	if(isQueueFull(q)) return;
	q->data[q->rear]=val;
	q->rear=(q->rear+1)%MAXSIZE;
}
TreeNode* deQueue(Queue* q)
{
	if(isQueueEmpty(q)) return nullptr;
	TreeNode* val=q->data[q->front];
	q->front=(q->front+1)%MAXSIZE;
	return val;
}

//------栈--------//
struct Stack{
	TreeNode* data[MAXSIZE];
	int top;
};
void initStack(Stack* s)
{
	s->top=-1;
}
bool isStackFull(Stack* s)
{
	return s->top==MAXSIZE-1;
}
bool isStackEmpty(Stack* s)
{
	return s->top==-1;
}
void push(Stack* s,TreeNode* val)
{
	if(isStackFull(s)) return;
	s->data[++s->top]=val;
}
TreeNode* pop(Stack* s)
{
	if(isStackEmpty(s)) return nullptr;
	return s->data[s->top--];
}

//创建二叉树
int i=0;
void createTree(TreeNode* &T,string s)
{
	char ch=s[i++];
	if(ch=='#'){
		T=nullptr;
	}else{
		T=new TreeNode(ch);
		createTree(T->left,s);
		createTree(T->right,s);
	}
}

void levelOrder(TreeNode* T)
{
	if(T==nullptr) return;  //空指针检查
	Queue q;
	Stack s;
	initQueue(&q);
	initStack(&s);
	enQueue(&q,T);
	push(&s,T);
	while(!isQueueEmpty(&q)){
		TreeNode* p=deQueue(&q);
		//每层输出是从左到右
		if(p->right!=nullptr){
			enQueue(&q,p->right);
			push(&s,p->right);
		}
		if(p->left!=nullptr){
			enQueue(&q,p->left);
			push(&s,p->left);
		}
	}
	
	//出栈输出遍历序列
	while(!isStackEmpty(&s)){
		TreeNode* temp=pop(&s);
		cout<<temp->data;
	}
}

int main()
{
	i=0;
	string s;
	cin>>s;
	TreeNode* T;
	createTree(T,s);
	levelOrder(T);
	return 0;
}