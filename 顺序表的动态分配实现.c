#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 10   //默认最大长度

typedef struct SeqList
{
	int* data;
	int MaxSize;      //顺序表当前容量
	int length;       //顺序表当前长度
}SeqList;

void InitList(SeqList* L)
{
	L.data=(int*)malloc(INITSIZE*sizeof(int));
	if(L.data==NULL){
		return 1;
	}
	L.length=0;
	L.MaxSize=INITSIZE;
}

void IncreaseSize(SeqList* L,int len)
{
	int* p=(int*)realloc(L.data,(L.MaxSize+len)*sizeof(int));
	if(p!=NULL){
		L.data=p;
	}
	L.MaxSize=L.MaxSize+len;
	free(L.data);
	L.data=NULL;
}

int main()
{
	SeqList L;
	InitList(&L);
	//操作
	IncreaseSize(&L,5);
	//操作
	return 0;
}