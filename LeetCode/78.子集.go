/*
 * @lc app=leetcode.cn id=78 lang=golang
 *
 * [78] 子集
 */
package LeetCode

// @lc code=start
func subsets(nums []int) [][]int {
	result := [][]int{}
	subset := []int{}

	var dfs func(idx int)

	dfs = func(idx int) {
		// 所有节点都已确定(不管是选还是不选)
		if idx == len(nums) {
			result = append(result, append([]int{}, subset...))
			return
		}

		// 选择当前节点
		subset = append(subset, nums[idx])
		dfs(idx + 1)
		subset = subset[:len(subset)-1]
		// 不选当前节点
		dfs(idx + 1)
	}
	dfs(0)
	return result
}

// @lc code=end
