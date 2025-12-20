#include <stdio.h>
#include <stddef.h>
struct S1
{
	char c1;
	int i;
	char c2;
};

struct S2
{
	char c1;
	char c2;
	int i;
};

int main()
{
	printf("%zu\n",sizeof(struct S1));
	printf("%zu\n",sizeof(struct S2));
	printf("\n");
	//offsetof(type,member)
	printf("%d\n",offsetof(struct S1,c1));
	printf("%d\n",offsetof(struct S1,i));
	printf("%d\n",offsetof(struct S1,c2));
	printf("\n");
	printf("%d\n",offsetof(struct S2,c1));
	printf("%d\n",offsetof(struct S2,c2));
	printf("%d\n",offsetof(struct S2,i));
}