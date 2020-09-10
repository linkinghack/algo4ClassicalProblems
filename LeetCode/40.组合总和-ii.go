import "sort"

/*
 * @lc app=leetcode.cn id=40 lang=golang
 *
 * [40] 组合总和 II
 */

// @lc code=start
func combinationSum2(candidates []int, target int) [][]int {
	result := [][]int{}
	comb := []int{}
	sort.Ints(candidates)

	var dfs func(target int, start int)
	dfs = func(target int, start int) {
		if target == 0 {
			// create new array to store comb
			result = append(result, append([]int{}, comb...))
			return
		}

		for i := start; i < len(candidates); i++ {
			// 提前停止搜索状态子树条件；剪枝
			if target-candidates[i] < 0 {
				break
			}

			if i > start && candidates[i] == candidates[i-1] {
				// 状态树同一层数值相同会导致重复结果
				continue
			}

			comb = append(comb, candidates[i])
			dfs(target-candidates[i], i+1)
			comb = comb[:len(comb)-1] // 恢复状态
		}

	}

	dfs(target, 0)
	return result
}

// @lc code=end

