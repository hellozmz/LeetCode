/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.30%)
 * Likes:    1286
 * Dislikes: 0
 * Total Accepted:    238.5K
 * Total Submissions: 325.4K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 
 * 回文串 是正着读和反着读都一样的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a"
 * 输出：[["a"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        bt(result, path, s, 0);
        return result;
    }

    void bt(vector<vector<string>>& result, vector<string>& path, string& s, int startIndex) {
        if (startIndex == s.size()) {
            bool allIsSame = true;
            for (auto& item : path) {
                if (!isSame(item)) {
                    allIsSame = false;
                }
            }
            if (allIsSame) {
                result.emplace_back(path);
            }
            return;
        }

        for (int i = startIndex; i < s.size(); ++i) {
            string str = s.substr(startIndex, i - startIndex + 1);
            path.emplace_back(str);
            bt(result, path, s, i + 1);
            path.pop_back();
        }
    }

    bool isSame(string& str) {
        int mid = str.size() / 2;
        for (int i = 0; i < mid; ++i) {
            int e = str.size() - 1 - i;
            if (str[i] != str[e]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

