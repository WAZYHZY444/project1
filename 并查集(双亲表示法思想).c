#define SIZE 13
int UFset[SIZE];  //集合元素数组(父节点的下标)

//初始化并查集
void Initial(int S[])
{
	for(int i=0;i<SIZE;i++){
		S[i]=-1;
	}
}

//“查”操作
int Find(int S[],int x)  //x是当前节点的下标
{
	while(S[x]>=0){      //S[x]的值是下标为x的元素的父节点下标
		x=S[x];
	}
	return x;
}

//“并”操作
void Union(int S[],int Root1,int Root2)
{
	if(Root1==Root2){
		return;        //要求是两个不同的集合
	}
	S[Root1]=Root2;   //将下标为Root1的根连接到另一个下标为Root2的根下面
}

//“并”操作优化
//1.用根节点的绝对值表示树的节点总数
//2.Union操作，让小树合并到大树(降低Find操作的时间复杂度)      //该方法构造的树最大高度不超过[log2(n)]+1
void Union(int S[],int Root1,int Root2)
{
	if(Root1==Root2){
		return;
	}
	if(S[Root1]>S[Root2]){    //Root1节点数少于Root2
		S[Root2]+=S[Root1];
		S[Root1]=Root2;
	}else{
		S[Root1]+=S[Root2];
		S[Root2]=Root1;
	}
}

//“并”操作优化之前，Find函数的最坏时间复杂度为O(n),优化之后，最坏时间复杂度为O(log2(n))
//Union函数时间复杂度始终为O(1)

//“查”操作优化，先找到根节点，再进行“压缩路径”
int Find(int [],int x)
{
	int root=x;
	while(root>=0) root=S[root];   //循环找到根节点
	while(root!=x){
		int t=S[x];
		S[x]=root;   //下标为x的节点直接挂到根节点下面
		x=t;         //不能直接写x=S[x];因为S[x]=root改变了S[x]的值
	}
	return root;
}

//“查”操作优化后，可使根的高度不超过O(α(n)).α(n)是一个增长缓慢的函数，对于常见的n值，通常α(n)<=4,因此Find优化后并查集的find、Union操作时间开销都很低