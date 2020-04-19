/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // 快慢指针
    // 快指针一次走两步，满指针一次走一步
    // 若有环一定相撞
    struct ListNode *fast = head, *slow = head;
    while (slow && fast && fast->next) { // 快指针要走两步，保证next不为NULL才不会NPE
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}
// @lc code=end

