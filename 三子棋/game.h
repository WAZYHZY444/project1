#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
//找没有被占用的位置下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢
//返回值：'*'玩家赢，'#'电脑赢，'Q'平局，'C'继续
char IsWin(char board[ROW][COL], int row, int col);
