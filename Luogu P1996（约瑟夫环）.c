#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

//创建新节点
Node* CreateNode(int val)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}

//创建单循环链表
Node* CreateList(int n)
{
	if(n<=0) return NULL;
	
	//创建头节点
	Node* head=CreateNode(1);
	Node* prev=head;
	for(int i=2;i<=n;i++){
		Node* cur=CreateNode(i);
		prev->next=cur;  //prev是cur的前驱节点
		prev=cur;        //让前驱节点指向当前节点，更新下一个新节点
	}
	prev->next=head;      //形成环
	return head;
}

//约瑟夫环求解
Node* Show(int n,int m)
{
	if(n<=0||m<=0) return NULL;
	
	Node* head=CreateList(n);
	Node* prev=NULL;
	Node* cur=head;
	while(n>0){
		//向后移动m-1步
		for(int i=1;i<m;i++){
			prev=cur;
			cur=cur->next;
		}
		//输出要删除的节点（此时cur指向的就是数到m的编号）
		printf("%d ",cur->data);
		
		Node* p=cur;
		//如果此时只剩下一个节点
		if(cur->next==cur){
			free(p);
			break;
		}
		//剩下不止一个节点
		prev->next=cur->next;
		cur=cur->next;
		free(p);
		
		n--;
	}
	printf("\n");
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	Show(n,m);
	return 0;
}