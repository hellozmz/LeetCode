/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (57.42%)
 * Likes:    2095
 * Dislikes: 0
 * Total Accepted:    658.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * 
 * 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 * 
 * 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[7,1,5,3,6,4]
 * 输出：5
 * 解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 * ⁠    注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief 贪心方法
     * 
     * @param prices 
     * @return int 
     */
    int maxProfit0(vector<int>& prices) {
        int result = 0;
        int minPrice = INT_MAX;
        for (auto p : prices) {
            minPrice = min(minPrice, p);
            result = max(result, p - minPrice);
        }
        return result;
    }

    /**
     * @brief 动态规划
     * 
     * @param prices 
     * @return int 
     */
    int maxProfit1(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }
        // 0买了，1卖了有收益
        vector<vector<int>> dp(len, vector<int>(2, 0));
        
        // init
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        // dp
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i][0] + prices[i]);
        }

        return dp[len - 1][1];
    }


    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int result = 0;
        for (auto& p : prices) {
            buy = min(buy, p);
            result = max(result, p - buy);
        }

        return result;
    }
};
// @lc code=end

