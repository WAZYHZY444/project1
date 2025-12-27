#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("------扫雷游戏---------\n");
	for (int k = 0; k <= col; k++) {
		//打印列号
		printf("%d ", k);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		//打印行号
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------\n");
}

void Setmine(char board[ROWS][COLS], int rows, int cols)
{
	int count = EASY_COUNT; //雷的数量
	while (count) {
		//生成随机行号
		int x = rand() % rows + 1; //1~9
		//生成随机列号
		int y = rand() % cols + 1; //1~9
		//布置雷
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;    //只有当雷布置成功后，count才减一
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++){
		for (int j = y - 1; j <= y + 1; j++){
			if (mine[i][j] == '1'){
				count++;
			}
		}
	}
	return count;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;  //找到非雷的个数
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入排查雷的坐标:>");
		scanf("%d %d", &x, &y);
		//判断输入的坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*') {
				printf("该位置已经排查过，请重新输入！\n");
				continue;
			}
			
			//判断是否排查到雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！\n");
				//显示布置好的雷的信息
				DisplayBoard(mine, row, col);
				break;
			}
			else //没有排查到雷
			{
				win++;  //找到非雷的个数加1
				//统计周围8个格子有多少雷
				int count = get_mine_count(mine, x, y);
				//将统计的结果更新到show数组中
				show[x][y] = count + '0';     //转换成数字字符
				//显示排查后的游戏界面
				DisplayBoard(show, row, col); 
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入！\n");
		}
	}
	if (win == row * col - EASY_COUNT) {
		printf("恭喜你，排查成功！\n");
		//显示布置好的雷的信息
		DisplayBoard(mine, row, col);
	}
}