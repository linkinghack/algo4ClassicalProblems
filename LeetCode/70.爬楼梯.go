/*
 * @lc app=leetcode.cn id=70 lang=golang
 *
 * [70] 爬楼梯
 */

// @lc code=start
func climbStairs(n int) int {
	p := 0
	q := 0
	steps := 1
	for i := 0; i < n; i++ {
		q = p
		p = steps
		steps = p + q
	}
	return steps
}

// @lc code=end

