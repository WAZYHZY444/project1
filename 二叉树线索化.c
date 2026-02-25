typedef struct ThreadNode
{
	int data;
	struct ThreadNode* LeftChild;
	struct ThreadNode* RightChild;
	//左右线索标志(初始化ltag、rtag为0)
	int ltag;
	int rtag;
}ThreadNode;

//全局变量
ThreadNode* pre=NULL;

//中序遍历二叉树(边遍历，边线索化)
void InThread(ThreadNode* T)
{
	if(T!=NULL){
		InThread(T->LeftChild);
		Visit(T);
		InThread(T->RightChild);
	}
}

void Visit(ThreadNode* q)
{
	if(q->LeftChild==NULL){
		q->LeftChild=pre;
		q->ltag=1;
	}
	if(pre!=NULL&&q->RightChild==NULL){
		pre->RightChild=q;
		pre->rtag=1;
	}
	pre=q;
}

//问：ThreadNode* pre=NULL，pre不是一个结构体指针吗，又不是节点，为什么可以用成员访问运算符->
//答：pre=q; 这行代码执行后，pre就不再是NULL，而是变成了指向实际节点的指针，所以后续的调用中就可以使用 pre-> 来访问这个节点的成员了。