/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 * 1.在构造使用字符串的例子的时候，需要加上引号""，否则会报错（https://banthink.com/index.php/archives/51/）。
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0; // 闭区间
        int len = s.size();
        int max_len = 0;
        std::set<char> char_set;
        std::cout << "string=" << s << std::endl;
        while ((start <= end) && (end < len)) {
            std::cout << "cur char=" << s[end] << std::endl;
            if (char_set.find(s[end]) == char_set.end()) {  // 缓存不重复的字符
                char_set.insert(s[end]);
                max_len= std::max(max_len, end - start + 1);
                end++;
                std::cout << "insert char=" << s[end] << std::endl;
            } else {
                char_set.erase(s[start]);
                start++;
            }
        }

        return max_len;
    }
};
// @lc code=end

