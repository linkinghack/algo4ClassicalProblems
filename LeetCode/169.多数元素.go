/*
 * @lc app=leetcode.cn id=169 lang=golang
 *
 * [169] 多数元素
 */

// @lc code=start
func majorityElement(nums []int) int {
	// 选择候选目标
	candidate := nums[0]
	// 得票数
	votes := 0

	for _, v := range nums {
		if candidate == v {
			votes++
		} else {
			votes--

			if votes == 0 {

				// 连续不得票到0，更换候选
				// 这里直接使candidate = v是可行的，因为多数元素一定可以获得最终选举
				// 1,1,2,2,1； 巧妙在于刚失去最后一票就要立即换掉
				candidate = v
				votes = 1
			}
		}
	}

	return candidate
}

// 方法2， 直接排序，中间位置的一定为多数元素
// func majorityElement(nums []int) int {
// sort.Ints(nums)
// return nums[len(nums) / 2]
// }

// @lc code=end

