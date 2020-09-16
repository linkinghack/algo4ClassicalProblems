/*
 * @lc app=leetcode.cn id=226 lang=golang
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func invertTree(root *TreeNode) *TreeNode {
	nodeQueue := []*TreeNode{}
	if root == nil {
		return root
	}

	nodeQueue = append(nodeQueue, root)
	for len(nodeQueue) > 0 {
		// pop out
		top := nodeQueue[0]
		nodeQueue = nodeQueue[1:len(nodeQueue)]

		// reverse
		var tempPointer *TreeNode
		tempPointer = top.Left
		top.Left = top.Right
		top.Right = tempPointer

		// push
		if top.Left != nil {
			nodeQueue = append(nodeQueue, top.Left)
		}
		if top.Right != nil {
			nodeQueue = append(nodeQueue, top.Right)
		}
	}
	return root
}

// @lc code=end

