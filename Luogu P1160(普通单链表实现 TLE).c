#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* createNode(int val)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}

//查找值为val的节点
Node* findNode(Node* head,int val)
{
	Node* temp=head;
	while(temp!=NULL&&temp->data!=val){
		temp=temp->next;
	}
	if(temp==NULL) return NULL;  //没找到
	return temp;
}

//查找值为val节点的前驱
Node* findPrev(Node* head,int val)
{
	if(head==NULL) return NULL;
	Node* prev=NULL;
	Node* cur=head;
	while(cur!=NULL&&cur->data!=val){
		prev=cur;
		cur=cur->next;
	}
	if(cur==NULL) return NULL;  //没找到
	return prev;
}

Node* Insert(int n,int a[][2])
{
	Node* head=createNode(1);
	head->next=NULL;
	for(int i=2;i<=n;i++){
		int k=a[i-2][0];
		int p=a[i-2][1];
		Node* newnode=createNode(i);
		Node* target=findNode(head,k);
		if(p==0){
			Node* prev=findPrev(head,k);
			//target是头节点
			if(prev==NULL){
				newnode->next=head;
				head=newnode;
			}else{
				newnode->next=target;
				prev->next=newnode;
			}
		}
		//p==1
		else{
			newnode->next=target->next;
			target->next=newnode;	
		}
	}
	return head;
}

//删除节点
void removeNode(Node** head,int val)
{
	if((*head)==NULL) return;
	//删除头节点
	if((*head)->data==val){
		Node* temp=*head;
		*head=(*head)->next;
		free(temp);
		return;
	}
	//删除非头结点
	Node* prev=*head;
	Node* cur=(*head)->next;
	while(cur!=NULL&&cur->data!=val){
		prev=cur;
		cur=cur->next;
	}
	if(cur==NULL) return; //没找到
	prev->next=cur->next;
	free(cur);
}

//打印链表
void print(Node* head)
{
	Node* cur=head;
	while(cur!=NULL){
		printf("%d ",cur->data);
		cur=cur->next;
	}
}

//销毁链表
void Destory(Node* head)
{
	Node* p;
	while(head!=NULL){
		p=head->next;
		free(head);
		head=p;
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	int a[N-1][2];
	for(int i=0;i<N-1;i++){
		scanf("%d %d",&a[i][0],&a[i][1]);
	}
	int M;
	scanf("%d",&M);
	//将N个人插入队列中
	Node* head=Insert(N,a);
	
	for(int i=0;i<M;i++){
		int num;
		scanf("%d",&num);
		removeNode(&head,num);
	}
	print(head);
	Destory(head);
	return 0;
}