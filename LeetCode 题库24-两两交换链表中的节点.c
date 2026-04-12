/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next=head;
    //必须要创建一个指向两个节点前面的指针，因为交换了两个节点之后，必须要把交换后的第一个节点与前面的指针相连，否则链表就断了
    struct ListNode* prev=newhead;
    while(prev->next!=NULL&&prev->next->next!=NULL){
        struct ListNode* p1=prev->next;        //第一个节点
        struct ListNode* p2=prev->next->next;  //第二个节点
        p1->next=p2->next;
        p2->next=p1;
        prev->next=p2;   //重点：交换后的第一个节点连接到前驱指针上
        //移动prev到下一组交换节点的前面
        prev=p1;
    }
    return newhead->next;
}