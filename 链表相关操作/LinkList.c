#include"LinkList.h"
//初始化链表
struct LinkNode* Init_LinkList()
{
	//创建头节点
	struct LinkNode* header = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	if (header == NULL) {  // malloc 可能返回 NULL，如果不检查直接使用 header->data，会导致对空指针的解引用。
		printf("内存分配失败！\n");
		return NULL;
	}
	header->data = -1;   //头节点数据域不存储数据
	header->next = NULL;

	//尾部指针，始终指向尾节点
	struct LinkNode* pRear = header;

	int val = -1;
	while (true) {
		printf("输入插入的数据：\n");
		scanf("%d", &val);
		if (val == -1) {  //避免死循环，输入-1结束
			break;
		}
		//创建新节点
		struct LinkNode* newnode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
		newnode->data = val;
		newnode->next = NULL; ////用尾插法，新插入的节点始终是尾节点，尾节点的指针域始终为NULL

		//将新节点插入到链表尾部
		pRear->next = newnode;

		//更新尾部指针指向
		pRear = newnode;
	}
	return header;
}


//在值为oldval的位置插入新的数据newval
void InsertByValue_LinkList(struct LinkNode* header, int oldval, int newval)
{
	if (NULL == header) {
		return;
	}
	//两个辅助指针变量
	struct LinkNode* pPrev = header;
	struct LinkNode* pCurrent = pPrev->next;

	while (pCurrent != NULL) {
		if (pCurrent->data == oldval) {
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
#if 0   //如果oldval在链表中不存在,newval就放在尾部
	//如果pCurrent为NULL，说明链表中不存在值为oldval的节点
	if (pCurrent == NULL) {
		return;
	}
#endif

	//创建新节点
	struct LinkNode* newnode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	if (newnode == NULL) { // 检查内存分配是否成功
		printf("内存分配失败！\n");
		return;
	}
	newnode->data = newval;
	newnode->next = NULL;

	//新节点插入到链表中
	newnode->next = pCurrent;
	pPrev->next = newnode;

}


//删除值为val的节点
void DeleteByValue_LinkList(struct LinkNode* header, int delValue)
{
	if(header==NULL){
		return;
	}
	//两个辅助指针变量
	struct LinkNode* pPrev = header;
	struct LinkNode* pCurrent = pPrev->next;
	while (pCurrent != NULL) {
		if (pCurrent->data == delValue) {
			//删除节点,重新建立删除节点前后节点的连接
			pPrev->next = pCurrent->next;
			struct LinkNode* temp = pCurrent; // 保存要释放的节点
			free(temp); // 释放删除节点的内存
			pCurrent = pPrev->next; // 更新pCurrent指针			
		}
		else {
			//继续向后查找
			pPrev = pCurrent;
			pCurrent = pCurrent->next;
		}
	}
}


//遍历链表
void Foreach_LinkList(struct LinkNode* header)
{
	//辅助指针变量
	struct LinkNode* pCurrent = header->next; //因为头节点的数据域为空，所以跳过头节点，遍历不经过头节点
	while (pCurrent != NULL)
	{
		printf("%d ", pCurrent->data);
		pCurrent = pCurrent->next;  //指向下一个节点
	}
}


//销毁链表
void Destroy_LinkList(struct LinkNode* header)
{
	if (header==NULL) {
		return;
	}
	//辅助指针变量
	struct LinkNode* pCurrent = header;
	while (pCurrent != NULL)
	{
		//先保存当前节点的下一个节点地址
		struct LinkNode* pNext = pCurrent->next;
		//释放当前节点内存
		printf("%d节点被销毁!\n", pCurrent->data);
		free(pCurrent);
		//pCurrent指向下一个节点
		pCurrent = pNext;
	}
}


//清空链表
void Clear_LinkList(struct LinkNode* header)
{
	if (header==NULL) {
		return;
	}
	//辅助指针变量
	struct LinkNode* pCurrent = header->next;  //头节点不清空
	while (pCurrent != NULL) {
		//先保存当前节点的下一个节点地址，如果不保存，清空了当前节点，就找不到后面的节点了
		struct LinkNode* pNext = pCurrent->next;
		//释放当前节点内存
		free(pCurrent);
		//pCurrent指向下一个节点
		pCurrent = pNext;
	}
	header->next = NULL;
}