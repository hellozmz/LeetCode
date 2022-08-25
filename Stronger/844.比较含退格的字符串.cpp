/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 *
 * https://leetcode.cn/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (48.89%)
 * Likes:    499
 * Dislikes: 0
 * Total Accepted:    156.9K
 * Total Submissions: 320.8K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
 * 
 * 注意：如果对空文本输入退格字符，文本继续为空。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ab#c", t = "ad#c"
 * 输出：true
 * 解释：s 和 t 都会变成 "ac"。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "ab##", t = "c#d#"
 * 输出：true
 * 解释：s 和 t 都会变成 ""。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a#c", t = "b"
 * 输出：false
 * 解释：s 会变成 "c"，但 t 仍然是 "b"。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length, t.length <= 200
 * s 和 t 只含有小写字母以及字符 '#'
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
// 错误的方法。
/**
 * @brief 
 * 错误例子："bxj##tw"   "bxo#j##tw"
 * ""bxj##tw"\n"bxo#j##tw""
 * @param s 
 * @param t 
 * @return true 
 * @return false 
 */
    bool backspaceCompare_bugs(string s, string t) {
        int si = s.size() - 1, ti = t.size() - 1;
        while (si >= 0 && ti >= 0) {
            int count = 0;
            while (s[si] == '#') {
                ++count;
                --si;
            }
            si = std::max(0, si - count);
            int count1 = 0;
            while (t[ti] == '#') {
                ++count1;
                --ti;
            }
            ti = std::max(0, ti - count1);
            if (s[si] != t[ti] && s[si] != '#' && t[ti] != '#') {
                return false;
            } else {
                --si;
                --ti;
            }
        }
        return true;
    }
    bool backspaceCompare(string s, string t) {
        return getString(s) == getString(t);
    }

    string getString(std::string& s) {
        int slow = 0, fast = 0;
        int len = s.size();
        while (fast < len) {
            if (s[fast] != '#') {
                s[slow++] = s[fast];
            } else {
                slow = std::max(slow - 1, 0);
            }
            ++fast;
        }
        return s.substr(0, slow);
    }
};
// @lc code=end

