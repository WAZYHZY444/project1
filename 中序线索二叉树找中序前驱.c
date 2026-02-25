/*
思路：
在中序线索二叉树中找到指定节点p的中序前驱next
1.若p->ltag=1,则next=p->LeftChild
2.若p->ltag=0,则next=p左子树中最右下节点
*/

typedef struct ThreadNode
{
	int data;
	struct ThreadNode* LeftChild;
	struct ThreadNode* RightChild;
	int ltag;
	int rtag;
}ThreadNode;

//找到以p为根的子树中，最后一个被中序遍历的节点
ThreadNode* LastNode(ThreadNode* p)
{
	while(p->rtag==0){
		p=p->RightChild;
	}
	return p;
}
//在中序线索二叉树中找到指定节点p的中序前驱节点
ThreadNode* PreNode(ThreadNode* p)
{
	if(p->ltag==0){
		return LastNode(p->LeftChild);
	}else{
		return p->LeftChild;
	}
}

//对中序线索二叉树进行逆向中序遍历
void InOrder(ThreadNode* T)
{
	for(ThreadNode* p=LastNode(T);p!=NULL;p=PreNode(p));
	Visit(P);
}