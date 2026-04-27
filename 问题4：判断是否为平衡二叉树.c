//判断平衡二叉树
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

int calHeight(BiTNode* T)
{
	if(T==NULL){
		return 0;
	}
	int h1=calHeight(T->left);
	int h2=calHeight(T->right);
	return h1>h2?h1+1:h2+1;
}

bool isBBT(BiTNode* T)
{
	if(T==NULL){
		return true;
	}
	int h1=calHeight(T->left);
	int h2=calHeight(T->right);
	if(abs(h1-h2)>1){
		return false;
	}
	//递归判断子树是不是平衡二叉树
	return isBBT(T->left)&&isBBT(T->right);
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
	int height=calHeight(T);
	bool result=isBBT(T);
	if(result){
		printf("是平衡二叉树\n");
	}else{
		printf("不是平衡二叉树\n");
	}
	
	freeTree(T);
	return 0;
}