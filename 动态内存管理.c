#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
/*
int main()
{
	//开辟动态内存
	int* p=(int*)malloc(40);
	if(p==NULL){      //动态内存开辟失败
		printf("%s\n",strerror(errno));
		return 1;
	}
	for(int i=0;i<10;i++){
		*(p+i)=i;
	}
	for(int i=0;i<10;i++){
		printf("%d ",*(p+i));
	}

	free(p);
	p=NULL;
	
	return 0;
}
*/

/*
int main()
{
//calloc在开辟动态内存的同时会把元素初始化为0
	int* p=(int*)calloc(10,sizeof(int));
	if(p==NULL){
		printf("%s\n",strerror(errno));
		return 1;
	}
	for(int i=0;i<10;i++){
		printf("%d ",*(p+i));
	}
	
	free(p);
	p=NULL;
	
	return 0;
}
*/

int main()
{
	int* p=(int*)malloc(40);
	if(p==NULL){
		printf("%s\n",strerror(errno));
		return 1;
	}
	//使用
	for(int i=0;i<10;i++){
		*(p+i)=i+1;
	}
	//扩容(增加40个字节)
	int* ptr=(int*)realloc(p,80);    //声明一个辅助指针，避免扩容失败，导致p返回为NULL
	if(ptr!=NULL){
		p=ptr;
	}
	for(int i=0;i<10;i++){
		printf("%d ",*(p+i));
	}
	free(p);
	p=NULL;
	
	return 0;
}
/*
注意：
1.p 和 ptr 指向同一块内存：当 realloc 成功时，p = ptr; 使两个指针指向相同的内存地址
2.free(p) 已经释放了这块内存：释放的是指针指向的内存，而不是指针本身
3.多个指针指向同一内存时，只需要释放一次：重复释放会导致未定义行为
4.ptr 是局部变量，函数结束后自动销毁
*/