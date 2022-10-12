/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (53.29%)
 * Likes:    2144
 * Dislikes: 0
 * Total Accepted:    678.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 *
 * 示例 2：
 *
 *
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 45
 *
 *
 */
#include "header.hpp"

// @lc code=start
class Solution {
public:
    int climbStairs0(int n) {
        if (n <= 2) { return n; }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) { dp[i] = dp[i - 2] + dp[i - 1]; }
        // printVector<int>(dp);
        return dp[n];
    }

    int climbStairs1(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        // i 步
        vector<int> dp(n + 1, 0);

        // init
        dp[0] = 1;

        // dp
        for (int i = 1; i <= n; ++i) {
            int m = min(i , 2);
            for (int j = 1; j <= m; ++j) {
                dp[i] = dp[i] + dp[i - j];
            }
        }

        return dp[n];
    }
};
// @lc code=end
