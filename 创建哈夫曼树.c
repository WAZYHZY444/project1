#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int weight;  //权重
	int parent,left,right;
}HuffmanNode;

HuffmanNode* InitHuffmanTree(int n,int weights[])
{
	//树节点数组
	HuffmanNode* nodes=(HuffmanNode*)malloc(sizeof(HuffmanNode)*(2*n-1));
	for(int i=0;i<2*n-1;i++){
		if(i<n)  //初始节点
			nodes[i].weight=weights[i];
		else
			nodes[i].weight=0;
			
		nodes[i].left=-1;
		nodes[i].right=-1;
		nodes[i].parent=-1;
	}
	return nodes;
}

//选择最小的树
void selectMin(int k,int* t,HuffmanNode nodes[])
{
	//先找第一个可用节点
	for(int i=0;i<k;i++){
		if(nodes[i].parent==-1){   //非根节点（相当于没有访问过的节点）
			*t=i;
			break;
		}
	}
	//遍历找更小的
	for(int i=0;i<k;i++){
		if(nodes[i].parent==-1&&nodes[i].weight<nodes[*t].weight){
			*t=i;
		}
	}
}

//选择两棵最小树
void select(int k,int* t1,int* t2,HuffmanNode nodes[])
{
	selectMin(k,t1,nodes);
	//当确定第一棵最小树后，将该树标识为父节点，查找第二小的树时就不在考虑这棵树
	nodes[*t1].parent=0;
	selectMin(k,t2,nodes);
}

//构建哈夫曼树
void CreateHuffmanTree(int n,HuffmanNode nodes[])
{
	//理解点：创建哈夫曼树的逻辑是初始森林中找到两个根节点权值最小的树构成新树，然后删除选定的两棵树，并加入新得到的树，所以要在2*n-1中寻找权值最小的树
	for(int i=n;i<2*n-1;i++){
		int t1,t2;
		select(i,&t1,&t2,nodes);
		//标记找到的这两棵最小树的父节点
		nodes[t1].parent=i;
		nodes[t2].parent=i;
		//标记当前创建的新节点的左右子树
		nodes[i].left=t1;
		nodes[i].right=t2;
		nodes[i].weight=nodes[t1].weight+nodes[t2].weight;
	}
}

//打印所有节点信息
void PrintHuffmanTree(int n,HuffmanNode nodes[])
{
	for(int i=0;i<2*n-1;i++){
		printf("%d\t%d\t%d\t%d\t%d\n",i,nodes[i].weight,nodes[i].parent,nodes[i].left,nodes[i].right);
	}
}

int main()
{
	int n=5;
	int weights[]={1,2,2,1,3};
	HuffmanNode* nodes=InitHuffmanTree(n,weights);
	CreateHuffmanTree(n,nodes);
	PrintHuffmanTree(n,nodes);
	return 0;
}