/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 *
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Medium (41.56%)
 * Likes:    1606
 * Dislikes: 0
 * Total Accepted:    742.7K
 * Total Submissions: 1.8M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0
 * 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack 和 needle 仅由小写英文字符组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int strStr0(string haystack, string needle) {
        if (haystack.find(needle) != string::npos) {
            // str 的 find 接口返回的结果直接就是下标，这个没有想到
            return haystack.find(needle);
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        int len = haystack.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (equals(haystack.substr(i, j - i + 1), needle)) {
                    return i;
                }
            }
        }
        return -1;
    }

    bool equals(string base, string cmp) {
        // cout << base << endl;
        if (base == cmp) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

