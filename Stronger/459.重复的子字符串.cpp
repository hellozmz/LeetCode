/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode.cn/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (51.08%)
 * Likes:    792
 * Dislikes: 0
 * Total Accepted:    143.8K
 * Total Submissions: 281.6K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abab"
 * 输出: true
 * 解释: 可由子串 "ab" 重复两次构成。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "aba"
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "abcabcabcabc"
 * 输出: true
 * 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        for (int i = 0; i < len / 2; ++i) {
            if (len % (i + 1) != 0) {
                continue;
            }
            string sub = s.substr(0, i + 1);
            // cout << "sub = " << sub << endl;
            int rep = len / (i + 1);
            string tmp = "";
            while (rep > 0) {
                tmp += sub;
                --rep;
            }

            // cout << "tmp = " << tmp << endl;
            if (tmp == s) {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

