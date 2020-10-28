/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (50.83%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    51.6K
 * Total Submissions: 101.4K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："hello"
 * 输出："holle"
 * 
 * 
 * 示例 2：
 * 
 * 输入："leetcode"
 * 输出："leotcede"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 元音字母不包含字母 "y" 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool valid(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    void swap(std::string& s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (l < r && !valid(s[l])) {
                ++l;
            }
            // cout << "l = " << l << ", v = " << s[l] << endl;
            while (l < r && !valid(s[r])) {
                --r;
            }
            // cout << "r = " << r << ", v = " << s[r] << endl;
            if (l < r)
                swap(s, l++, r--);
        }
        return s;
    }
};
// @lc code=end

