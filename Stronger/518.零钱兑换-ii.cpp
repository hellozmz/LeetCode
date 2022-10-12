/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 *
 * https://leetcode.cn/problems/coin-change-ii/description/
 *
 * algorithms
 * Medium (69.60%)
 * Likes:    933
 * Dislikes: 0
 * Total Accepted:    200.6K
 * Total Submissions: 288.2K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
 *
 * 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回
 * 0 。
 *
 * 假设每一种面额的硬币有无限个。 
 *
 * 题目数据保证结果符合 32 位带符号整数。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：amount = 5, coins = [1, 2, 5]
 * 输出：4
 * 解释：有四种方式可以凑成总金额：
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 *
 * 示例 2：
 *
 *
 * 输入：amount = 3, coins = [2]
 * 输出：0
 * 解释：只用面额 2 的硬币不能凑成总金额 3 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：amount = 10, coins = [10]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * coins 中的所有值 互不相同
 * 0
 *
 *
 */

// @lc code=start
/**
 * @brief 简单总结下动态规划的问题
 * 动态规划常见的有两种：01背包和完全背包。区别是每个元素可以被使用的次数。
 * 01代表是否，完全代表元素可以被使用多次。
 * 
 * 另外在实现的时候分为使用一维数组和二维数组：
 * 正常可以使用二维数组，优化内存的话可以采用滚动数组（一维数组）去替换二维数组
 * 
 * 实现的时候需要注意：
 * 1. for循环中i/j的含义
 * 2. dp如何初始化
 * 3. dp状态转移方程
 *
 */
class Solution {
public:
    /**
     * @brief 二维数组处理动态规划完全背包
     *
     * @param amount
     * @param coins
     * @return int
     */
    int change0(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<vector<int>> dp(len + 1, vector<int>(amount + 1, 0));

        // init
        for (int i = 0; i <= len; ++i) { dp[i][0] = 1; }

        // dp
        for (int i = 1; i <= len; ++i) {
            int coin = coins[i - 1];
            for (int j = 0; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coin) {
                    // 如果是01背包问题，这里要这样写，但是这个是上个硬币，不是当前的
                    // dp[i][j] += dp[i - 1][j - coin];
                    dp[i][j] +=
                        dp[i][j - coin];  // 选择这个方法，对当前硬币进行处理
                }
            }
        }

        // for (auto& v : dp) {
        //     for (auto i : v) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        return dp[len][amount];
    }

    /**
     * @brief 一维数组处理动态规划完全背包
     *
     * @param amount
     * @param coins
     * @return int
     */
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<int> dp(amount + 1, 0);

        // init
        dp[0] = 1;

        // dp
        for (int i = 0; i < len; ++i) {
            int coin = coins[i];
            for (int j = coin; j <= amount; ++j) {
                dp[j] = dp[j - coin] + dp[j];
                // cout << dp[j] << " ";
            }
            // cout << endl;
        }
        // cout << endl;

        return dp[amount];
    }
};
// @lc code=end
