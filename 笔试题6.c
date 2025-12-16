#include <stdio.h>
int main()
{
	int aa[2][5]={1,2,3,4,5,6,7,8,9,10};
	int* ptr1=(int*)(&aa+1);
	int* ptr2=(int*)(*(aa+1)); //aa+1->第二行的一维数组
	printf("%d %d",*(ptr1-1),*(ptr2-1));
	return 0;
}