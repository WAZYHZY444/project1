#include <stdio.h>
int main()
{
	int a[3][2]={(0,1),(2,3),(4,5)}; //逗号表达式
	int* p;
	p=a[0]; //a[0]是第一行的数组名，即a[0][0]
	printf("%d",p[0]);  //p[0]->*(p+0)
	return 0;
}

//1 3
//5 0
//0 0