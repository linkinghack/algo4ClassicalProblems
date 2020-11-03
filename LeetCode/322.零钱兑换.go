/*
 * @lc app=leetcode.cn id=322 lang=golang
 *
 * [322] 零钱兑换
 * 1. 暴力搜索状态树. 11 - {1, 2, 5}... 指数时间复杂度
 * 2. BFS 搜索状态树
 * 3. DP
 */
package LeetCode

import "math"

/**
 * DP:
 *  subproblem:
 *  状态转移方程: f(n) = min{f(n-k), for k in [1, 2, 5]} + 1 // 加本次决定的一枚硬币
 *	  f(n) 表示凑到需要的最小硬币数。 f(n-1), f(n-2), f(n-5) 中的最小者
 *
 *
 */
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
