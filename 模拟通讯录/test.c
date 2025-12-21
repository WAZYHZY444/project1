#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
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
			case 1:
				AddContact(&con);
				break;
			case 2:
				DelContact(&con);
				break;
			case 3:
				SearchContact(&con);
				break;
			case 4:
				ModifyContact(&con);
				break;
			case 5:
				ShowContact(&con);
				break;
			case 6:
				SortContact(&con);
				break;
			case 0:
				printf("exit\n");
				break;
				default:
					printf("选择错误\n");
					break;
		}
	}while (input != 0);
	return 0;
}