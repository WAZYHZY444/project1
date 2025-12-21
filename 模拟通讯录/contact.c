#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX) { // assuming MAX_CONTACT_COUNT is defined
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[pc->count].age);
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("增加成功！\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	printf("========================Contact List==============================\n");
	printf("%-10s\t%-5s\t%-5s\t%-10s\t%-10s\n", "名字", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < pc->count; i++) {
		printf("%-10s\t%-5d\t%-5s\t%-10s\t%-10s\n",	pc->data[i].name,
													pc->data[i].age,
													pc->data[i].sex,
													pc->data[i].tele,
													pc->data[i].addr);
	}
}


static FindByName(Contact* pc, char name[])    //添加static表示该函数只能在本文件使用
{
	assert(pc);
	for (int i = 0; i < pc->count; i++) {
		if (strcmp(pc->data[i].name, name) == 0) {
		return i;
		}
	}
	return -1;
}
void DelContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除的联系人:>");
	scanf("%s", name);
	if (pc->count == 0) {
		printf("通讯录为空，没有信息删除\n");
		return;
	}


	//删除
	//1.查找
	int pos=FindByName(pc, name);
	if (pos == -1) {
		printf("要删除的联系人不存在\n");
		return;
	}
	//2.删除
	for(int i = pos; i < pc->count - 1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}

void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找的联系人:>");
	scanf("%s", name);
	//1.查找
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("要查找的联系人不存在\n");
		return;
	}
	//2.打印该联系人信息
	printf("%-10s\t%-5s\t%-5s\t%-10s\t%-10s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-10s\t%-5d\t%-5s\t%-10s\t%-10s\n", pc->data[pos].name,
												pc->data[pos].age,
												pc->data[pos].sex,
												pc->data[pos].tele,
												pc->data[pos].addr);
}

void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的联系人:>");
	scanf("%s", name);
	//1.查找
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("要修改的联系人不存在\n");
		return;
	}
	printf("请重新输入该联系人信息：\n");
	//2.修改该联系人信息
	printf("请输入名字:>");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[pos].age);
	printf("请输入性别:>");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pos].addr);

	printf("修改成功！\n");
}

int cmp_poe_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//按照名字排序 
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_poe_by_name);
	printf("排序成功！\n");
}
	