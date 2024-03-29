/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (52.16%)
 * Likes:    1361
 * Dislikes: 0
 * Total Accepted:    232.3K
 * Total Submissions: 445.3K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
 * 
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
 * 注意，你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s 和 wordDict[i] 仅有小写英文字母组成
 * wordDict 中的所有字符串 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool wordBreak0(string s, vector<string>& wordDict) {
        std::unordered_set<std::string> dict;
        int len = s.size();
        for (auto word : wordDict) {
            dict.insert(word);
        }

        std::vector<bool> dp(len+1, false);
        dp[0] = true;
        for (int end = 1; end <= len; ++end) {
            for (int start = 0; start < end; ++start) {
                if (dp[start] && dict.count(s.substr(start, end - start)) > 0) {
                    dp[end] = true;
                }
            }
        }
        return dp[len];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        // unordered_set<string> dict;
        // for (auto& w : wordDict) {
        //     dict.insert(w);
        // }
        vector<int> dp(len + 1, 0);

        // 认为没有元素的时候，是可以匹配成功的
        dp[0] = 1;

        for (int i = 1; i <= len; ++i) {
            for (auto& w : wordDict) {
                int wlen = w.size();
                if (i >= wlen && s.substr(i - wlen, wlen) == w) {
                    dp[i] = dp[i] || dp[i - w.size()];
                }
            }
        }

        return dp[len] > 0;
    }
};
// @lc code=end

