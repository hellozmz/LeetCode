/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 * 最简单的动态规划的问题：整体最大的受益是每天的受益积累出来的
 * 由于数字都是大于0的，可以使用每天的受益和0比较，如果小于认为是0，
 * 这样就可以计算出每天的受益，整体的受益就是每天受益的和
 */

// @lc code=start
class Solution {
public:
    int maxProfit0(vector<int>& prices) {
        int len = prices.size();
        if (len < 1) {
            return 0;
        }
        int diff[len] = {0};
        for (int i=0; i<len-1; ++i) {
            diff[i] = prices[i+1] - prices[i];
        }
        int dp[len] = {0};
        int profit = 0, rst = 0;
        for (int i=0; i<len-1; ++i) {
            profit = std::max(0, diff[i] + profit);
            rst = std::max(rst, profit);
        }
        return rst;
    }

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 1) {
            return 0;
        }
        int last=0, profit=0;
        for (int i=0; i<len-1; ++i) {
            last = std::max(0, last + prices[i+1]-prices[i]);
            profit = std::max(last, profit);
        }
        return profit;
    }
};
// @lc code=end

