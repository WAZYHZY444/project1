#include <stdio.h>
#include <string.h>
//长度受限制的字符串函数
/*
int main()
{
//strncpy如果要求复制的字符数大于源字符串的个数，就补'\0'
	char arr1[20]={'\0'};
	char arr2[]="hello world";
	strncpy(arr1,arr2,7);
	printf("%s\n",arr1);
	return 0;
}
*/

/*
int main()
{
//strncat再追加的过程中，会覆盖目标空间字符串末尾的'\0',追加完成后会在末尾添加一个'\0'
//strncat如果要求追加的字符数大于源字符串的个数，不会补'\0'
	char arr1[]="hello ";
	char arr2[]="world";
	strncat(arr1,arr2,3);
	printf("%s\n",arr1);
	return 0;
}
*/

int main()
{
	char arr1[]="abcdef";
	char arr2[]="abc";
	int ret=strncmp(arr1,arr2,4);
	printf("%d\n",ret);
	if(ret==0)printf("==\n");
	else if(ret>0)printf(">\n");
	else printf("<\n");
	return 0;
}