#include <stdio.h>
int main()
{
	int a[5][5];
	int (*p)[4];
	p=a;
	printf("%p %d\n",&p[4][2]-&a[4][2],&p[4][2]-&a[4][2]);
	printf("%p\n",-4);
	return 0;
}
//a->int(*)[5]
//b->int(*)[4]
//p=a  等号两边类型不相等，所以会报警告