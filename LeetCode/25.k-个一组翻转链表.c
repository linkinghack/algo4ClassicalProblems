/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// #include<stdio.h>
// #include<stdlib.h>
//  struct ListNode {
//      int val;
//      struct ListNode *next;
//  };


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    // 处理边界
    if (!head || !head->next || k <= 1)
    {
        return head;
    }

    // 构造临时头节点
    struct ListNode temp_head={0, NULL}, *block_head = &temp_head;
    block_head->next = head;

    while (1)
    {
        // next 指向反转区域的最后一个节点
        struct ListNode *next = block_head;
        
        // 找出反转区域
        int nodes = 0;
        while(next && nodes < k){
            nodes++;
            next = next->next;
        }
        if (nodes < k || !next)
        {
            break; // 剩余节点不够k个
        }

        // 保留工作区域下一个节点记录
        struct ListNode *block_next = next->next;
        
        // 反转
        struct ListNode *prev = NULL, *curr=block_head->next, *tail = block_head->next;
        while (curr && nodes-- > 0)
        {
            struct ListNode *tail_cut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tail_cut;
        }
        
        // 拼接
        block_head->next = prev;
        tail->next = block_next;

        // 移动工作区域
        block_head = tail;
    }
    
    return temp_head.next;
}

// int main(void)
// {
//     struct ListNode list, *iter = &list;
//     for(int i = 1; i<=5; i++) {
//         struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
//         node -> val = i;
//         node -> next = NULL;
//         iter->next = node;
//         iter = node;
//     }
//     struct ListNode *reversed = reverseKGroup(list.next, 2);
//     while (reversed)
//     {
//         printf("%d,",reversed->val);
//         reversed=reversed->next;
//     }
//     return 0;
// }
// @lc code=end

