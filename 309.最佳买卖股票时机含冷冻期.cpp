/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (61.93%)
 * Likes:    1050
 * Dislikes: 0
 * Total Accepted:    141K
 * Total Submissions: 227.6K
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
 * int maxProfit(vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        // f[i][0]: 手上持有股票的最大收益
        // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
};

 */

// @lc code=start
class Solution {
public:
    int maxProfit00(vector<int>& prices) {
        // 动态规划的方法
        int len = prices.size();
        if (len == 0) {
            return 0;
        }
        std::vector<int> buy(len, 0);               // 一共有3个状态，那么就使用三个动态方程记录状态转移方程
        std::vector<int> sell(len, 0);
        std::vector<int> cold(len, 0);

        buy[0] = 0 - prices[0];                     // 状态初始化
        for (int i = 1; i < len; ++i) {
            buy[i] = std::max(buy[i-1], cold[i-1] - prices[i]);
            sell[i] = buy[i-1] + prices[i];
            cold[i] = std::max(cold[i-1], sell[i-1]);
        }
        return std::max(sell[len -1], cold[len - 1]);
    }

    int maxProfit(vector<int>& prices) {
        // 贪心方法：
        // 记录上次交易时候的买卖之后的价格，同时计算当前情况下和上次之间价格的收益（冷静期就使用到了这个上次和这次之间的逻辑关系）
        // 下面的逻辑理解起来有些绕，还是想要使用动态规划做
        int buy(INT_MIN);       // 买之后的钱
        int sell(0);            // 卖之后的钱（初始化为0）
        int pre_buy;            // 记录的上次的上次
        int pre_sell(0);
        for (auto price : prices) {
            pre_buy = buy;
            buy = std::max(buy, pre_sell - price);      // 买入有一天的冷静期，要使用上一次卖完的价格
            pre_sell = sell;
            sell = std::max(pre_buy + price, sell);
            // std::cout << buy << ", " << sell << std::endl;
        }
        return sell;
    }
};
// @lc code=end

