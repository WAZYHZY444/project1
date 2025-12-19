#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct node
{
	char sID[21];
	char name[41];
	char sex;
	int year;
	int score;
	char address[41];
	struct node* next;
}LinkNode;

//反转链表实现倒序打印(不要使用递归的方式打印，会造成内存溢出)
void PprintList(LinkNode* head)
{
	if(head==NULL){  //链表不存在
		return;
	}
	//第一次遍历：计算链表长度
	int count=0;
	LinkNode* p=head;
	while(p!=NULL){
		count++;
		p=p->next;
	}
	//第二次遍历：从后往前打印
	for(int i=count-1;i>=0;i--){
		p=head;
		for(int j=0;j<i;j++){
			p=p->next;  //p移动到第i个节点
		}
		printf("%s %s %c %d %d %s\n",p->sID,p->name,p->sex,p->year,p->score,p->address);
	}
}
//销毁链表
bool destroyList(LinkNode* head)
{
	LinkNode* p; 
	if(head==NULL){
		return false;
	}
	while(head){
		p=head->next;
		free(head);
		head=p;
	}
	return true;
}

int main()
{
	int n_year,n_score;
	char n_sID[21],n_name[41],n_sex,n_address[41];

//创建头节点
//head指向头节点，p指向新节点，r指向尾节点(辅助指针变量)
	LinkNode *head,*p,*r;//结构体指针变量，LinkNode是普通变量别名
	head=(LinkNode*)malloc(sizeof(LinkNode));  //创建头节点，分配内存，malloc返回的是地址，需要强制类型转换
	head->next=NULL;  //访问头节点指针域
	r=head;  // 创建头节点后，需要初始化 r(重要，不可忽略)

	while(1){  //为真进入循环
		scanf("%s",n_sID);
		if(strcmp(n_sID,"end")==0){
			break;
		}
		scanf("%s %c %d %d %s",n_name,&n_sex,&n_year,&n_score,n_address);
	//创建新节点
		p=(LinkNode*)malloc(sizeof(LinkNode));
		//使用strcpy赋值字符串
		strcpy(p->sID,n_sID);
		strcpy(p->name,n_name);
		p->sex=n_sex;
		p->year=n_year;
		p->score=n_score;
		strcpy(p->address,n_address);
		p->next=NULL;//用尾插法，新插入的节点始终是尾节点，尾节点的指针域始终为NULL
	//r指针指向尾节点
		r->next=p;
		r=p;
	}
	PprintList(head->next);  //从第一个有效节点开始
	destroyList(head);
	return 0;
}