#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct polynomial
{
    int coefficient;//系数
    //int exp;//指数
    struct polynomial *next;
}LinkNode;


//打印链表
void printList(LinkNode* head,int n)
{

	LinkNode* p=head->next; //因为头节点的数据域为空，所以跳过头节点，遍历不经过头节点
	bool first=true;  //标记是否是第一项
	while(p!=NULL)
    {
        //只处理系数不为0的项
        if(p->coefficient!=0)
        {
            //处理符号
            if(!first)
            {
                if(p->coefficient>0)
                    printf("+");
            }
            
            //打印系数和指数
            if(n==0) //常数项
            {
                printf("%d",p->coefficient);
            }
            else // 非常数项
            {
                if(p->coefficient==1)
                {
                    printf("x^%d",n);
                }
                else if(p->coefficient==-1)
                {
                    printf("-x^%d",n);
                }
                else
                {
                    printf("%dx^%d",p->coefficient,n);
                }
            }
            first=false;
        }
		p=p->next;
		n--;	
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
	int n,num;
	scanf("%d",&n);
//创建头节点
//head指向头节点，p指向新节点，r指向尾节点(辅助指针变量)
	LinkNode *head,*p,*r;//结构体指针变量，LinkNode是普通变量别名
	head=(LinkNode*)malloc(sizeof(LinkNode));  //创建头节点，分配内存，malloc返回的是地址，需要强制类型转换
	head->next=NULL;  //访问头节点指针域
	r=head;  // 创建头节点后，需要初始化 r(重要，不可忽略)

	for(int i=0;i<=n;i++){
		scanf("%d",&num);
//创建新节点
	p=(LinkNode*)malloc(sizeof(LinkNode));
	p->coefficient=num;
	p->next=NULL;//用尾插法，新插入的节点始终是尾节点，尾节点的指针域始终为NULL
//r指针指向尾节点
	r->next=p;
//更新尾部指针指向
	r=p;
	}


	printList(head,n);
	destroyList(head);
	return 0;
}
//在前面的for循环结束后，r,p,num等的作用释放出来，所以可以不需要重定义新的变量