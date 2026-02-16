/*
#include <stdio.h>
int main()
{
//	char ch='z';
//	char* pc=&ch;
//	*pc='y';
//	printf("%c\n",pc);
//当你传递指针 pc 给 %c 时：
//指针值（内存地址）被当作 ASCII 码解释
//这个地址值对应的 ASCII 字符恰好是 'G'
//这是未定义行为，不同编译器/环境下可能输出不同的字符
//	return 0;

	char* p="abcdef";
	printf("%s\n",p);
	return 0;
}
*/

#include <stdio.h>
int main()
{
	const char* p1="abcdef";
	const char* p2="abcdef";
//p1和p2存的都是字符串首字符a的地址，共用没有重新创建新的空间，所以地址相同,p1==p2

	char arr1[]="abcdef";
	char arr2[]="abcdef";
//arr1和arr2是两个不同的数组，会开辟新的空间，相同的字符串但是地址不同，所以arr1!=arr2
	
	if(p1==p2)
		printf("p1=p2\n");
	else
		printf("p1!=p2\n");
		
	if(arr1==arr2)
		printf("arr1=arr2\n");
	else
		printf("arr1!=arr2\n");
		return 0;
}





