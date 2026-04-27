//计算树的高度
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

int calHeight(BiTNode* T)
{
	if(T==NULL){
		return 0;
	}
	int h1=calHeight(T->left);
	int h2=calHeight(T->right);
	return h1>h2?h1+1:h2+1;
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
	BiTNode* T;
	char* str="ABD##E##C#F##";
	createTree(&T,str);
	int height=calHeight(T);
	printf("%d\n",height);
	
	freeTree(T);
	return 0;
}