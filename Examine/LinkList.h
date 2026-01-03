#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

typedef struct Event
{
	char title[100];
	char description[256];
	int date;  // Format: YYYYMMDD
	int time;  // Format: HHMM
	struct Event* next;
} Event;

//创建新节点
Event* EventNode(void);

//检查日期的格式是否正确
bool exzamineDate(int date);

//检查时间的格式是否正确
bool exzamineTime(int time);

//将格式化的日期转换为字符串
void stringDate(int date, char* buffer);

//将格式化的时间转换为字符串
void stringTime(int time, char* buffer);