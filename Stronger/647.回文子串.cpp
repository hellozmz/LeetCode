/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode.cn/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (66.51%)
 * Likes:    918
 * Dislikes: 0
 * Total Accepted:    198.7K
 * Total Submissions: 298.8K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 * 
 * 回文字符串 是正着读和倒过来读一样的字符串。
 * 
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSubstrings0(string s) {
        int len = s.size();
        std::vector<std::vector<char>> dp(len, std::vector<char>(len, false));
        for (int i = 0; i < len; ++i) {
            dp[i][i] = true;
        }
        int count = 0;
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i; j < len; ++j) {
                if (s[i] == s[j]) {
                    if (i + 1 < len && j - 1 >= 0) {
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if (j - i < 2) {
                        dp[i][j] = true;
                    }
                }
                // std::cout << "i = " << i << ", j = " << j << ", state = " << dp[i][j] << std::endl;
                if (dp[i][j]) {
                    ++count;
                }
                // std::cout << "(" << i << "," << j << ")  ";
            }
            // std::cout << "\n";
        }
        // std::cout << "\n";
        return count;
    }

    /**
     * @brief 暴力方法是O(n^3)，动态规划就是为了能降低复杂度，重新试下。
     * BTW：这应该也是一个hard题目才对呀
     * 
     * @param s 
     * @return int 
     */
    int countSubstrings(string s) {
        int len = s.size();
        int count = 0;
        // 从 i->j 是回文串
        vector<vector<bool>> dp(len, vector<bool>(len, false));

        // dp
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i; j < len; ++j) {
                if (s[i] == s[j]) {
                    if (i == j) {
                        dp[i][j] = true;
                    } else if (j - i == 1) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                } else {
                    dp[i][j] = false;
                }

                if (dp[i][j]) {
                    ++count;
                }
            }
        }

        return count;
    }
};
// @lc code=end

