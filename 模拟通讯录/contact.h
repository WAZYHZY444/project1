#pragma once
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>

#define DEFAULT_SIZE 3  //默认的初始容量
#define INC_SIZE 2      //每次增加的容量
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
//类型的声明

//人的信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
} PeoInfo;

//通讯录

//静态版本
/*
typedef struct Contact
{
	PeoInfo data[MAX]; //存放人的信息
	int count;         //记录当前通讯录中人的个数
} Contact
*/

//动态版本
typedef struct Contact
{
    PeoInfo* data;
    int count;
	int capacity;  //当前通讯录的容量
} Contact; 

//初始化通讯录
void InitContact(Contact* pc);

//销毁通讯录
void DestroyContact(Contact* pc);

//增加联系人到通讯录
void AddContact(Contact* pc);

//打印通讯录中的信息
void ShowContact(const Contact* pc);

// 删除联系人
void DelContact(Contact* pc);

//查找联系人
void SearchContact(Contact* pc);

//修改联系人
void ModifyContact(Contact* pc);

//排序联系人
void SortContact(Contact* pc);

//保存联系人到文件
void SaveContact(const Contact* pc);

//加载文件中的联系人到通讯录
void LoadContact(Contact* pc);