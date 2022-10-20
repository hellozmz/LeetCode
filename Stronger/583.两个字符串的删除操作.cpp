/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 *
 * https://leetcode.cn/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (65.82%)
 * Likes:    503
 * Dislikes: 0
 * Total Accepted:    100.7K
 * Total Submissions: 152.9K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
 * 
 * 每步 可以删除任意一个字符串中的一个字符。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: word1 = "sea", word2 = "eat"
 * 输出: 2
 * 解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
 * 
 * 
 * 示例  2:
 * 
 * 
 * 输入：word1 = "leetcode", word2 = "etco"
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 1 <= word1.length, word2.length <= 500
 * word1 和 word2 只包含小写英文字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief 题目可以抽象成获取最长公共子序列长度，然后分别使用两个数组减去该长度就是结果
     * 
     * @param word1 
     * @param word2 
     * @return int 
     */
    int minDistance(string word1, string word2) {
        if (word1 == word2) {
            return 0;
        }
        int len1 = word1.size();
        int len2 = word2.size();

        if (len1 * len2 == 0) {
            return len1 + len2;
        }

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        // init
        
        // dp
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        for (auto& v : dp) {
            for (auto i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
        return len1 + len2 - dp[len1][len2] * 2;
    }
};
// @lc code=end

