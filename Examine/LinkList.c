
# define _CRT_SECURE_NO_WARNINGS

#include "LinkList.h"

Event* head = NULL;   //指向头节点的指针
Event* tail = NULL;   //指向尾节点的指针
int eventCount = 0;

//qsort比较函数
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

//移除fgets末尾的换行符
void RemoveLine(char* str)
{
	int len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}

//初始化链表
void InitLinkList(void)
{
	if (head != NULL) {
		return;
	}
	//创建头节点
	head = (Event*)malloc(sizeof(Event));
	if (head == NULL) {
		return;
	}
	// 初始化头节点的内容，避免未初始化数据被比较或打印
	head->title[0] = '\0';
	head->description[0] = '\0';
	head->date = 0;
	head->time = 0;
	head->next = NULL;
	tail = head;    //初始化尾指针也要指向头节点
	eventCount = 0;
}
//检查日期的格式是否正确
bool exzamineDate(int date)
{
	//date:20251207
	int year = date / 10000;
	int month = (date % 10000) / 100;
	int day = date % 100;

	if (year < 1900 || year > 2100) return false;
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;

	//判断闰年
	int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		daysInMonth[1] = 29;
	}
	if (day > daysInMonth[month - 1]) return false;
	return true;
}

//检查时间的格式是否正确
bool exzamineTime(int time)
{
	//time:1645
	int hour = time / 100;
	int minute = time % 100;
	return (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59);  //如果时间格式正确返回true，否则返回false
}


//按照标题查找事件
Event* FindEvent(const char* title)
{
	if (head == NULL) return NULL;
	Event* current = head->next; // 跳过头节点（哨兵）
	while (current != NULL) {
		if (strcmp(current->title, title) == 0) {
			return current;
		}
		current = current->next;
	}
	return NULL;  //若没有找到就返回NULL
}


//添加事件
void AddEvent(void)
{
	if (head == NULL) {
		InitLinkList();
	}
	Event* newEvent = (Event*)malloc(sizeof(Event));
	if (newEvent == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	newEvent->next = NULL;
	newEvent->title[0] = '\0';
	newEvent->description[0] = '\0';
	printf("输入事件标题：");
	fgets(newEvent->title, sizeof(newEvent->title), stdin);
	RemoveLine(newEvent->title);
	//避免标题为空
	if (strlen(newEvent->title) == 0) {
		printf("标题不能为空！\n");
		free(newEvent);        //注意：此处以及下面的两处free只能写在if语句里，只有当这两种情况出现，才释放空间，不是这两种情况，还有后续的操作，不能释放
		return;
	}
	//避免标题重复出现
	if (FindEvent(newEvent->title) != NULL) {
		printf("标题已存在！\n");
		free(newEvent);
		return;
	}

	//输入事件内容
	printf("请输入事件内容：");
	fgets(newEvent->description, sizeof(newEvent->description), stdin);
	RemoveLine(newEvent->description);

	//输入日期
	printf("请输入日期（格式 YYYYMMDD）：");
	if (scanf("%d", &newEvent->date) != 1) {
		printf("输入错误！\n");
		getchar();
		free(newEvent);
		return;
	}
	getchar();  //清除换行符
	if (!exzamineDate(newEvent->date)) {
		printf("日期格式不正确！\n");
		// 可选择在此返回 / 不插入。当前保持插入但提示。
	}
	//输入时间
	printf("请输入时间（格式 HHMM）：");
	if (scanf("%d", &newEvent->time) != 1) {
		printf("输入错误！\n");
		getchar();
		free(newEvent);
		return;
	}
	getchar();
	if (!exzamineTime(newEvent->time)) {
		printf("时间格式不正确！\n");
	}

	//插入链表（尾插法）
	if (tail == NULL) { // 保险检查
		InitLinkList();
	}
	newEvent->next = NULL;
	tail->next = newEvent;
	tail = newEvent;
	eventCount++;
	//排序
	SortEvent();
	printf("事件添加成功！\n");
}

//显示事件
void DisplayEvent(void)
{
	if (head == NULL || head->next == NULL) {
		printf("没有日程安排！\n");   //没有创建链表或无实际事件
		return;
	}
	printf("-----------所有日程安排--------------\n");
	Event* current = head->next;  //跳过头节点
	int i = 1;
	while (current != NULL) {
		int year = current->date / 10000;
		int month = (current->date % 10000) / 100;
		int day = current->date % 100;
		int hour = current->time / 100;
		int minute = current->time % 100;

		printf("事件%d\n", i);
		printf("标题:%s\n", current->title);
		printf("日期:%d年%2d月%2d日\n", year, month, day);
		printf("时间:%2d:%2d\n", hour, minute);
		printf("内容:%s\n", current->description);
		printf("-----------------------------------\n");
		i++;
		current = current->next;  //移动指针
	}
	printf("总共%d个事件\n", eventCount);
}

//更新事件（相当于修改）
void UpdateEvent(void)
{
	char Title[100];
	printf("请输入要更新事件的标题：");
	fgets(Title, sizeof(Title), stdin);
	RemoveLine(Title);

	Event* p = FindEvent(Title);   //FindEvent函数返回的是指针，创建一个辅助指针，指向要更新事件的节点
	if (p == NULL) {
		printf("要更新的事件不存在！\n");
		return;
	}
	printf("找到该事件！\n");
	printf("请输入更新的信息\n");

	printf("新日期（YYYYMMDD）：");
	int Newdate;
	if (scanf("%d", &Newdate) == 1) {
		p->date = Newdate;
	}
	else {
		printf("输入错误，保持原日期。\n");
		getchar();
	}
	printf("新时间（HHMM）：");
	int Newtime;
	if (scanf("%d", &Newtime) == 1) {
		p->time = Newtime;
	}
	else {
		printf("输入错误，保持原时间。\n");
		getchar();
	}
	getchar(); // 清除 scanf 留下的换行，避免下面的 fgets 读到空行
	printf("新内容：");
	char Newdescription[200];
	fgets(Newdescription, sizeof(Newdescription), stdin);
	RemoveLine(Newdescription);
	strncpy(p->description, Newdescription, sizeof(p->description) - 1);
	p->description[sizeof(p->description) - 1] = '\0';

	//重新排序
	SortEvent();
	printf("时间更新成功！\n");
}

//删除事件
void DeleteEvent(void)
{
	char Title[100];
	printf("请输入要删除事件的标题：");
	fgets(Title, sizeof(Title), stdin);
	RemoveLine(Title);

	if (head == NULL) {
		printf("链表未初始化！\n");
		return;
	}

	Event* pre = head;
	Event* cur = head->next;

	while (cur != NULL) {
		if (strcmp(cur->title, Title) == 0) {
			//删除节点
			pre->next = cur->next;
			//如果删除的是尾节点，更新尾指针
			if (cur == tail) {
				tail = pre;
			}
			free(cur);
			eventCount--;
			printf("事件删除成功!\n");
			return;
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	printf("未找到要删除的是事件！\n");
}

//按标题搜索并显示单个事件
void SearchEvent(void)
{
	char Title[100];
	printf("请输入要查找事件的标题：");
	fgets(Title, sizeof(Title), stdin);
	RemoveLine(Title);

	Event* p = FindEvent(Title);
	if (p == NULL) {
		printf("未找到该事件!\n");
		return;
	}
	int year = p->date / 10000;
	int month = (p->date % 10000) / 100;
	int day = p->date % 100;
	int hour = p->time / 100;
	int minute = p->time % 100;

	printf("标题:%s\n", p->title);
	printf("日期:%d年%2d月%2d日\n", year, month, day);
	printf("时间:%2d:%2d\n", hour, minute);
	printf("内容:%s\n", p->description);
}

//链表排序
void SortEvent(void)
{
	if (head == NULL || head->next == NULL) return;

	// 先计算实际节点数以避免 eventCount 与链表不一致导致越界
	int actualCount = 0;
	Event* temp = head->next;
	while (temp != NULL) {
		actualCount++;
		temp = temp->next;
	}
	if (actualCount == 0) {
		// 没有实际节点
		head->next = NULL;
		tail = head;
		eventCount = 0;
		return;
	}

	//创建数组存储节点指针
	Event** ARR = (Event**)malloc(actualCount * sizeof(Event*));
	if (ARR == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	Event* p = head->next;
	for (int i = 0; i < actualCount && p != NULL; i++) {
		ARR[i] = p;
		p = p->next;  //指针移动
	}

	//排序
	qsort(ARR, actualCount, sizeof(Event*), compareEvents);

	//重建链表
	head->next = ARR[0];
	for (int i = 0; i < actualCount - 1; i++) {   //防止数组越界访问
		ARR[i]->next = ARR[i + 1];
	}
	ARR[actualCount - 1]->next = NULL;  //尾节点的指针域为NULL
	tail = ARR[actualCount - 1];        //注意：尾节点要实时更新

	free(ARR);

	// 同步 eventCount（以实际节点数为准，避免不一致）
	eventCount = actualCount;
}

//销毁链表
void DestroyLinkList(void)
{
	if (head == NULL) return;   //链表没有初始化

	Event* p = head->next;
	while (p != NULL) {
		Event* Next = p->next;   //先保存下一个结点的地址
		free(p);
		p = Next;
	}
	free(head);
	head = NULL;
	tail = NULL;
	eventCount = 0;
}
