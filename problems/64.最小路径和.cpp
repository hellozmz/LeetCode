/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (64.21%)
 * Likes:    369
 * Dislikes: 0
 * Total Accepted:    54K
 * Total Submissions: 84.2K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                dp[i][j] = grid[i][j];
            }
        }
        // for (int i = 0; i < grid.size(); ++i) {
        //     for (int j = 0; j < grid[0].size(); ++j) {
        //         std::cout << dp[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int up = (i==0) ? INT_MAX : dp[i-1][j];
                int left = (j==0)? INT_MAX : dp[i][j-1];
                dp[i][j] += std::min(up, left);
                // std::cout << "up=" << up << ", left=" << left << ", min="
                //           << std::min(up, left) << " " << dp[i][j] << std::endl;
            }
        }

        // for (int i = 0; i < grid.size(); ++i) {
        //     for (int j = 0; j < grid[0].size(); ++j) {
        //         std::cout << dp[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << "INT_MAX=" << INT_MAX << std::endl;
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
// @lc code=end

