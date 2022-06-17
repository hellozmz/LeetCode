/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (35.85%)
 * Likes:    1634
 * Dislikes: 0
 * Total Accepted:    220.9K
 * Total Submissions: 615.8K
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s[i] 为 '(' 或 ')'
 * 
 * 
 * class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int max = 0;
        std::vector<int> dp(len, 0);
        for (int i = 1; i < len; ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '('){
                    if (i >= 2) {
                        dp[i] = dp[i-2] + 2;
                    } else {
                        dp[i] = 2;
                    }
                } else {
                    int last_pos = i - dp[i - 1];
                    if (last_pos > 0 && s[last_pos - 1] == '(') {
                        // 里面开始递归的处理
                        dp[i] = dp[i-1] + 2;
                        // 处理这种："()(())"\n
                        if (i - dp[i-1] >= 2) {
                            dp[i] += dp[i - dp[i-1] - 2];
                        }
                    }
                    // dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                max = std::max(max, dp[i]);
            }
        }
        // for (auto v : dp) {
        //     std::cout << v << " ";
        // }
        return max;
    }
};
// @lc code=end

