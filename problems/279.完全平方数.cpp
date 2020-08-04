/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (52.99%)
 * Likes:    290
 * Dislikes: 0
 * Total Accepted:    33.6K
 * Total Submissions: 63.5K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        std::vector<int> dp(n+1, INT_MAX - 1);
        for (int i=0; i <= n; ++i) {
            if (i==0) {
                dp[i] = 0;
                continue;
            }
            if (i==1) {
                dp[i] = 1;
                continue;
            }
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = std::min(dp[i], dp[i - j*j] + 1);
            }
        }
        // for (auto elem : dp) {
        //     std::cout << elem << " ";
        // }
        // std::cout << std::endl;
        return dp[n];
    }
};
// @lc code=end

