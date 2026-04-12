/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->next=NULL;
    struct ListNode* tail=head;  //尾指针
    int x,y;
    int carry=0;
    //"||"只要满足一个条件就可以进入循环
    while(l1!=NULL||l2!=NULL||carry!=0){ //如果最后l1和l2都为空了，但是还需要进位(carry!=0),就需要再  循环一次，把carry赋给最高位
        if(l1!=NULL)
            x=l1->val;
        else
            x=0;
        if(l2!=NULL)
            y=l2->val;
        else
            y=0;
        int sum=x+y+carry;
        int digit=sum%10;
        carry=sum/10;

        struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=digit;
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;

        if(l1!=NULL)
            l1=l1->next;
        if(l2!=NULL)
            l2=l2->next;
    }
    //释放头节点（头节点的数据域为空）
    struct ListNode* result=head->next;
    free(head);
    return result;
}