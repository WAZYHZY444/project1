#include <stdio.h>
#include <stdlib.h>

//单链表VS单向循环链表
typedef struct Node{
	int data;
	struct Node* next;
}Node;

//新建节点
Node* createNode(int val)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=val;
	
	//普通单链表
//	newnode->next=NULL;
	
	//单向循环链表
	newnode->next=newnode;
	
	return newnode;
}

//尾插法
void addTail(Node** head,Node** tail,int val)
{
	Node* newnode=createNode(val);
	if(*head==NULL){
		*head=newnode;
		*tail=newnode;
		return;
	}
	
	//普通链表
//	(*tail)->next=newnode;
//	*tail=newnode;
	
	//单向循环链表
	newnode->next=*head;
	(*tail)->next=newnode;
	*tail=newnode;
}

//遍历
void show(Node* head)   //head指针不需要移动，所以是一维指针
{
	if(head==NULL) return;
	Node* p=head;
	
	//普通链表
//	while(p!=NULL){
//		printf("%d ",p->data);
//		p=p->next;
//	}
	
	//单向循环链表
	do{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=head);
	
	printf("\n");
}

//按值删除
void delVal(Node** head,Node** tail,int val)
{
	if(*head==NULL) return;
	
//===========================================================//	
//-------------普通单链表----------------------//
	//这是没有头节点(哑节点)的写法,head是指向第一个节点的指针
	//Node* prev=head; Node* cur=prev->next; head是第一个节点前面的哑节点，cur是指向第一个节点的指针
//	Node* prev=NULL;
//	Node* cur=*head;
//	//查找
//	while(cur!=NULL&&cur->data!=val){
//		prev=cur;
//		cur=cur->next;
//	}
//	//没找到
//	if(cur==NULL) return;
//	//删除头节点
//	if(cur==*head){
//		*head=cur->next;
//	}
//	//删除尾节点
//	else if(cur==*tail){
//		prev->next=NULL;
//		*tail=prev;
//	}
//	//删除中间节点
//	else{
//		prev->next=cur->next;
//	}
//	free(cur);
	
//-------------单向循环链表-------------------//
	Node* prev=*tail;
	Node* cur=*head;
	//查找
	do{
		if(cur->data==val) break;
		prev=cur;
		cur=cur->next;
	}while(cur!=*head);
	//没找到
	if(cur==*head&&cur->data!=val) return;
	//只有一个节点（循环链表）
	if(cur->next==cur){
		*head=NULL;
		*tail=NULL;
		free(cur);
		return;
	}
	//删除头节点
	if(cur==*head){
		*head=cur->next;
		//循环链表需要维护尾指针
		(*tail)->next=*head;
	}
	//删除尾节点
	else if(cur==*tail){
		prev->next=*head;
		*tail=prev;
	}
	//删除中间节点
	else{
		prev->next=cur->next;
	}
	free(cur);
//======================================================//

}

int main()
{
	Node* head=NULL;
	Node* tail=NULL;
	
	addTail(&head,&tail,10);
	addTail(&head,&tail,20);
	addTail(&head,&tail,30);
	
	show(head);
	
	delVal(&head,&tail,20);
	show(head);
	
	return 0;
}