/*
 * @lc app=leetcode.cn id=350 lang=golang
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
package main

import "sort"

func intersect(nums1 []int, nums2 []int) []int {
	sort.Ints(nums1)
	sort.Ints(nums2)

	len1 := len(nums1)
	len2 := len(nums2)
	result := []int{}
	if len1 == 0 || len2 == 0 {
		return result
	}

	if nums1[0] > nums2[len2-1] || nums1[len1-1] < nums2[0] {
		return result
	}

	i := 0
	j := 0
	for i < len1 && j < len2 {
		if nums1[i] == nums2[j] {
			result = append(result, nums1[i])
			i++
			j++
		} else if nums1[i] < nums2[j] {
			i++
		} else {
			j++
		}
	}

	return result
}

// @lc code=end
