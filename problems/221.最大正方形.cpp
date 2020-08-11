/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (38.62%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    19.9K
 * Total Submissions: 51.6K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max = 0;
        int row = matrix.size();
        if (row == 0) {
            return max;
        }
        int col = matrix[0].size();

        // for (int i = 0; i < row; ++i) {
        //     for (int j = 0; j < col; ++j) {
        //         std::cout << matrix[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        std::vector<std::vector<int>> dp(row, std::vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] - '0') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = std::min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                    }
                    max = std::max(max, dp[i][j]);
                }
            }
        }

        // for (int i = 0; i < row; ++i) {
        //     for (int j = 0; j < col; ++j) {
        //         std::cout << dp[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;
        return max*max;
    }
};
// @lc code=end

