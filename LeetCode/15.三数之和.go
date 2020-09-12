import "sort"

/*
 * @lc app=leetcode.cn id=15 lang=golang
 *
 * [15] 三数之和
 */

// @lc code=start
func threeSum(nums []int) [][]int {
	result := [][]int{}
	if len(nums) < 1 {
		return result
	}
	sort.Ints(nums)

	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		p1 := i + 1
		p2 := len(nums) - 1
		for p1 < p2 {
			if nums[i]+nums[p1]+nums[p2] == 0 {
				result = append(result, []int{nums[i], nums[p1], nums[p2]})
				// 注意在循环中对循环判断变量做修改，要首先满足循环条件
				for p1 < p2 && nums[p1+1] == nums[p1] {
					p1++
				}
				for p1 < p2 && nums[p2-1] == nums[p2] {
					p2--
				}
				p1++
				p2--
			} else if nums[p1]+nums[p2] < -nums[i] {
				p1++
			} else {
				p2--
			}

		}
	}
	return result
}

// @lc code=end

