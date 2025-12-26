#include <stdio.h>
//offsetof在结构体内存对齐时，求偏移量
struct S
{
	char c1;
	int i;
	char c2;
};

#define OFFSETOF(type,m_name) (size_t)&(((type*)0)->m_name)
//当结构体第一个元素的起始地址为0时，后面元素的偏移量就等于起始地址
int main()
{
	struct S s={0};
	printf("%d\n",OFFSETOF(struct S,c1));
	printf("%d\n",OFFSETOF(struct S,i));
	printf("%d\n",OFFSETOF(struct S,c2));
	return 0;
}