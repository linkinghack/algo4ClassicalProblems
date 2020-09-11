/*
 * @lc app=leetcode.cn id=637 lang=golang
 *
 * [637] 二叉树的层平均值
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
func averageOfLevels(root *TreeNode) []float64 {
	if root == nil {
		return []float64{}
	}
	result := []float64{}
	queue := []*TreeNode{}
	queue = append(queue, root)
	level := 0
	for len(queue) > 0 {
		nextLevelQueue := []*TreeNode{}
		for _, node := range queue {
			if len(result) <= level {
				result = append(result, 0)
			}
			result[level] += float64(node.Val)
			if node.Left != nil {
				nextLevelQueue = append(nextLevelQueue, node.Left)
			}
			if node.Right != nil {
				nextLevelQueue = append(nextLevelQueue, node.Right)
			}
		}
		result[level] /= float64(len(queue))

		queue = nextLevelQueue
		level++
	}
	return result
}

// @lc code=end

