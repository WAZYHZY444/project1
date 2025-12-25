#include <stdio.h>
int main()
{
	for (int i = 0; i < 10; i++) {
		printf("file:%s line:%d date:%s time:%s i=%d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);
	}
	return 0;
}