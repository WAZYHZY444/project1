/*
#include <stdio.h>
#include <stdlib.h>
void GetMemory(char* p)
{
	p=(char*)malloc(100);  //内存泄漏，p出了作用域后被销毁
}
void Test(void)
{
	char* str=NULL;
	GetMemory(str);
	strcpy(str,"Hello World");  //str始终是个空指针
	printf(str);
}
int main()
{
	Test();
	return 0;
}
*/