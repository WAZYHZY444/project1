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

//2.孩子表示法
#define MAX_TREE_SIZE 100
struct CTNode
{
	int child;              //孩子节点在数组中的下标
	struct CTNode* next;    //指向下一个孩子节点
}

typedef struct
{
	ElemType data;
	struct CTNode* firstChild;  //指向第一个孩子结点的链表头
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n;   //总结点数
	int r;   //根节点位置下标
}

//3.孩子兄弟表示法
typedef struct
{
	ElemType data;
	struct CSNode *firstchild;  //指向第一个孩子
	struct CSNode *nextsibing;  //指向右边一个兄弟
}CSNode;