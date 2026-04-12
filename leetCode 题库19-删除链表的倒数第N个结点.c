/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* p=head;
    int len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    //删除第一个节点
    if(len-n==0){
        struct ListNode* newhead=head->next;
        free(head);
        return newhead;
    }
    struct ListNode* prev=head;
    p=prev->next;
    for(int i=0;i<len-n-1;i++){  //注意这里的i1的取值范围
        prev=p;
        p=p->next;
    }
    prev->next=p->next;
    free(p);
    return head;
}