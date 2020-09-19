/*
 * @lc app=leetcode.cn id=404 lang=golang
 *
 * [404] 左叶子之和
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
func sumOfLeftLeaves(root *TreeNode) int {
	return dfs(root)
}

func dfs(root *TreeNode) int {
	if root == nil {
		return 0
	}

	sum := 0

	// 递归搜素左子树
	if root.Left != nil && isLeaf(root.Left) {
		sum += root.Left.Val
	} else {
		sum += dfs(root.Left)
	}

	if root.Right != nil && !isLeaf(root.Right) {
		sum += dfs(root.Right)
	}

	return sum
}

func isLeaf(node *TreeNode) bool {
	if node != nil && node.Left == nil && node.Right == nil {
		return true
	}
	return false
}

// @lc code=end

