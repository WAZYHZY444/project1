//树的存储结构
//1.双亲表示法
#define MAX_TREE_SIZE 100   //树中最多节点数

//树的节点定义
typedef struct
{
	ElemType data;
	int parent;      //双亲位置域（父节点在数组中的下标，-1表示无父节点，即根节点）
}PTNode;

//树的类型定义
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int n;
}PTree;

//2。孩子兄弟表示法
typedef struct
{
	ElemType data;
	struct CSNode *firstchild;  //指向第一个孩子
	struct CSNode *nextsibing;  //指向右边一个兄弟
}CSNode;