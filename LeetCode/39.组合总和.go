import "sort"

/*
 * @lc app=leetcode.cn id=39 lang=golang
 *
 * [39] 组合总和
 */

// @lc code=start
func combinationSum(candidates []int, target int) [][]int {
	result := [][]int{}
	comb := []int{}
	sort.Ints(candidates)

	var dfs func(target int, idx int)
	dfs = func(target int, idx int) {
		if target < 0 || idx >= len(candidates) {
			// 当前状态子树未找到匹配结果
			return
		}

		if target == 0 {
			// create new array to store comb
			result = append(result, append([]int{}, comb...))
		}

		// 提前停止搜索状态子树条件；剪枝
		if target-candidates[idx] < 0 {
			return
		}

		// 继续搜索状态子树(仅两种状态,选或不选当前节点)
		// 1. 不选当前节点
		dfs(target, idx+1)
		// 2. 选当前节点
		comb = append(comb, candidates[idx])
		dfs(target-candidates[idx], idx)
		comb = comb[:len(comb)-1] // 恢复状态
	}

	dfs(target, 0)
	return result
}

// @lc code=end

