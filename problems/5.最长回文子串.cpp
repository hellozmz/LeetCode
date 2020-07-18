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

