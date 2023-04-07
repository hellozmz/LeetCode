/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Medium (71.17%)
 * Likes:    1852
 * Dislikes: 0
 * Total Accepted:    743.3K
 * Total Submissions: 1M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
 * 
 * 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
 * 
 * 返回 你能获得的 最大 利润 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：prices = [7,1,5,3,6,4]
 * 输出：7
 * 解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4
 * 。
 * 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
 * ⁠    总利润为 4 + 3 = 7 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：prices = [1,2,3,4,5]
 * 输出：4
 * 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4
 * 。
 * 总利润为 4 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= prices.length <= 3 * 10^4
 * 0 <= prices[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProfit2(vector<int>& prices) {
        int len = prices.size();
        int buy = INT_MAX;
        bool has = false;
        int get = 0;
        for (auto p : prices) {
            if (p < buy) {
                has = true;
                buy = p;
            }
            if (!has) {
                has = true;
                buy = p;
            }
            if (p > buy && has == true) {
                get += (p - buy);
                buy = p;
            }
            // cout << p << " buy " << buy << ", sold " << p << ", get=" << get << endl;
        }
        return get;
    }

    int maxProfit1(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); ++i) {
            result += max((prices[i] - prices[i-1]), 0);
        }
        return result;
    }


    /**
     * @brief 贪心
     * 
     * @param prices 
     * @return int 
     */
    int maxProfit0(vector<int>& prices) {
        int result = 0;
        int len = prices.size();
        for (int i = 1; i < len; ++i) {
            result += max(prices[i] - prices[i -1], 0);
        }
        return result;
    }

    /**
     * @brief 动态规划
     * 股票问题，使用两个元素控制结果，分别是买了和卖了。有点像是dp中树的感觉（树中是否选择）
     * 
     * @param prices 
     * @return int 
     */
    int maxProfit3(vector<int>& prices) {
        int len = prices.size();

        // vec: 0，买了，1，卖了
        vector<vector<int>> dp(len, vector<int>(2, 0));

        // init
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        // dp
        for (int i = 1; i < len; ++i) {
            // dp[i][0] = -prices[i];
            // dp[i][1] = dp[i - 1][1] + max(0, dp[i - 1][0] + prices[i]);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);     // 和121相比多了收益
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }

        // result
        return dp[len - 1][1];
    }


    int maxProfit4(vector<int>& prices) {
        int len = prices.size();
        // 0:买了；1:卖了
        vector<vector<int>> dp(len, vector<int>(2, 0));

        // init
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        // dp
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        // return
        return dp[len - 1][1];
    }

    int maxProfit5(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        int result = 0;
        for (int i = 0; i < prices.size(); ++i) {
            buy = max(buy, -1 * prices[i]);
            sell = max(sell, buy + prices[i]);
            result += sell;
        }

        return result;
    }


    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i-1][1] - prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] + prices[i], dp[i-1][1]);
        }
        return dp[len - 1][1];
    }
};
// @lc code=end

