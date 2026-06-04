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

Node* createList(int n)
{
	if(n<=0) return NULL;
	Node* head=createNode(1);
	Node* prev=head;
	for(int i=2;i<=n;i++){
		Node* cur=createNode(i);
		prev->next=cur;
		prev=cur;
	}
	prev->next=head;
	return head;
}

void showTheEnd(int n,int m){
	if(n<=0&&m<=0) return;
	Node* head=createList(n);
	Node* prev=NULL;
	Node* cur=head;
	while(n>0){
		for(int i=1;i<m;i++){
			prev=cur;
			cur=cur->next;
		}
		Node* p=cur;
		//剩下最后一个
		if(cur->next==cur){
			printf("%d\n",cur->data);
			free(p);
			break;
		}
		prev->next=cur->next;
		cur=cur->next;
		free(p);
		//外层循环条件
		n--;
	}
}

int main()
{
	int a[100][2];
	int count=0;
	while(1){
		scanf("%d %d",&a[count][0],&a[count][1]);
		if(a[count][0]==0&&a[count][1]==0){
			break;
		}
		count++;
	}
	for(int i=0;i<count;i++){
		showTheEnd(a[i][0],a[i][1]);
	}
	return 0;
}