#include <stdio.h>
int main()
{
	char* a[]={"work","at","alibaba"};
	char** pa=a; //pa指向的对象是char*类型，所以当pa+1跳过一个char*类型  
	pa++;
	printf("%s\n",*pa);
	return 0;
}