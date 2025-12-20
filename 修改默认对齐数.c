#include <stdio.h>
#pragma pack(4)  //修改默认对齐数为4，默认对齐数可以修改
struct S
{
	int i;
	double d;	
};
#pragma pack()  //恢复
int main()
{
	printf("%zu\n",sizeof(struct S));
	return 0;
}