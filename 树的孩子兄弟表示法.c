#include <stdio.h>
#include <stdlib.h>

typedef struct CSNode
{
	char data;
	struct CSNode* firstchild;  //指向第一个孩子
	struct CSNode* nextsibing;  //指向右边一个兄弟
}CSNode;

CSNode* createNode(char val)
{
	CSNode* newnode=(CSNode*)malloc(sizeof(CSNode));
	newnode->data=val;
	newnode->firstchild=NULL;
	newnode->nextsibing=NULL;
	return newnode;
}
//原树：
//        A
//      / | \
//     B  C  D
//    / \    |
//   E   F   G

CSNode* createTree()
{
	CSNode* A=createNode('A');
	CSNode* B=createNode('B');
	CSNode* C=createNode('C');
	CSNode* D=createNode('D');
	CSNode* E=createNode('E');
	CSNode* F=createNode('F');
	CSNode* G=createNode('G');
	
	A->firstchild=B;
	B->firstchild=E;
	B->nextsibing=C;
	C->nextsibing=D;
	E->nextsibing=F;
	D->firstchild=G;
	
	return A;
}

//先根遍历
void preOrder(CSNode* T)
{
	if(T!=NULL){
		printf("%c ",T->data);
		preOrder(T->firstchild);
		preOrder(T->nextsibing);
	}
}

//释放内存（后序遍历）
void DestroyByPostOrder(CSNode* T)
{
	if(T!=NULL){
		DestroyByPostOrder(T->firstchild);
		DestroyByPostOrder(T->nextsibing);
		free(T);
	}
}

int main()
{
	CSNode* root=createTree();
	preOrder(root);
	DestroyByPostOrder(root);
	root=NULL;
	
	return 0;
}