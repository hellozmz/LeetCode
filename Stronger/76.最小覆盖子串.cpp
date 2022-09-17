/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (44.42%)
 * Likes:    2044
 * Dislikes: 0
 * Total Accepted:    324.6K
 * Total Submissions: 727.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */

// @lc code=start
class Solution {
public:
    string minWindow0(string s, string t) {
        // 记录返回的字符串，需要维护起始和长度
        // 为了提升效率，将要比较的元素都给放到hash表中维护
        // 滑动窗口需要维护左右边界
        int left = 0, right = 0;
        int start = 0, len = INT_MAX;
        std::unordered_map<char, int> windows, need;
        for (auto ch : t) {
            ++need[ch];             // 将要处理的字符串中的字符统计出来
        }
        int s_len = s.size();
        int match_count = 0;
        while (right < s_len) {
            char ch = s[right];
            ++right;
            if (need.count(ch) > 0) {
                ++windows[ch];
                if (windows[ch] == need[ch]) {
                    ++match_count;
                }
            }

            while (need.size() == match_count) {
                if (len > right - left) {
                    start = left;
                    len = right - left;
                }
                char c = s[left];
                ++left;
                if (need.count(c) > 0) {
                    if (windows[c] == need[c]) {
                        --match_count;
                    }
                    --windows[c];
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }

    string minWindow(string s, string t) {
        int len = s.size();
        std::unordered_map<char, int> need;
        std::unordered_map<char, int> windows;
        for (auto ch : t) {
            ++need[ch];
        }
        int start = 0, end = INT_MAX;
        bool found = false;
        int left = 0, right = 0;
        int match_count = 0;
        while (right < len) {
            char ch = s[right];
            ++windows[ch];
            if (need.count(ch) > 0 && windows[ch] == need[ch]) {
                ++match_count;
            }
            while (left < right && match_count == need.size()) {
                if (end - start > right - left) {
                    end = right;
                    start = left;
                    found = true;
                }
                char ch = s[left];
                --windows[ch];
                if (need.count(ch) > 0 && windows[ch] < need[ch]) {
                    --match_count;
                }
                ++left;
            }
            ++right;
        }
        return found ? s.substr(start, end - start) : "";
    }

};
// @lc code=end

