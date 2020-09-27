import "sort"

/*
 * @lc app=leetcode.cn id=18 lang=golang
 *
 * [18] 四数之和
 */
package LeetCode


// @lc code=start
func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	return kSum(nums, target, 0, 4)
}

func kSum(nums []int, target, start, k int) [][]int {
	result := [][]int{}
	// 判断极端不可能边界
	if start == len(nums) || nums[start]*k > target || target > nums[len(nums)-1]*k {
		return result
	}

	// 最终问题都归结为求2sum问题
	if k == 2 {
		return twoSum(nums, target, start)
	}

	for i := start; i < len(nums)-1; i++ {
		if i == start || nums[i-1] != nums[i] {
			// 递归的解决 k-1 sum 问题
			for _, res := range kSum(nums, target-nums[i], i+1, k-1) {
				result = append(result, append([]int{nums[i]}, res...))
			}

		}
	}
	return result
}

func twoSum(nums []int, target, start int) [][]int {
	result := [][]int{}
	l, r := start, len(nums)-1
	for l < r {
		sum := nums[l] + nums[r]
		if sum < target || (l > start && nums[l] == nums[l-1]) {
			l++
		} else if sum > target || (r < len(nums)-1 && nums[r] == nums[r+1]) {
			r--
		} else {
			result = append(result, []int{nums[l], nums[r]})
			l++
			r--
		}
	}
	return result
}

// @lc code=end

