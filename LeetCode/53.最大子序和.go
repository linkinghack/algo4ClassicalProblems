/*
 * @lc app=leetcode.cn id=53 lang=golang
 *
 * [53] 最大子序和
 */
package LeetCode

// @lc code=start
func maxSubArray(nums []int) int {
	prevSubSum := 0
	maxSum := nums[0]

	// maxSub(i) = max(maxSub(i-1), nums[i])
	for _, v := range nums {
		// 连续子序列和
		if v > prevSubSum+v {
			prevSubSum = v
		} else {
			prevSubSum += v
		}

		if prevSubSum > maxSum {
			maxSum = prevSubSum
		}
	}
	return maxSum
}

/**
 * DP
 * 连续子数组最大和, 对于每个元素, 前面子数组的和小于当前值则遗忘。
 *  即 最大子序和 = 当前元素自身最大  或  包含之前的和最大
 * 子问题(分治): max_sum(i) = Max( max_sum(i-1), 0 ) + a[i]
 * 状态数组定义: f[i]
 * DP方程： f[i] = Max(f[i-1], 0) + a[i]
 */
func solveWithDPStatusArray(nums []int) {
	if len(nums) < 2 {
		return nums[0]
	}

	dpStatus := nums
	maxIdx := 0
	for i := 1; i < len(nums); i++ {

		// dp[i] = max( nums[i] + 0, nums[i] + dp[i-1] )
		//     = nums[i] + max(0, dp[i-1])
		max := 0
		if dpStatus[i-1] > 0 {
			max = dpStatus[i-1]
		}

		dpStatus[i] = max + nums[i]

		if dpStatus[i] > dpStatus[maxIdx] {
			maxIdx = i
		}
	}

	return dpStatus[maxIdx]
}

// @lc code=end
