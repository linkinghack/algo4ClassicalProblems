/*
 * @lc app=leetcode.cn id=322 lang=golang
 *
 * [322] 零钱兑换
 */
package LeetCode

import "math"

// @lc code=start
func coinChange(coins []int, amount int) int {
	coinsCount := make([]int, amount+1) // 保存1~amount分别需要使用的硬币数
	coinsCount[0] = 0
	// for i := 1; i <= amount; i++ {
	// 	coinsCount[i] = amount + 1
	// }

	for i := 1; i <= amount; i++ {
		coinsCount[i] = amount + 1
		for _, coin := range coins {
			if coin <= i {
				// 上一个金额的硬币数量+1
				coinsCount[i] = int(math.Min(float64(coinsCount[i]), float64(coinsCount[i-coin]+1)))
			}
		}
	}

	// 处理结果
	if coinsCount[amount] > amount {
		return -1
	} else {
		return coinsCount[amount]
	}
}

// @lc code=end
