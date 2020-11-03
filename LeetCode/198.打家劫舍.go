import "math"

/*
 * @lc app=leetcode.cn id=198 lang=golang
 *  DP：涉及到相邻两个取值互相影响，对于DP array可以增加一个维度，来记录关系
 * [198] 打家劫舍
 */

/**
 * dp[i][0,1]
 *  dim-0: 偷盗的 max value
 *  dim-1: 偷还是不偷
 * 状态转移：
 *   a[i][0] = max(a[i-1][0], a[i-1][1])
 *   a[i][1] = a[i-1][0] + nums[i]
 */
// @lc code=start
func rob(nums []int) int {
	if len(nums) < 1 {
		return 0
	}
	dp := make([][2]int, len(nums))

	// 初始化状态
	dp[0][0] = 0
	dp[0][1] = nums[0]

	for i := 1; i < len(nums); i++ {
		// 不偷i
		dp[i][0] = int(math.Max(float64(dp[i-1][0]), float64(dp[i-1][1])))
		// 偷i
		dp[i][1] = dp[i-1][0] + nums[i]
	}

	n := len(nums)
	return int(math.Max(float64(dp[n-1][0]), float64(dp[n-1][1])))
}

// @lc code=end

