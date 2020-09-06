import "container/list"

/*
 * @lc app=leetcode.cn id=94 lang=golang
 *
 * [94] 二叉树的中序遍历
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

func inorderTraversal(root *TreeNode) []int {
	var result []int
	// traversal(root, &result)
	traversalWithStack(root, &result)
	return result
}

func traversal(root *TreeNode, result *[]int) {
	if root != nil {
		traversal(root.Left, result)
		*result = append(*result, root.Val)
		traversal(root.Right, result)
	}
}

func traversalWithStack(root *TreeNode, result *[]int) {
	stack := list.New()
	var curr *TreeNode = root

	for curr != nil || stack.Len() > 0 {
		// 中序遍历，每个节点都先遍历左子树
		// 当前节点入栈，先访问左子树
		// 入栈顺序保证了弹出访问是中序遍历
		for curr != nil {
			stack.PushBack(curr)
			curr = curr.Left
		}
		top := stack.Back()
		stack.Remove(top)
		curr = top.Value.(*TreeNode)
		*result = append(*result, curr.Val) // 访问节点
		curr = curr.Right
	}
}

// @lc code=end

