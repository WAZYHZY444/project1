#include <stdio.h>
#include <stdlib.h>

//前序线索化并遍历
typedef  struct ThreadNode{
	char data;
	struct ThreadNode* left;
	struct ThreadNode* right;
	int ltag;
	int rtag;
}ThreadNode;

ThreadNode* pre=NULL;

//创建二叉树
//         A
//       /  \
//      B    C
//     / \    \
//    D   E    F
ThreadNode* CreateNode(char val)
{
	ThreadNode* newnode=(ThreadNode*)malloc(sizeof(ThreadNode));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->ltag=0;
	newnode->rtag=0;
	return newnode;
}
ThreadNode* CreateTree()
{
	ThreadNode* A=CreateNode('A');
	ThreadNode* B=CreateNode('B');
	ThreadNode* C=CreateNode('C');
	ThreadNode* D=CreateNode('D');
	ThreadNode* E=CreateNode('E');
	ThreadNode* F=CreateNode('F');
	
	A->left=B;
	A->right=C;
	B->left=D;
	B->right=E;
	C->right=F;
	
	return A;
}

//前序线索化
void preThread(ThreadNode* T)
{
	if(T!=NULL){
		//处理当前节点的左指针
		if(T->left==NULL){
		T->left=pre;
		T->ltag=1;
		}
		//处理前驱节点的右指针
		if(pre!=NULL&&pre->right==NULL){
			pre->right=T;
			pre->rtag=1;
		}
		pre=T;
		
		//递归处理左子树
		if(T->ltag==0){
			preThread(T->left);
		}
		//递归处理右子树
		if(T->rtag==0){
			preThread(T->right);
		}
	}
}

void CreatepreThread(ThreadNode* T)
{
	pre=NULL;
	if(T!=NULL){
		preThread(T);
		//处理最后一个节点的右指针
		if(pre->right==NULL){
			pre->rtag=1;
		}
	}
}

//前序遍历线索二叉树(不需要递归)
void preOrder(ThreadNode* T)
{
	ThreadNode* p=T;
	while(p!=NULL){
		printf("%c ",p->data);
		if(p->ltag==0){
			p=p->left;
		}else{
			p=p->right;
		}
	}
}

//释放内存
void DestroyTree(ThreadNode* T)
{
	if(T==NULL) return;
	//只释放真正的孩子，不释放线索指向的节点
	if(T->ltag==0) DestroyTree(T->left);
	if(T->rtag==0) DestroyTree(T->right);
	free(T);
}

int main()
{
	ThreadNode* root=CreateTree();
	CreatepreThread(root);
	preOrder(root);
	DestroyTree(root);
	
	return 0;
}