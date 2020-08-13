/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (37.11%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    37.8K
 * Total Submissions: 101.8K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 * 
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> money(amount + 1, amount + 1);
        money[0] = 0;

        for (int i = 0; i <= amount; ++i) {
            // for (int j = 0; j < coins.size(); ++j) {
            //     if (i - coins[j] >= 0) {
            //         money[i] = std::min(money[i], money[i-coins[j]] + 1);
            //     }
            // }
            for (auto coin : coins) {
                if (i >= coin) {
                    money[i] = std::min(money[i], money[i-coin] + 1);
                }
            }
        }

        // for (auto m : money) {
        //     std::cout << m << " ";
        // }
        // std::cout << std::endl;
        
        return money[amount] != amount+1 ? money[amount] : -1;
    }

    int coinChange1(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// @lc code=end

