# define _CRT_SECURE_NO_WARNINGS

#include "LinkList.h"

//枚举
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
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

//清空 stdin 中剩余的字符直到遇到换行或 EOF
void ClearInput(void)
{
	int ch = getchar();
	while (ch != '\n' && ch != EOF) {
		ch = getchar();
	}
}

int main()
{
	//初始化链表
	InitLinkList();

	int input = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		/*在菜单用 scanf("%d", &input) 读取数字后，回车符仍留在 stdin。
		  随后 AddEvent 里第一个 fgets 会读到这个残留的换行，从而读取到空字符串，导致提示“标题不能为空”*/
		ClearInput();

		switch (input)
		{
		case ADD:
			AddEvent();
			break;
		case DEL:
			DeleteEvent();
			break;
		case SEARCH:
			SearchEvent();
			break;
		case UPDATE:
			UpdateEvent();
			break;
		case SHOW:
			DisplayEvent();
			break;
		case SORT:
			SortEvent();
			break;
		case EXIT:
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input != 0);

	DestroyLinkList();
	return 0;
}