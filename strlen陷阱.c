#include<stdio.h>
#include <string.h>
int main()
{
	//strlen函数的返回类型是size_t-->unsigned int
	if(strlen("abc")-strlen("abcdef")>=0){
		printf(">\n");
	}else{
		printf("<\n");
	}
//-3 在无符号表示中会变成一个大正数（因为无符号数没有负数概念）
//在 32 位系统中：-3 → 4294967293（即 2³² - 3）
//所以 4294967293 >= 0 为真，输出 >	
	
	printf("%d\n",strlen("abc")-strlen("abcdef"));
//表达式 strlen("abc")-strlen("abcdef") 的结果是 size_t 类型的 4294967293
//但用 %d（有符号 int）来格式化输出
//所以系统把内存中的无符号值 4294967293 按有符号 int 解释
//4294967293 的二进制表示作为有符号 int 就是 -3
	return 0;
}