/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (50.92%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    13K
 * Total Submissions: 25.6K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 示例:
 * 
 * 输入: [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int len = prices.size();
        // dp 第二列，分别代表当天结束时候的状态：
        // 0:持有股票
        // 1:卖出了股票，接下来一天需要处于冷冻期
        // 2:无股票，可以买
        std::vector<std::vector<int>> dp(len, std::vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = std::max(dp[i-1][2], dp[i-1][1]);
        }
        return std::max(dp[len-1][1], dp[len-1][2]);
    }
};
// @lc code=end

