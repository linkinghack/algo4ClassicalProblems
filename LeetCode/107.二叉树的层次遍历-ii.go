import "container/list"

/*
 * @lc app=leetcode.cn id=107 lang=golang
 *
 * [107] 二叉树的层次遍历 II
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
func levelOrderBottom(root *TreeNode) [][]int {
	result := [][]int{}
	if root == nil {
		return result
	}

	queue := list.New()
	queue.PushBack(root)
	for queue.Len() > 0 {
		level := []int{}
		currentLayerLength := queue.Len()
		for i := 0; i < currentLayerLength; i++ {
			top := queue.Front()
			queue.Remove(top)
			node := top.Value.(*TreeNode)
			level = append(level, node.Val)
			if node.Left != nil {
				queue.PushBack(node.Left)
			}
			if node.Right != nil {
				queue.PushBack(node.Right)
			}
		}
		// prepend。 从根开始的层序使用append
		result = append([][]int{level}, result...)
	}
	return result
}

// @lc code=end

