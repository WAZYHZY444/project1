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

/*中序线索化*/

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

//中序线索化二叉树T
void CreateInThread(ThreadNode* T)
{
	pre=NULL;
	if(T!=NULL){
		InThread(T);           //中序线索化二叉树
		if(pre->RightChild==NULL){
			pre->rtag=1;       //处理遍历的最后一个节点
		}
	}
}
//问：ThreadNode* pre=NULL，pre不是一个结构体指针吗，又不是节点，为什么可以用成员访问运算符->
//答：pre=q; 这行代码执行后，pre就不再是NULL，而是变成了指向实际节点的指针，所以后续的调用中就可以使用 pre-> 来访问这个节点的成员了。


/*先序线索化*/

//先序遍历二叉树(边遍历，边线索化)
void PreThread(ThreadNode* T)
{
	if(T!=NULL){
		Visit(T);
		if(T->ltag==0){    //避免出现循环线索化(只有先序遍历会出现循环)
			PreThread(T->LeftChild);
		}
		PreThread(T->RightChild);
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

//中序线索化二叉树T
void CreateInThread(ThreadNode* T)
{
	pre=NULL;
	if(T!=NULL){
		PreThread(T);           //中序线索化二叉树
		if(pre->RightChild==NULL){
			pre->rtag=1;       //处理遍历的最后一个节点
		}
	}
}