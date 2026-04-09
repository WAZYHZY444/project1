#include <stdio.h>
#include <stdlib.h>

//双向链表
typedef struct Node{
	int data;
	struct Node* next;  //后继指针
	struct Node* prev;  //前驱指针
}Node;

//创建头节点
Node* CreateHead()
{
	Node* head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
	head->prev=NULL;
	return head;
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
void append(Node* head,int val)
{
	Node* newnode=CreateNode(val);
	Node* tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	tail->next=newnode;
	newnode->prev=tail;	
}

//头部插入
void prepend(Node* head,int val)
{	
	Node* newnode=CreateNode(val);
	newnode->next=head->next;
	if(head->next!=NULL){  //头结点的后继节点不为NULL
		head->next->prev=newnode;
	}
	//可以发现：其实这一部分的代码和尾部插入逻辑一样，只是需要考虑的是如果头节点有后继节点，需要让新节点指向这个后继节点的前驱指针
	head->next=newnode;
	newnode->prev=head;
}

//在第pos个位置插入(pos从0开始)
void InsertByLocation(Node* head,int pos,int val)
{
	Node* temp=head;
	for(int i=0;temp!=NULL&&i<pos;i++){
		temp=temp->next;
	}
	if(temp==NULL) return;  //链表创建失败，注意有pos指定插入位置，所以插入位置不会是头部
	Node* newnode=CreateNode(val);
	//注意；这里的指针修改和头部插入差不多，但是顺序不同，要去理解为什么
	newnode->next=temp->next;
	newnode->prev=temp;   //因为当前temp指向的是i=pos-1位置的节点，newnode要插入temp的后面，所以要先让temp指针赋给newnode的前驱指针，让newnode的前驱指针指向它的前驱节点
	if(temp->next!=NULL){
		temp->next->prev=newnode;  //此时的temp指向的后继节点的前驱指针需要指newnode节点
	}
	temp->next=newnode;
}

//删除值为val的节点
void DeleteByVal(Node* head,int val)
{
	Node* temp=head->next;   //头节点的数据域为空，所以不考虑头节点
	while(temp!=NULL&&temp->data!=val){
		temp=temp->next;
	}
	if(temp==NULL) return;
	temp->prev->next=temp->next;  //删除节点，让temp的后继节点连接到temp前驱节点（temp前驱节点的后继指针指向temp的后继节点）
	if(temp->next!=NULL){
		temp->next->prev=temp->prev;  //如果删除的不是最后一个节点，temp的前驱节点连接到temp后继节点（temp后继节点的前驱指针指向temp的前驱节点）
	}
	free(temp);
}

//删除第pos个节点
void DeleteByLocation(Node* head,int pos)
{
	Node* temp=head->next;   //头节点的数据域为空，所以不考虑头节点
	for(int i=0;temp!=NULL&&i<pos;i++){
		temp=temp->next;
	}
	if(temp==NULL) return;
	temp->prev->next=temp->next;  //删除节点，让temp的后继节点连接到temp前驱节点（temp前驱节点的后继指针指向temp的后继节点）
	if(temp->next!=NULL){
		temp->next->prev=temp->prev;  //如果删除的不是最后一个节点，temp的前驱节点连接到temp后继节点（temp后继节点的前驱指针指向temp的前驱节点）
	}
	free(temp);
}

int Find(Node* head,int val)
{
	int pos=0;
	Node* temp=head->next;
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
void printForward(Node* head)
{
	Node* temp=head->next;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

//反向遍历
void printBackward(Node* head)
{
	if(head->next==NULL) return;
	Node* temp=head->next;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	while(temp!=head){
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}

//销毁链表
void Destory(Node** head)
{
	Node* temp=*head;
	while(temp!=NULL){
		Node* Next=temp->next;
		free(temp);
		temp=Next;
	}
	*head=NULL;
}

int main()
{
	Node* head=CreateHead();
	
	append(head, 10);
    append(head, 20);
    append(head, 30);
    prepend(head, 5);
    InsertByLocation(head, 2, 15);

    printForward(head);   // 5 10 15 20 30
    printBackward(head);  // 30 20 15 10 5

    DeleteByVal(head, 15);
    printForward(head);   // 5 10 20 30

    DeleteByLocation(head, 1);
    printForward(head);   // 5 20 30

    printf("Find 20: %d\n", Find(head, 20)); // 1
    printf("Find 99: %d\n", Find(head, 99)); // 0

	
	Destory(&head);
	return 0;
}