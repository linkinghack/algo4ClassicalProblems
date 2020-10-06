/*
 * @lc app=leetcode.cn id=62 lang=golang
 *
 * [62] 不同路径

 * DP 推导递推方程，自底向上的解决问题。
 */

// @lc code=start

// 方法一: 记录整个grid
/* func uniquePaths(m int, n int) int {
	grid := make([][]int, m)
	// 初始化与finish所在的列和行
	for i := m - 1; i >= 0; i-- {
		grid[i] = make([]int, n)
		grid[i][n-1] = 1
	}
	for i := n - 1; i >= 0; i-- {
		grid[m-1][i] = 1
	}

	for i := m-1; i > 0; i-- {
		for j := n-1; j>0; j-- {
			grid[i-1][j-1] = grid[i][j-1] + grid[i-1][j]
		}
	}

	return grid[0][0]
} */

// 方法二：只记录一行状态
//  从行的角度看每个单元格, 结果总是同列前一行状态+本行前一列状态
//   本行前一列 不需要一个单独的数组来记录
func uniquePaths(m int, n int) int {
	row := make([]int, n)
	// 初始化finish所在行
	for i, _ := range row {
		row[i] = 1
	}

	for i := m - 1; i > 0; i-- {
		// 每一行状态都可在前一行状态基础上得来
		// row[len - 1] 永远为1
		for j := n - 1; j > 0; j-- {
			row[j-1] += row[j]
		}
	}
	return row[0]
}

// @lc code=end

