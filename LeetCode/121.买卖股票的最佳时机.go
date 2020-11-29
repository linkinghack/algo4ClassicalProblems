import "math"

/*
 * @lc app=leetcode.cn id=121 lang=golang
 *
 * [121] 买卖股票的最佳时机 (仅允许交易一次)
 */

// @lc code=start
// Kadane's Algorithm
func maxProfit(prices []int) int {
	profit := 0
	maxProfit := 0
	for i := 1; i < len(prices); i++ {
		// 仅一次购买
		// 扫描过程中要有清零
		profit = int(math.Max(float64(profit+prices[i]-prices[i-1]), 0))
		if profit > maxProfit {
			maxProfit = profit
		}
	}
	return maxProfit
}

// @lc code=end

