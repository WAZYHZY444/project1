#include <stdio.h>
int main()
{
	int a[4]={1,2,3,4};
	int* ptr1=(int*)(&a+1);
	int* ptr2=(int*)((int)a+1);
	printf("%x %x",ptr1[-1],*ptr2);
	return 0;
}
//a=0x0012ff40
//a+1->0x0012ff44  (int)a+1->0x0012ff41