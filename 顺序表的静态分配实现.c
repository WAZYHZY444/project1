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
		//插入操作：从最后一个元素依次向后移动
		L.data[j]=L.data[j-1];    //易混点：i指向的是位序(元素在第几个)，j指向的是数组角标
	}
	L.data[i-1]=e;
	L.length++;
	return true;
}

bool ListDelete(SqList* L,int i)
{
	if(i<1||i>L.length+1){
		return false;
	}
	int e=L.data[i-1];
	for(int j=i;j<length;j++){
		//删除操作：从前面的元素依次向前移动
		L.data[j-1]=L.data[j];
	}
	L.length--;
	return e;
}

int main()
{
	SqList L;
	InitList(&L);
	//操作
	ListInsert(&L,3,3);    //在顺序表第3个位置(位序)插入数值3
	
	int e=ListDelete(&L,3);      //删除第3个元素
	if(e){
		printf("删除的第3个元素为%d\n",e);
	}else{
		printf("位序i不合法，删除失败");
	}
	return 0;
}