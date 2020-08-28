/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *prev = NULL, *curr, *next, new_head;
    new_head.next = head;
    prev = &new_head;
    while(prev->next && prev->next-> next)
    {
        struct ListNode *a = prev->next, *b = prev->next->next;
        prev->next = b;
        a->next = b->next;
        b->next = a;
        prev = a;
    }

    return new_head.next;
}


// @lc code=end

