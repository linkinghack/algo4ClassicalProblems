#include <iostream>

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int d):data(d),next(nullptr) {}
};

// 反转链表的前 k 个结点，返回反转后的链表的头指针
ListNode* Reverse(ListNode* head, int k){
    // 假设传入的链表包含头节点
    ListNode* newp = head->next;
    ListNode* oldp = head->next->next;
    // newp可代表已经完成逆序的最后一个结点，既逆序后的第一个结点
    // olp 可代表未完成逆序部分的第一个结点
    while(k>0){
        ListNode* tmp = oldp->next;
        oldp->next = newp; // 反向链接
        newp = oldp;  oldp = tmp;

        k--;
    }

    head->next->next = oldp; // 将原来的头指向未反转部分的第一个结点
    return newp;
}