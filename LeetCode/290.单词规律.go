import "strings"

/*
 * @lc app=leetcode.cn id=290 lang=golang
 *
 * [290] 单词规律
 */

// @lc code=start
func wordPattern(pattern string, str string) bool {
	// 由于最开始不同的两个格式字符串需要和不同的目标字符串绑定
	// 若只记录单向的map，容易出现 a -> dog,  紧接着 b -> dog的情况
	ptnMap := make(map[string]string) // pattern -> str
	strMap := make(map[string]string) // str -> pattern

	subStrs := strings.Split(str, " ")

	// 前置判断
	if len(pattern) != len(subStrs) {
		return false // 长度比匹配
	}

	for idx, _ := range pattern {
		ptnSubStr := pattern[idx : idx+1] // 读取当前规律字符
		if ptnMap[ptnSubStr] == "" && strMap[subStrs[idx]] == "" {
			ptnMap[ptnSubStr] = subStrs[idx]
			strMap[subStrs[idx]] = ptnSubStr
		} else { // 至少 pattern 出现过，或str出现过
			// 出现过的记录必须匹配
			if ptnMap[ptnSubStr] != subStrs[idx] {
				return false
			}
		}
	}

	return true
}

// @lc code=end
