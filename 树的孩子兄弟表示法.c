#include <stdio.h>
#include <stdlib.h>

typedef struct CSNode
{
	char data;
	struct CSNode* firstchild;  //指向第一个孩子
	struct CSNode* nextsibing;  //指向右边一个兄弟
}CSNode;

CSNode* createNode(char val)
{
	CSNode* newnode=(CSNode*)malloc(sizeof(CSNode));
	newnode->data=val;
	newnode->firstchild=NULL;
	newnode->nextsibing=NULL;
	return newnode;
}

void createTree(CSNode** T)
{
	*T=createNode('A');
	(*T)->firstchild=createNode('B');
	(*T)->
}