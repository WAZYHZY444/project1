#include <stdio.h>
#include <stdlib.h>
typedef struct BSTNode
{
	int data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
}BSTNode;

//在树中插入值key(递归实现)
BSTNode* InsertNode(BSTNode* root,int key)
{
	if(root==NULL){
		root=(BSTNode*)malloc(sizeof(BSTNode));
		root->data=key;
		root->lchild=NULL;
		root->rchild=NULL;
		return root;
	}
	if(key==root->data){ //key值已经存在，不需要插入
		return root;
	}
	else if(key<root->data){ //如果比根节点的数值小，则插入左子树
		root->lchild=InsertNode(root->lchild,key);
	}
	else{  ////如果比根节点的数值大，则插入右子树
		root->rchild=InsertNode(root->rchild,key);
	}
	return root;
}

//创建二叉树
BSTNode* CreateBST(int* data,int len)  //传入数组
{
	BSTNode* root=NULL;
	for(int i=0;i<len;i++){
		root=InsertNode(root,data[i]);
	}
	return root;
}

//查找值为key的节点(非递归实现)
BSTNode* SearchNode(BSTNode* root,int key)
{
	while(root!=NULL&&key!=root->data){ //树空表示找不到该节点，等于根节点表示已经找到了
		if(key<root->data){
			root=root->lchild;  //小于根节点，则在左子树上查找
		}else{
			root=root->rchild;
		}
	}
	return root;
}

//查找值为key的节点(递归实现)
BSTNode* Search_Node(BSTNode* root,int key)
{
	if(root==NULL||key==root->data){
		return root;
	}
	if(key<root->data){
		return Search_Node(root->lchild,key);
	}else{
		return Search_Node(root->rchild,key);
	}
}

//删除节点
BSTNode* DeleteNode(BSTNode* root,int key)
{
	if(root==NULL){  //要删除的节点不存在
		return NULL;
	}
	if(root->data>key){
		root->lchild=DeleteNode(root->lchild,key);
	}
	else if(root->data<key){
		root->rchild=DeleteNode(root->rchild,key);
	}
	//找到要删除的节点
	else{
		//要删除的节点是叶子节点或者没有左子树,用节点的右子树作为父节点的右子树
		if(root->lchild==NULL){
			BSTNode* temp=root->rchild;
			free(root);
			return temp;
		}
		//没有右子树，用节点的左子树作为父节点的左子树
		else if(root->rchild==NULL){
			BSTNode* temp=root->lchild;
			free(root);
			return temp;
		}
		//左右子树都存在
		//方法一：找节点的直接后继(最小值节点)
		else{
			BSTNode* parent=root;  //父节点指针
			BSTNode* successor=root->rchild; //后继结点指针
			while(successor->lchild!=NULL){
				parent=successor;
				successor=successor->lchild;
			}
			//结点的值用直接后继节点的值替换
			root->data=successor->data;  //注意：root指针没有移动，root指针始终指向的是要删除的节点
			//删除对应的后继节点
			if(parent->lchild==successor){  //后继是左孩子
				parent->lchild=successor->rchild;  //相当于赋值的是NULL
			}else{    //后继是右孩子(后继没有左孩子)
				parent->rchild=successor->rchild;  //后继如果有有孩子，赋值的是后继的右孩子，如果没有右孩子，赋值的是NULL
			}
			free(successor);
		}
		
		//方法二：找节点的直接前继(最大值节点)
		else{
			BSTNode* predecessor=root->lchild;
			BSTNode* predecessorParent=root;
			while(predecessor->rchild!=NULL){
				predecessorParent=predecessor;
				predecessor=predecessor->rchild;
			}
			root->data=predecessor->data;
			if(predecessorParent->rchild==predecessor){
				predecessorParent->rchild=predecessor->lchild;
			}else{
				predecessorParent->lchild=predecessor->lchild;
			}
			free(predecessor);
		}
		
	}
	return root;
}

//销毁树(后序遍历释放内存)
void DestroyTree(BSTNode* root)
{
	if(root!=NULL){
		DestroyTree(root->lchild);
		DestroyTree(root->rchild);
		free(root);
	}
}