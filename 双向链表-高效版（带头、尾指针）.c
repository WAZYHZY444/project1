#include <stdio.h>
#include <stdlib.h>

//双向链表节点
typedef struct Node{
	int data;
	struct Node* next;  //后继指针
	struct Node* prev;  //前驱指针
}Node;

typedef struct{
	Node* head;
	Node* tail;
}List;

//初始化链表
List* CreateHead()
{
	List* list=(List*)malloc(sizeof(List));
	list->head=NULL;
	list->tail=NULL;
	return list;
}

//创建新节点
Node* CreateNode(int val)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=val;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}

//尾部插入
void append(List* list,int val)
{
	Node* newnode=CreateNode(val);
	//空链表
	if(list->tail==NULL){
		list->head=newnode;
		list->tail=newnode;
	}else{
		list->tail->next=newnode;
		newnode->prev=list->tail;
		list->tail=newnode;     //更新尾指针
	}
}

//头部插入
void prepend(List* list,int val)
{	
	Node* newnode=CreateNode(val);
	//空链表
	if(list->tail==NULL){
		list->head=newnode;
		list->tail=newnode;
	}else{
		newnode->next=list->head;
		list->head->prev=newnode;
		list->head=newnode;     //更新头指针
	}
}

//在第pos个位置插入(pos从0开始)
void InsertByLocation(List* list,int pos,int val)
{
	if(pos==0){
		prepend(list,val);
		return;
	}
	
	Node* temp=list->head;
	for(int i=0;temp!=NULL&&i<pos;i++){
		temp=temp->next;
	}
	if(temp==NULL) return;  
	Node* newnode=CreateNode(val);
	newnode->prev=temp->prev; 
	newnode->next=temp;
	temp->prev->next=newnode;
	temp->prev=newnode;
}

//删除值为val的节点
void DeleteByVal(List* list,int val)
{
	Node* temp=list->head;
	while(temp!=NULL&&temp->data!=val){
		temp=temp->next;
	}
	if(temp==NULL) return;
	if(temp->prev!=NULL)
		temp->prev->next=temp->next;
	else
		list->head=temp->next;  //删头
		
	if(temp->next!=NULL)
		temp->next->prev=temp->prev;
	else
		list->tail=temp->prev;  //删尾

	free(temp);
}

//删除第pos个节点
void DeleteByLocation(List* list,int pos)
{
	Node* temp=list->head;
	for(int i=0;temp!=NULL&&i<pos;i++){
		temp=temp->next;
	}
	if(temp==NULL) return;
	if(temp->prev!=NULL)
		temp->prev->next=temp->next;
	else
		list->head=temp->next;  //删头
		
	if(temp->next!=NULL)
		temp->next->prev=temp->prev;
	else
		list->tail=temp->prev;  //删尾

	free(temp);
}

int Find(List* list,int val)
{
	int pos=0;
	Node* temp=list->head;
	while(temp!=NULL&&temp->data!=val){
		pos++;
		temp=temp->next;
	}
	if(temp==NULL) return -1;
	else{
		return pos;  //pos从0开始
	}
}

//正向遍历
void printForward(List* list)
{
	Node* temp=list->head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

//反向遍历
void printBackward(List* list)
{
	Node* temp=list->tail;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}

//销毁链表
void Destory(List** list)
{
	Node* temp=(*list)->head;
	while(temp!=NULL){
		Node* Next=temp->next;
		free(temp);
		temp=Next;
	}
	free(*list);
	*list=NULL;
}

int main()
{
	List* list=CreateHead();
	
	append(list, 10);
    append(list, 20);
    append(list, 30);
    prepend(list, 5);
    InsertByLocation(list, 2, 15);

    printForward(list);   // 5 10 15 20 30
    printBackward(list);  // 30 20 15 10 5

    DeleteByVal(list, 15);
    printForward(list);   // 5 10 20 30

    DeleteByLocation(list, 1);
    printForward(list);   // 5 20 30

    printf("Find 20: %d\n", Find(list, 20)); // 1
    printf("Find 99: %d\n", Find(list, 99)); // 0

	
	Destory(&list);
	return 0;
}