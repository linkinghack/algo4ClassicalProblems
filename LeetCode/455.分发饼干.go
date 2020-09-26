package LeetCode

import "sort"

/*
 * @lc app=leetcode.cn id=455 lang=golang
 *
 * [455] 分发饼干
 */

// @lc code=start
func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
	count := 0

	// greedy
	for i, j := 0, 0; i < len(g) && j < len(s); {
		if s[j] >= g[i] {
			count++
			j++
			i++
		} else {
			j++
		}
	}
	return count
}

// @lc code=end
