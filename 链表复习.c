#include <stdio.h>
#include <stdlib.h>

//-------链表指针问题-----------//
//  1.如果head进行了malloc分配空间，分配的空间大小是一个节点的大小，head是头节点  LinkNode* head=(LinkNode*)malloc(sizeof(LinkNode));
//    如果head的数据类型只是单纯的LinkNode*，head是头指针  LinkNode* head=NUll;
//头节点在传参时，不需要加取地址符，相当于传递的结构体本身，而结构体本身不需要发生改变，需要改变的是指针域
//头指针在传参时，需要加取地址符

//指针在传参的时候，在函数调用时不加取地址符，在函数内部操作指针只会改变指针指向对象的值，不会改变指针的指向，相当于在函数内部创建了一个指针副本，
//在函数内部进行指针移动，原本的指针的指向并没有改变，只是指针副本发生改变，出了函数指针副本就销毁，
//如果想要修改指针的指向，传参是要传指针的地址，函数列表是一个二级指针


typedef struct LinkNode{
	int data;
	struct LinkNode* next;
}LinkNode;

//头节点(带头结点)
LinkNode* LinkInsert_shifan1()
{
	LinkNode* head=(LinkNode*)malloc(sizeof(LinkNode));
	head->next=NULL;
	
	LinkNode* newnode=(LinkNode*)malloc(sizeof(LinkNode));
	newnode->data=10;
	newnode->next=head->next;
	head->next=newnode;
	
	return head;
}
//头指针(不带头结点)
LinkNode* LinkInsert_shifan2()
{
	LinkNode* head=NULL;
	LinkNode* newnode=(LinkNode*)malloc(sizeof(LinkNode));
	newnode->data=10;
	newnode->next=head;
	head=newnode;
	return head;
}

//------------------------------------------------------------------//
//------------------------------------------------------------------//

void LinkInsert1(LinkNode* head,int a[],int n)
{
	for(int i=0;i<n;i++){
		LinkNode* newnode=(LinkNode*)malloc(sizeof(LinkNode));
		newnode->data=a[i];
		newnode->next=head->next;
		head->next=newnode;
	}
}

void LinkInsert2(LinkNode* head,int a[],int n)
{
	LinkNode* r=head;    //重点困惑点：尾节点指向的整个节点，不是节点的数据域也不是指针域
	for(int i=0;i<n;i++){
		LinkNode* newnode=(LinkNode*)malloc(sizeof(LinkNode));
		newnode->data=a[i];
		r->next=newnode;  //r是结构体指针
		r=newnode;        //重点困惑点：尾节点指向的整个节点，不是节点的数据域也不是指针域
	}
	r->next=NULL;
}


int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	LinkNode* head=(LinkNode*)malloc(sizeof(LinkNode));
	head->next=NULL;
	//头插法
	LinkInsert1(head,a,n);
	
	//尾插法
	LinkInsert2(head,a,n);
}