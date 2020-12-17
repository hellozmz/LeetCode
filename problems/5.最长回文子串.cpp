/*
 * @lc app=leetcode.cn id=5 lang=cpp
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
class Solution {
public:
    string longestPalindrome(string s) {
        int r_start = 0, r_len = 0;
        int end = s.size();
        // cout << "s=" << s << ", end=" << end << endl;
        std::vector<std::vector<int>> dp(end, std::vector<int>(end));
        for (int len = 0; len < end; ++len) {
            for (int start = 0; start + len < end; ++start) {
                if (len == 0) {
                    dp[start][start + len] = 1;
                } else if (len == 1) {
                    if (s[start] == s[start + len]) {
                        dp[start][start+len] = 1;
                    }
                } else {
                    if (s[start] == s[start + len]) {
                        dp[start][start+len] = dp[start+1][start+len-1];
                    }
                }
                if (dp[start][start+len] == 1 && len > r_len) {
                    r_start = start;
                    r_len = len;
                }
                // cout << "start=" << start << ", len=" << len
                //     << ", r_start=" << r_start << ", r_len=" << r_len
                //     << ", dp=" << dp[start][start+len] << endl;
            }
        }
        return s.substr(r_start, r_len + 1);
    }

    string longestPalindrome_old(string s) {
        if (s.size() <= 1) {
            return s;
        }
        std::string result("");
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            // 奇数情况
            std::string tmp1 = palindrome(s, i, i);
            // 偶数情况
            std::string tmp2 = palindrome(s, i, i+1);
            if (tmp1.size() > result.size()) {
                result = tmp1;
            }
            if (tmp2.size() > result.size()) {
                result = tmp2;
            }
        }
        return result;
    }

    std::string palindrome(std::string& str, int left, int right) {
        int len = str.size();
        while (left >= 0 && right < len && str[left] == str[right]) {
            --left;
            ++right;
        }
        // 将位置回放回满足条件的样子
        return str.substr(left+1, right-left-1);
    }
};
// @lc code=end

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};
