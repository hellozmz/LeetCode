 /*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 *
 * https://leetcode.cn/problems/reach-a-number/description/
 *
 * algorithms
 * Medium (44.42%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 31.9K
 * Testcase Example:  '2'
 *
 * 在一根无限长的数轴上，你站在0的位置。终点在target的位置。
 * 
 * 你可以做一些数量的移动 numMoves :
 * 
 * 
 * 每次你可以选择向左或向右移动。
 * 第 i 次移动（从  i == 1 开始，到 i == numMoves ），在选择的方向上走 i 步。
 * 
 * 
 * 给定整数 target ，返回 到达目标所需的 最小 移动次数(即最小 numMoves ) 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: target = 2
 * 输出: 3
 * 解释:
 * 第一次移动，从 0 到 1 。
 * 第二次移动，从 1 到 -1 。
 * 第三次移动，从 -1 到 2 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: target = 3
 * 输出: 2
 * 解释:
 * 第一次移动，从 0 到 1 。
 * 第二次移动，从 1 到 3 。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * -10^9 <= target <= 10^9
 * target != 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 3
    // 1->3
    //   0 1 2 3
    // 0 0
    // 1 0 1 
    // 2 0 1 x 2
    // 3 0 1 3 2
    // 4
    // 5

    // 2
    //   0 1 2 3
    // 0 0
    // 1 0 1 
    // 2 0 1 1 2
    // 3
    // 4
    // dp[i][j] = dp[i-1][j-1] + 2;
    // dp[i][j] = dp[i-1][j-i] + 1;
    int reachNumber(int target) {
        int len = target * 2 - 1;
        // target 行/ 所有可能的列
        vector<vector<int>> dp(len + 1, vector<int>(target + 1, INT_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= i / 2 + 1; ++j) {
                if (dp[i-1][j] != INT_MAX) {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
};
// @lc code=end

