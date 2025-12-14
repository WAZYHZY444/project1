#include <stdio.h>
int main()
{
	int a[5]={1,2,3,4,5};
	int* ptr=(int*)(&a+1);
//&a + 1 的类型是int(*)[5]（指向包含5个int的数组的指针）
//所以强制类型转换int(*)[5]->int*
	printf("%d %d\n",*(a+1),*(ptr-1));
	return 0;
}