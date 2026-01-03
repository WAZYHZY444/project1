# define _CRT_SECURE_NO_WARNINGS

#include "LinkList.h"

Event* head = NULL;
int eventCount = 0;

//创建新节点
Event* EventNode(void)
{
	Event* newEvent = (Event*)malloc(sizeof(Event));
	if (newEvent == NULL) {
		printf("%s\n", strerror(errno));
		return NULL;
	}
	newEvent->next = NULL;
	return newEvent;
}

int compareEvents(const void* a, const void* b)
{
	Event* eventA = *(Event**)a;
	Event* eventB = *(Event**)b;
	//先比较日期
	if (eventA->date != eventB->date) {
		return eventA->date - eventB->date;
	}
	//比较时间
	return eventA->time - eventB->time;
}

//检查日期的格式是否正确
bool exzamineDate(int date)
{
	//date:20251207
	int year = date / 10000;
	int month = (date % 10000) / 100;
	int day=date % 100;

	if (year < 1900 || year > 2100)return false;
	if (month < 1 || month > 12)return false;
	if (day < 1 || day > 31)return false;

	//判断闰年
	int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		daysInMonth[1] = 29;
	}
	if (day > daysInMonth[month - 1])return false;
	return true;
}

//检查时间的格式是否正确
bool exzamineTime(int time)
{
	//time:1645
	int hour = time / 100;
	int minute = time % 100;
	return (hour >= 0 && hour <=23 && minute >= 0 && minute <=59);  //如果时间格式正确返回true，否则返回false
}

//将格式化的日期转换为字符串
void stringDate(int date, char* buffer)
{
	int year = date / 10000;
	int month = (date % 10000) / 100;
	int day = date % 100;
	sprintf(buffer, "%04d-%02d-%02d", year, month, day);
}

//将格式化的时间转换为字符串
void stringTime(int time, char* buffer)
{
	int hour = time / 100;
	int minute = time % 100;
	sprintf(buffer, "%02d:%02d", hour, minute);
}

//

