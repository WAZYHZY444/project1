#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10

typedef struct SqList
{
	int data[MAXSIZE];
	int length;
}SqList;

void InitList(SqList* L)
{
	for(int i=0;i<MAXSIZE;i++){
		L.data[i]=0;
	}
	L.length=0;
}

bool ListInsert(SqList* L,int i,int e)
{
	//i取值范围的判断(i的有效性)
	if(i<1||i>L.length+1){    //当i=L.length+1时，表示在表末尾插入数据
		return false;
	}
	if(L.length>=MAXSIZE){
		return false;
	}
	for(int j=L.length;j>=i;j--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
}

int main()
{
	SqList L;
	InitList(&L);
	//操作
	ListInsert(&L,3,3);    //在顺序表第3个位置(位序)插入数值3
	return 0;
}