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

extern Event* head;   //链表头指针
extern int eventCount;

//初始化链表
void InitLinkList(void);

//检查日期的格式是否正确
bool exzamineDate(int date);

//检查时间的格式是否正确
bool exzamineTime(int time);

//qsort比较函数
int compareEvents(const void* a, const void* b);

//移除fgets末尾的换行符
void RemoveLine(char* str);

//按照标题查找事件
Event* FindEvent(const char* title);

//添加事件
void AddEvent(void);

//显示事件
void DisplayEvent(void);

//更新事件（相当于修改）
void UpdateEvent(void);

//删除事件
void DeleteEvent(void);

//按标题搜索并显示单个事件
void SearchEvent(void);

//链表排序
void SortEvent(void);

//销毁链表
void DestroyLinkList(void);