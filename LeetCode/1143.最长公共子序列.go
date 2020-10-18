/*
 * @lc app=leetcode.cn id=1143 lang=golang
 *
 * [1143] 最长公共子序列

 * if s1[i] == s2[j]:
 *   LCS[i][j] = LCS[i-1][j-1] + 1;
 * else:
 *   LCS[i][j] = MAX(LCS[i][j-1], LCS[i-1][j]);
 */
package LeetCode

// @lc code=start
func longestCommonSubsequence(text1 string, text2 string) int {
	l1 := len(text1)
	l2 := len(text2)
	lcs := make([][]int, l1+1)
	for i, _ := range lcs {
		lcs[i] = make([]int, l2+1)
	}

	// lcs DP数组每个维度多一个长度可省去专门初始化首行首例
	for i := 1; i <= l1; i++ {
		for j := 1; j <= l2; j++ {
			if text1[i-1] == text2[j-1] {
				lcs[i][j] = lcs[i-1][j-1] + 1
			} else {
				if lcs[i-1][j] > lcs[i][j-1] {
					lcs[i][j] = lcs[i-1][j]
				} else {
					lcs[i][j] = lcs[i][j-1]
				}
			}
		}
	}
	return lcs[l1][l2]
}

// @lc code=end
