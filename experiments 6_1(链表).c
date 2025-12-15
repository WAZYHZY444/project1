#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
	int data;
	struct node* next;
}LinkNode;

//打印链表
void printList(LinkNode* head)
{
	LinkNode* p; //访问指针
	if(head->next==NULL)return; //如果是空链表，不打印
	p=head->next; //指向头节点的后继节点
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	return;
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
	int n,num;
	scanf("%d",&n);
//创建头节点
//head指向头节点，p指向新节点，r指向尾节点(辅助指针变量)
	LinkNode *head,*p,*r;//结构体指针变量，LinkNode是普通变量别名
	head=(LinkNode*)malloc(sizeof(LinkNode));  //创建头节点，分配内存，malloc返回的是地址，需要强制类型转换
	head->next=NULL;  //访问头节点指针域
	r=head;  // 创建头节点后，需要初始化 r(重要，不可忽略)
	
	for(int i=0;i<n;i++){
		scanf("%d",&num);
//创建新节点
	p=(LinkNode*)malloc(sizeof(LinkNode));
	p->data=num;
	p->next=NULL;//用尾插法，新插入的节点始终是尾节点，尾节点的指针域始终为NULL
//r指针指向尾节点
	r->next=p;
	//r=p;
	r=r->next;
	}
	scanf("%d",&num); //可以不重新定义一个变量
	r=head; //r指向的是p访问当前节点的前驱节点
	p=head->next; //p访问当前节点
	while(p->next!=NULL){
		//匹配
		if(p->data==num){
			r->next=p->next; //删除
			free(p);         //释放
			p=r->next;
		}else{
			r=p;
			p=p->next;
		}
		
	}
//处理尾节点
	if(p->data==num){
		r->next=NULL;
		free(p);
	}
	printList(head);
	destroyList(head);
	return 0;
}
//在前面的for循环结束后，r,p,num等的作用释放出来，所以可以不需要重定义新的变量

/*
while(strcmp(scanf("%s",sID),"end")!=0){  //用学号来比较
	scanf("%d ",&num);  //6
//创建新节点
	p=(LinkNode*)malloc(sizeof(LinkNode));
	p->data=num;
	p->next=NULL;//用尾插法，新插入的节点始终是尾节点，尾节点的指针域始终为NULL
//r指针指向尾节点
	r->next=p;
	//r=p;
	r=r->next;
}
*/