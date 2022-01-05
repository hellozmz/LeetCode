/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.25%)
 * Likes:    1680
 * Dislikes: 0
 * Total Accepted:    172.9K
 * Total Submissions: 611.8K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 示例 1：
 *
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 *
 * 示例 2：
 *
 * 输入: "cbbd"
 * 输出: "bb"
 *
 *
 */

// @lc code=start
func longestPalindrome(s string) string {
	r_start := 0
	r_len := 0
	end := len(s)
	dp := make([][]int, end)
	for i := 0; i < end; i++ {
		dp[i] = make([]int, end)
	}
	for l := 0; l < end; l++ {
		for start := 0; start+l < end; start++ {
			t_end := start + l
			if l == 0 {
				dp[start][t_end] = 1
			} else if l == 1 {
				if s[start] == s[t_end] {
					dp[start][t_end] = 1
				}
			} else {
				if s[start] == s[t_end] {
					dp[start][t_end] = dp[start+1][t_end-1]
				}
			}
			if dp[start][t_end] == 1 && l > r_len {
				r_start = start
				r_len = l
			}
		}
	}
	return s[r_start : r_start+r_len+1]
}

// @lc code=end

func longestPalindrome(s string) string {
	n := l(s)
	ans := ""
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
	}
	for l := 0; l < n; l++ {
		for i := 0; i+l < n; i++ {
			j := i + l
			if l == 0 {
				dp[i][j] = 1
			} else if l == 1 {
				if s[i] == s[j] {
					dp[i][j] = 1
				}
			} else {
				if s[i] == s[j] {
					dp[i][j] = dp[i+1][j-1]
				}
			}
			if dp[i][j] > 0 && l+1 > l(ans) {
				ans = s[i : i+l+1]
			}
		}
	}
	return ans
}
