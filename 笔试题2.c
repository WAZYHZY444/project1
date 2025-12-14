#include <stdio.h>
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
int main()
{
	printf("%p\n",p+0x1);
	printf("%p\n",(unsigned long)p+0x1);
	printf("%p\n",(unsigned int*)p+0x1);
	return 0;
}