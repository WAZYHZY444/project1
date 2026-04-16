#include <iostream>
using namespace std;

struct BiTNode{
	int data;
	BiTNode* left;
	BiTNode* right;
	
	//构造函数(初始化列表)
	BiTNode(int val):data(val),left(NULL),right(NULL){
	};
}

//手动创建二叉树
BiTNode* CreateTree()
{
	//根节点
	BiTNode* root=new BiTNode(1);
	//第一层
	root->left=new BiTNode(2);
	//第三层
	root->left->left=new BiTNode(3);
	root->left->right=new BiTNode(4);
	return root;
}

//前序遍历（序列）创建二叉树
