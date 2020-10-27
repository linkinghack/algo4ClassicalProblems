/*
 * @lc app=leetcode.cn id=120 lang=golang
 *
 * [120] 三角形最小路径和
 * 重复性：problem(i,j) = min( sub(i+1, j), sub(i+1, j+1) ) + a[i,j]
 * 定义状态数组: f[i, j]
 * DP方程: f[i, j] = min(f[i+1, j], f[i+1, j+1]) + a[i,j]
 */

// @lc code=start
func minimumTotal(triangle [][]int) int {
	if len(triangle) < 1 {
		return 0
	}

	dpStatus := triangle
	// 由底向上计算路径和
	for i := len(triangle) - 2; i > -1; i-- {
		// 每层从左向右计算
		for j := 0; j < len(triangle[i]); j++ {
			minSub := 0
			if triangle[i+1][j] > triangle[i+1][j+1] {
				minSub = triangle[i+1][j+1]
			} else {
				minSub = triangle[i+1][j]
			}
			dpStatus[i][j] = minSub + triangle[i][j]
		}
	}

	return dpStatus[0][0]
}

// @lc code=end

