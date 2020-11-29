/*
 * @lc app=leetcode.cn id=122 lang=golang
 *
 * [122] 买卖股票的最佳时机 II (任意多笔交易)
 */
package LeetCode

// @lc code=start
// 股票交易，按天收益
// 在已知所有历史的情况下，历史中的每一天都可以单独计算收益
// 即前一天买入，后一天卖出的方式。
// 在这种情况下最大化收益，精确的决定每一天是否买入明天的股票就可以
//  和长期持有效果一样(可以贪心策略解决).
//   即 长期持有的最大化收益，就是每次收益的单位时间的收益和
func maxProfit(prices []int) int {
	profit := 0
	for i, v := range prices {
		if i > 0 && prices[i-1] < v {
			profit += v - prices[i-1]
		}
	}
	return profit
}

// @lc code=end
