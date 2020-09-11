/*
 * @lc app=leetcode.cn id=216 lang=golang
 *
 * [216] 组合总和 III
 */

// @lc code=start
func combinationSum3(k int, n int) [][]int {
	result := [][]int{}
	comb := []int{}
	var dfs func(start int, target int)
	dfs = func(start int, target int) {
		if target == 0 && len(comb) == k {
			result = append(result, append([]int{}, comb...))
			return
		}

		// 跳过和无法满足的情况
		if target-start < 0 {
			return
		}

		// 跳过剩余数字不足的情况
		if len(comb)+(9-start+1) < k {
			return
		}

		// 不选当前数字
		dfs(start+1, target)

		// 选当前数字
		comb = append(comb, start)
		dfs(start+1, target-start)
		comb = comb[:len(comb)-1]
	}
	dfs(1, n)
	return result
}

// @lc code=end

