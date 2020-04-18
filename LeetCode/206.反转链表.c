/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 * 使用相邻的两指针持续反转同步移动
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL, *curr = head;
    while (curr)
    {
        // 先留下截断点
        struct ListNode *next_cur = curr->next;
        curr->next = prev; // 当前节点转向
        // 移动操作指针
        prev = curr;
        curr = next_cur;
    }
    return prev;
}


// @lc code=end

