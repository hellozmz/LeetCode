/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode.cn/problems/integer-break/description/
 *
 * algorithms
 * Medium (62.09%)
 * Likes:    950
 * Dislikes: 0
 * Total Accepted:    208K
 * Total Submissions: 334.9K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 * 
 * 返回 你可以获得的最大乘积 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: n = 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 
 * 输入: n = 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= n <= 58
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        }
        vector<int> dp(n + 1);
        dp[2] = 2;
        dp[3] = 3;
        dp[4] = 4;
        for (int i = 5; i <= n; ++i) {
            dp[i] = max(dp[i-3] * 3, dp[i-4] * 4);
        }
        return dp[n];
    }
};
// @lc code=end

