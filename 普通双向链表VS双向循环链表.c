#include <stdio.h>
#include <stdlib.h>

//双向链表VS双向循环链表
typedef struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

//创建节点
Node* createNode(int val)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=val;
	
	//普通双向链表
//	newnode->next=NULL;
//	newnode->prev=NULL;
	
	//双向循环链表
	newnode->next=newnode;
	newnode->prev=newnode;
	
	return newnode;
}

//尾插
void addTail(Node** head,Node** tail,int val)
{
	Node* newnode=createNode(val);
	if(*head==NULL){
		*head=newnode;
		*tail=newnode;
		return;
	}
	
	//普通双向链表
//	(*tail)->next=newnode;
//	newnode->prev=*tail;
//	*tail=newnode;
	
	//双向循环链表
	newnode->prev=*tail;
	newnode->next=*head;
	(*tail)->next=newnode;
	(*head)->prev=newnode;
	*tail=newnode;
}

//遍历
void show(Node* head)
{
	if(head==NULL) return;
	Node* p=head;
	
	//普通双向链表
//	while(p!=NULL){
//		printf("%d ",p->data);
//		p=p->next;
//	}
	
	//双向循环链表
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
	Node* cur=*head;
	
//--------------普通双向链表---------------------//
//	while(cur!=NULL&&cur->data!=val){
//		cur=cur->next;
//	}
//	
//	if(cur==NULL) return;
//	if(cur->prev!=NULL)
//		cur->prev->next=cur->next;
//	else
//		*head=cur->next;  //删头
//	
//	if(cur->next!=NULL)
//		cur->next->prev=cur->prev;
//	else
//		*tail=cur->prev;  //删尾
//
//	free(cur);
	
//--------------双向循环链表---------------------//
	do{
		if(cur->data==val) break;
		cur=cur->next;
	}while(cur!=*head);
	
	if(cur==*head&&cur->data!=val) return;
	
	cur->prev->next=cur->next;
	cur->next->prev=cur->prev;
	if(cur==*head) *head=cur->next;
	if(cur==*tail) *tail=cur->prev;
	
	free(cur);
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