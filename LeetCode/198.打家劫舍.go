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
 * 状态转移：每层状态都要计算偷和不偷两种情况的结果
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

/**
 * 方法2 不使用而为数组来记录状态
 * a[i]  : 0..i 能偷到的最大值, 第i个房子可偷可不偷
 * DP方程
 * a[i] = max( a[i-1] + 0,  nums[i] + a[i-2], nums[i] + a[i-3]... )
 *            决定偷i-1  ,  i-1不偷,状态从i-2转换过来, ...
 *  nums[i] + a[i-3]... 的状态已经包含在a[i-2]中了, 所以：
 * a[i] = max( a[i-1] , nums[i] + a[i-2])
 *
 * 又因为，每次只需要记录两个状态, a[i-1] , a[i-2]
 * 所有不需要一个dp数组，只需要两个变量
 */
func robMethod2(nums []int) int {
	prev, now := 0, 0
	for _, v := range nums {
		// prev: a[i-2], now: a[i-1]
		prev, now = now, math.Max(float64(prev+v), now)
	}
	return now
}

// @lc code=end

