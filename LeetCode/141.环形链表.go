/*
 * @lc app=leetcode.cn id=141 lang=golang
 *
 * [141] 环形链表
 */
package LeetCode

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func hasCycle(head *ListNode) bool {
	if head == nil {
		return false
	}
	fp := head.Next
	sp := head
	for fp != sp && fp != nil && sp != nil {
		if fp.Next != nil {
			fp = fp.Next.Next
		} else {
			return false
		}
		sp = sp.Next
	}
	if fp == nil || sp == nil {
		return false
	}
	return true
}

// @lc code=end
