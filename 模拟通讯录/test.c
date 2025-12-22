#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
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
int main()
{
	int input = 0;
	Contact con;  //定义通讯录变量
	//初始化通讯录
	InitContact(&con);  //结构体传参最好传地址
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
			case ADD:
				AddContact(&con);
				break;
			case DEL:
				DelContact(&con);
				break;
			case SEARCH:
				SearchContact(&con);
				break;
			case MODIFY:
				ModifyContact(&con);
				break;
			case SHOW:
				ShowContact(&con);
				break;
			case SORT:
				SortContact(&con);
				break;
			case EXIT:
				printf("exit\n");
				break;
				default:
					printf("选择错误\n");
					break;
		}
	}while (input != 0);
	return 0;
}