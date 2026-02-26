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
}
