#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  1.手动创建
typedef struct BiTNode{
	int data;
	struct BiTNode* left;
	struct BiTNode* right;
}BiTNode;

BiTNode* createNode(int val)
{
	BiTNode* newnode=(BiTNode*)malloc(sizeof(BiTNode));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

BiTNode* createTree()
{
	//根节点
	BiTNode* root=createNode(1);
	//第二层
	root->left=createNode(2);
	root->right=createNode(3);
	//第二层
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	return root;
}
//-----------------------------------------//

//  2.前序遍历序列创建
//根据遍历序列创建二叉树必须用一个特殊值表示空节点
typedef struct BiTNode{
	char data;
	struct BiTNode* left;
	struct BiTNode* right;
}BiTNode,*Tree;

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

//前序遍历（输出验证）
void preOrder(Tree T)
{
	if(T!=NULL){
		printf("%c ",T->data);
		preOrder(T->left);
		preOrder(T->right);
	}
}

int main()
{
	Tree T;
	char* str="AB#D##C##";
	createTree(&T,str);
	preOrder(T);
	return 0;
}
//------------------------------------------//

//  3.后序遍历序列创建
typedef struct BiTNode{
	char data;
	struct BiTNode* left;
	struct BiTNode* right;
}BiTNode,*Tree;

int i;
void createTree(Tree* T,char str[])  //递归
{
	char ch=str[i--];  //先使用后改变
	if(ch=='#'){
		*T=NULL;
	}else{
		*T=(BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data=ch;  //根节点
		
		//递归创建右子树
		createTree(&((*T)->right),str);
		//递归创建左子树
		createTree(&((*T)->left),str);
	}
}

//前序遍历（输出验证）
void postOrder(Tree T)
{
	if(T!=NULL){
		postOrder(T->left);
		postOrder(T->right);
		printf("%c ",T->data);
	}
}

int main()
{
	Tree T;
	char* str="##D#B##CA";
	i=strlen(str)-1;
	createTree(&T,str);
	postOrder(T);
	return 0;
}
//--------------------------------------//

//注意：单凭中序遍历是无法创建二叉树的
//  4.前序+中序创建
typedef struct BiTNode{
	char data;
	struct BiTNode* left;
	struct BiTNode* right;
}BiTNode,*Tree;

//在前序遍历序列里找到根节点在中序遍历序列的位置(是子节点的根)
int findRoot(char in[],int start,int end,char val)
{
	for(int i=start;i<=end;i++){
		if(in[i]==val){
			return i;
		}
	}
	return -1;
}

//创建二叉树
BiTNode* createTree(char pre[],char in[],int inStart,int inEnd,int* preIndex)
{
	//没有节点了
	if(inStart>inEnd) return NULL;  //递归结束的条件
	
	char rootVal=pre[*preIndex];
	(*preIndex)++;
	//创建根节点
	BiTNode* root=(BiTNode*)malloc(sizeof(BiTNode));
	root->data=rootVal;
	//找到根节点在中序遍历序列的位置
	int pos=findRoot(in,inStart,inEnd,rootVal);
	
	//创建左子树
	root->left=createTree(pre,in,inStart,pos-1,preIndex);
	//创建右子树
	root->right=createTree(pre,in,pos+1,inEnd,preIndex);
	
	return root;
}

//中序遍历（输出验证）
void inOrder(Tree T)
{
	if(T!=NULL){
		inOrder(T->left);
		printf("%c ",T->data);
		inOrder(T->right);
	}
}

int main()
{
	char* pre="ABDC";  //前序遍历序列
	char* in="BDAC";   //中序遍历序列
	
	int len=strlen(in);
	int preIndex=0;
	
	Tree T=createTree(pre,in,0,len-1,&preIndex);
	inOrder(T);
	
	return 0;
}
//----------------------------------------//

//  5.后序+中序创建
typedef struct BiTNode{
	char data;
	struct BiTNode* left;
	struct BiTNode* right;
}BiTNode,*Tree;

//在后序遍历序列里找到根节点在中序遍历序列的位置(是子节点的根)
int findRoot(char in[],int start,int end,char val)
{
	for(int i=start;i<=end;i++){
		if(in[i]==val){
			return i;
		}
	}
	return -1;
}

//创建二叉树
BiTNode* createTree(char post[],char in[],int inStart,int inEnd,int* postIndex)
{
	//没有节点了
	if(inStart>inEnd) return NULL;  //递归结束的条件
	
	char rootVal=post[*postIndex];
	(*postIndex)--;
	//创建根节点
	BiTNode* root=(BiTNode*)malloc(sizeof(BiTNode));
	root->data=rootVal;
	root->left=NULL;
	root->right=NULL;
	//找到根节点在中序遍历序列的位置
	int pos=findRoot(in,inStart,inEnd,rootVal);
	
	//创建右子树
	root->right=createTree(post,in,pos+1,inEnd,postIndex);
	//创建左子树
	root->left=createTree(post,in,inStart,pos-1,postIndex);
	
	return root;
}

//中序遍历（输出验证）
void inOrder(Tree T)
{
	if(T!=NULL){
		inOrder(T->left);
		printf("%c ",T->data);
		inOrder(T->right);
	}
}

int main()
{
	char* in="BDAC";   //中序遍历序列
	char* post="DBCA";  //后序遍历序列
	
	int len=strlen(in);
	int postIndex=len-1;
	
	Tree T=createTree(post,in,0,len-1,&postIndex);
	inOrder(T);
	
	return 0;
}