/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (63.78%)
 * Likes:    1334
 * Dislikes: 0
 * Total Accepted:    214.8K
 * Total Submissions: 336.8K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: prices = [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 * 示例 2:
 * 
 * 
 * 输入: prices = [1]
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        // vector: 0 买，1 卖
        vector<vector<int>> dp(len + 1, vector<int>(2, 0));

        // init
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = -prices[0];

        // dp
        for (int i = 2; i <= len; ++i) {
            int p = prices[i - 1];
            // i - 2 体现了上一次也就是冷冻期的概念
            dp[i][0] = max(dp[i - 2][1] - p, dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + p, dp[i - 1][1]);
        }

        // for (auto& v : dp) {
        //     for (auto i : v) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        return dp[len][1];
    }
};
// @lc code=end

