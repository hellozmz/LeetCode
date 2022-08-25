/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (36.83%)
 * Likes:    5417
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 3M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution0 {
public:
    string longestPalindrome(string s) {
        // 暴力方法
        std::string result;
        for (int i = 0; i < s.size(); ++i) {
            std::string pal = getPal(s, i);
            if (pal.size() > result.size()) {
                result = pal;
            }
        }
        return result;
    }

    std::string getPal(const std::string& str, int idx) {
        int len = str.size();
        int step = 0;
        std::string pal1;
        std::string pal2;
        // 作为中心
        while (idx + step < len && idx - step >= 0) {
            if (str[idx + step] == str[idx - step]) {
                // std::cout << "1 idx = " << idx << ", step = " << step << ", left = " << idx - step << ", right = " << idx + step + 1 << ", str = " << str << std::endl;
                pal1 = str.substr(idx - step, 2 * step + 1);
                // std::cout << "pal1 = " << pal1 << std::endl;
                ++step;
            } else {
                break;
            }
        }

        // 作为左中心
        step = 0;
        while (idx + step + 1 < len && idx - step >= 0) {
            if (str[idx + step + 1] == str[idx - step]) {
                // std::cout << "2 idx = " << idx << ", step = " << step << ", left = " << idx - step << ", right = " << idx + step + 1 << ", str = " << str << std::endl;
                pal2 = str.substr(idx - step, 2 * step + 2);
                // std::cout << "pal2 = " << pal2 << std::endl;
                ++step;
            } else {
                break;
            }
        }
        if (pal1.size() > pal2.size()) {
            return pal1;
        } else {
            return pal2;
        }
    }
};

/**
 * @brief 动态规划
 * 使用二维数组去记录历史遍历过的情况。dp[i][j] 代表从 str[i..j] 是否是回文串
 * true代表是回文，false代表是非回文
 * 初始化：dp[i][i] = true
 * 状态转移方程：str[i] == str[j] -> dp[i][j] = dp[i+1][j-1]
 * [
 *   [(0,0),(0,1),...(0,n)]
 *         ...
 *   [(i,0),(i,j),...(i,n)]
 *   [(i+1,j-1),  ...(i,n)]
 *   [(m,0),(m,1),...(m,n)]
 * ]
 * 通过上面的图可以看出来，需要从下向上，从左向右，遍历整个数组，而且还要保证j>i
 */
class Solution1 {
public:
    string longestPalindrome(string s) {
        // 动态规划
        std::string result;
        int len = s.size();
        int begin = 0, end = 0;
        std::vector<std::vector<char>> dp(len, std::vector<char>(len, false));
        for (int i = 0; i < len; ++i) {
            dp[i][i] = true;
        }

        // for (int i = 0; i < len; ++i) {
        //     for (int j = i; j < len; ++j) {
        //         std::cout << dp[i][j];
        //     }
        //     std::cout << std::endl;
        // }
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i; j < len; ++j) {
                if (s[i] == s[j]) {
                    if (j - i < 2) {        // 需要通过画图去辅助理解
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if (dp[i][j] && j - i > end - begin) {
                    begin = i;
                    end = j;
                }
            }
        }
        // for (int i = 0; i < len; ++i) {
        //     for (int j = i; j < len; ++j) {
        //         std::cout << dp[i][j];
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;
        // std::cout << "begin = " << begin << ", end = " << end << std::endl;
        result = s.substr(begin, end - begin + 1);
        return result;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
    }
};
// @lc code=end

