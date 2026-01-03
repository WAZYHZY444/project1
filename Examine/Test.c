# define _CRT_SECURE_NO_WARNINGS

#include "LinkList.h"

enum Option
{
	EXIT,
	ADD,
	DEL,
	UPDATE,
	SHOW,
	SORT
};

void menu()
{
	printf("************************************************\n");
	printf("*****   1.add          2.del     ***************\n");
	printf("*****   3.search       4.modify  ***************\n");
	printf("*****   5.show        6.sort     ***************\n");
	printf("*****   0.exit                   ***************\n");
	printf("************************************************\n");
}

void test()
{
	//初始化链表

}
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
			case ADD:
				break;
			case DEL:
				break;
			case UPDATE:
				break;
			case SHOW:
				break;
			case SORT:
				break;
			case EXIT:
				break;
			default:
				printf("选择错误\n");
				break;
		}
	} while (input != 0);

	test();

	return 0;
}