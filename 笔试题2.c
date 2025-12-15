#include <stdio.h>
struct Test
//x64环境
{
	//优化
	char* pcName;
    short sBa[4];
    int Num;
    short sDate;
    char cha[2]; //共24字节
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4]; //共32字节
}*p=(struct Test*)0x100000;
//64位系统通常要求8字节对齐（特别是对于包含8字节指针的结构体）
/*
8字节的指针必须放在8的倍数位置
为了让东西放对位置，中间要留空位
这些空位让总大小从24变成了32，它们占着位置，但没有存储有意义的数据
速度快：CPU读取对齐的数据更快
效率高：一次能读取完整数据
硬件要求：有些CPU直接不支持读取未对齐的数据
*/
int main()
{
	printf("%p\n",p+0x1);
	printf("%p\n",(unsigned long)p+0x1);
	printf("%p\n",(unsigned int*)p+0x1);
	return 0;
}