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

// @lc code=end
