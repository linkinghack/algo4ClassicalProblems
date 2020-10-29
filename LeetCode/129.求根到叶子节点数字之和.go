/*
 * @lc app=leetcode.cn id=129 lang=golang
 *
 * [129] 求根到叶子节点数字之和
 */
package LeetCode

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumNumbers(root *TreeNode) int {
	sum := 0

	var trace func(root *TreeNode, num int)
	trace = func(root *TreeNode, num int) {
		if root == nil {
			return
		}

		if root.Left == nil && root.Right == nil {
			num = num*10 + root.Val
			sum += num
			return
		}

		trace(root.Left, num*10+root.Val)
		trace(root.Right, num*10+root.Val)
	}

	trace(root, 0)
	return sum
}

// @lc code=end
