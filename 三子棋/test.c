#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu(void)
{
	printf("***********************************\n");
	printf("*******  1.play     0.exit  *******\n");
	printf("***********************************\n");
	fflush(stdout);
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘的函数
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		//判断输赢
		ret=IsWin(board,ROW,COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);

		//电脑下棋
		ComputerMove(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	DisplayBoard(board, ROW, COL);
	if(ret=='*')
	{
		printf("玩家赢了!\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了!\n");
	}
	else
	{
		printf("平局!\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));  //设置随机数的生成起点
	int input = 0;
	do {
		menu();
		printf("请选择:>");
		fflush(stdout);
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break; 
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误!\n");
			break;
		}
	} while (input);

	return 0;
}