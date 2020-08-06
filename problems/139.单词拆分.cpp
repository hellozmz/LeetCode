/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (43.01%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    31.6K
 * Total Submissions: 73.5K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<std::string> dict;
        for (auto word : wordDict) {
            dict.insert(word);
        }

        int len = s.size();
        std::vector<int> dp(len+1, 0);
        dp[0] = 1;
        // i 代表当前要查看的长度
        for (int i = 1; i <= len; ++i) {
            // j 代表遍历的具体的位置，在dp中是[1, len]位置对应的s
            for (int j = 0; j < i; ++j) {
                // 字符串边界(j, i]
                if (dp[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    dp[i] = 1;
                }
            }
        }
        return dp[len];
    }
};
// @lc code=end

