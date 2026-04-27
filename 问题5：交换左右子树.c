//交换左右子树
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
	char data;
	struct BiTNode* left;
	struct BiTNode* right;
}BiTNode;

//创建二叉树
int i=0;
void createTree(BiTNode** T,char str[])
{
	char ch=str[i++];
	if(ch=='#'){
		*T=NULL;
	}else{
		*T=(BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data=ch;
		
		createTree(&((*T)->left),str);
		createTree(&((*T)->right),str);
	}
}

void exLeftandRight(BiTNode* T)  //只修改了内容，没有修改地址，不需要二级指针
{
	if(T==NULL){
		return;
	}
	BiTNode* temp=T->left;
	T->left=T->right;
	T->right=temp;
	exLeftandRight(T->left);
	exLeftandRight(T->right);
}

//前序遍历检验是否交换成功
void preOrder(BiTNode* T)
{
	if(T!=NULL){
		printf("%c ",T->data);
		preOrder(T->left);
		preOrder(T->right);
	}
}

//销毁二叉树
void freeTree(BiTNode* T)
{
	if(T!=NULL){
		freeTree(T->left);
		freeTree(T->right);
		free(T);
	}
}

int main()
{
	i=0;
	BiTNode* T;
	char* str="ABD##E##C#F##";
	createTree(&T,str);
	exLeftandRight(T);
	preOrder(T);
	
	freeTree(T);
	return 0;
}