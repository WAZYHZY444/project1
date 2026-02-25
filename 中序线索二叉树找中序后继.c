/*
思路：
在中序线索二叉树中找到指定节点p的中序后继next
1.若p->rtag=1,则next=p->RightChild
2.若p->rtag=0,则next=p右子树中最左下节点
*/

typedef struct ThreadNode
{
	int data;
	struct ThreadNode* LeftChild;
	struct ThreadNode* RightChild;
	int ltag;
	int rtag;
}ThreadNode;

//找到以p为根的子树中，第一个被中序遍历的节点
ThreadNode* FirstNode(ThreadNode* p)
{
	while(p->ltag==0){
		p=p->LeftChild;
	}
	return p;
}
//在中序线索二叉树中找到指定节点p的中序后继节点
ThreadNode* NextNode(ThreadNode* p)
{
	if(p->rtag==0){
		return FirstNode(p->RightChild);
	}else{
		return p->RightChild;
	}
}

//对中序线索二叉树进行中序遍历(利用线索实现的非递归算法)
void InOrder(ThreadNode* T)
{
	for(ThreadNode* p=FirstNode(T);p!=NULL;p=NextNode(p));
	Visit(P);
}