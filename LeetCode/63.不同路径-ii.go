/*
 * @lc app=leetcode.cn id=63 lang=golang
 *
 * [63] 不同路径 II
 */

// @lc code=start
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	m := len(obstacleGrid)
	n := len(obstacleGrid[0])
	if m == 0 || n == 0 {
		return 0
	}

	opt := make([][]int, m)
	for i := 0; i < m; i++ {
		opt[i] = make([]int, n)
	}

	// 初始化end所在行列，并考虑 预设障碍物(==1)
	for i := m - 1; i >= 0 && obstacleGrid[i][n-1] == 0; i-- {
		opt[i][n-1] = 1
	}
	for i := n - 1; i >= 0 && obstacleGrid[m-1][i] == 0; i-- {
		opt[m-1][i] = 1
	}

	// opt[i][j] = opt[i][j-1] + opt[i-1][j]
	for i := m - 2; i >= 0; i-- {
		for j := n - 2; j >= 0; j-- {
			if obstacleGrid[i][j] == 0 {
				opt[i][j] = opt[i+1][j] + opt[i][j+1]
			}
		}
	}

	return opt[0][0]
}

// @lc code=end

