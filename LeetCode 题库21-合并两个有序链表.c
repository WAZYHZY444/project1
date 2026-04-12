/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
//list1、list2是指向头节点的指针，不是节点
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //重新创建一个链表，用尾插法按序插入新链表
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->next=NULL;
    struct ListNode* tail=head;

    while(list1!=NULL&&list2!=NULL){
        if(list1->val<=list2->val){
            tail->next=list1;
            list1=list1->next;
        }
        else{
            tail->next=list2;
            list2=list2->next;
        }
        tail=tail->next;
        //不能tail=list1,// 不能写 tail = list1，因为 tail 是新链表的尾指针，一旦直接赋值，就会脱离新链表，不再是尾节点
    }

    //把剩余原链表节点直接接过来，不需要循环移动指针了
    if(list1!=NULL){
        tail->next=list1;
    }
    if(list2!=NULL){
        tail->next=list2;
    }
    return head->next;  //head是头节点，数据域为空
}