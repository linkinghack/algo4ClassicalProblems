/*
 * @lc app=leetcode.cn id=1021 lang=golang
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
func removeOuterParentheses(S string) string {
	leftCount := 0
	result := []rune{}
	for _, c := range S {
		if c == '(' {
			if leftCount > 0 {
				result = append(result, c)
			}
			leftCount++
		} else {
			leftCount--
			if leftCount != 0 {
				result = append(result, c)
			}
		}
	}

	return string(result)
}

// @lc code=end

