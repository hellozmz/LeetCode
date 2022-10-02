/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (38.87%)
 * Likes:    7881
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 4.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start
class Solution0{
public:
// 暴力法
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int max_len = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (unique(s, i, j)) {
                    max_len = std::max(j - i + 1, max_len);
                    // std::cout << i << ", " << j << std::endl;
                }
            }
        }
        return max_len;
    }

    bool unique(std::string& s, int begin, int end) {
        std::unordered_set<char> set;
        for (int i = begin; i <= end; ++i) {
            if (set.count(s[i]) > 0) {
                return false;
            }
            set.insert(s[i]);
        }
        return true;
    }
};

class Solution {
public:
/**
 * @brief 
 * 暴力法需要如何处理：两层的for循环，端点是起点和终点。然后加入一个判断是否有相同元素的比较函数，整体的复杂度是立方
 * 看到题目的第一反应：维护一个hashmap存储数据个数，然后再加上两个指针，估计O(n)的复杂度就可以了
 */

    int lengthOfLongestSubstring(string s) {
        int begin = 0, end = s.size() - 1;
        std::unordered_map<char, int> mapping;
        int index = 0;
        int max_len = 0;
        int len = 0;
        while (index <= end) {
            // std::cout << s[index] << ",0000000 " << begin << std::endl;

            if (mapping.count(s[index]) == 0 || mapping[s[index]] < begin) {
                // std::cout << "s[index]" << s[index] << ", begin " << begin << std::endl;
            } else {
                ++begin;
                while (begin < index && s[begin] == s[index]) {
                    ++begin;
                }
                // std::cout << s[index] << ", " << index << std::endl;
            }
            mapping[s[index]] = index;

            len = index - begin + 1;
            max_len = std::max(max_len, len);
            ++index;
            // std::cout << s[index] << ",aaaaaaa " << begin << std::endl;
        }
        return max_len;
    }
};
// @lc code=end

