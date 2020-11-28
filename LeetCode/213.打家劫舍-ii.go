import "math"

/*
 * @lc app=leetcode.cn id=213 lang=golang
 *
 * [213] 打家劫舍 II
 * 和I的区别在于多了环形房屋
 * 可以分成两部分解决：
 * 抢头不抢尾，抢尾不抢头
 *   剩余问题解决方式同I
 */

// @lc code=start
func rob(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}
	solution1 := naiveRob(nums[1:])
	solution2 := naiveRob(nums[0 : len(nums)-1])
	if solution1 > solution2 {
		return solution1
	} else {
		return solution2
	}
}

func naiveRob(nums []int) int {
	prev, now := 0, 0
	for _, v := range nums {
		// prev: a[i-2], now: a[i-1]
		prev, now = now, int(math.Max(float64(prev+v), float64(now)))
	}
	return now
}

// @lc code=end

