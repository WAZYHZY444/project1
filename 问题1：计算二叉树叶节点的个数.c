#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
	char data;
	struct BiTNode* LeftChild;
	struct BiTNode* rightChild;
}BiTNode;

int isLeaf(BiTNode* root)
{
	if(root==NULL) return 0;
	int count=0;
	if(root->LeftChild==NULL&&root->rightChild==NULL){
		return 1;
	}
	return 0;
}

//前序计算叶节点
int  PreOrder(BiTNode* root)
{
	if(root==NULL) return 0;
	return isLeaf(root)+PreOrder(root->LeftChild)+PreOrder(root->rightChild);
}

//创建二叉树
int i=0;
BiTNode* CreateTree(BiTNode** T,char str[])
{
	char ch=str[i++];
	if(ch=='#'){
		*T=NULL;
	}else{
		*T=(BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data=ch;
		
		CreateTree(&((*T)->LeftChild),str);
		CreateTree(&((*T)->rightChild),str);
	}
}



int main()
{
	BiTNode* T;
	char* str="AB#D##C##";
	CreateTree(&T,str);
	printf("%d\n",PreOrder(T));
	return 0;
}