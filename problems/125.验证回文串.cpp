/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (46.49%)
 * Likes:    285
 * Dislikes: 0
 * Total Accepted:    172.7K
 * Total Submissions: 371.1K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    inline bool valid(string& s, int i) {
        // cout << s[i] << endl;
        return (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9');
    }
    inline bool compare(char a, char b) {
        a = (a >= 'a' ? a - 32 : a);
        b = (b >= 'a' ? b - 32 : b);
        return a == b;
    }
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end) {
            if (!valid(s, begin)) {
                ++begin;
            } else if (!valid(s, end)) {
                --end;
            } else if (!compare(s[begin++], s[end--])) {
                return false;
            }
            // cout << "begin = "<< begin << ", end=" << end << endl;
        }
        return true;
    }
};
// @lc code=end

