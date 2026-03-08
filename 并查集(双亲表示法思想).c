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

//优化之前，Find函数的最坏时间复杂度为O(n),优化之后，最坏时间复杂度为O(log2(n))
//Union函数时间复杂度始终为O(1)