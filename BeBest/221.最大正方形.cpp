/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (48.16%)
 * Likes:    1012
 * Dislikes: 0
 * Total Accepted:    162.7K
 * Total Submissions: 337.4K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [["0","1"],["1","0"]]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * [["1","0","1","0","0"],
 *  ["1","0","1","1","1"],
 *  ["1","1","1","1","1"],
 *  ["1","0","0","1","0"]]

 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int max_len = 0;
        vector<vector<int>> dp(row + 1, std::vector<int>(col + 1, 0));
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1])) + 1;
                    max_len = std::max(max_len, dp[i][j]);
                }
            }
        }
        return max_len * max_len;
    }
    int maximalSquare0(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        std::vector<std::vector<int>> dp(row + 1, std::vector<int>(col + 1, 0));
        for (int i = 0; i <= row; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= col; ++i) {
            dp[0][i] = 0;
        }
        int len = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    // std::cout << "i = " << i << ", j = " << j << std::endl;
                    dp[i+1][j+1] = std::min(dp[i][j], std::min(dp[i][j+1], dp[i+1][j])) + 1;
                    len = std::max(len, dp[i+1][j+1]);
                }
            }
        }
        // for (auto &v : dp) {
        //     for (auto &i : v) {
        //         std::cout << i << " ";
        //     }
        //     std::cout << std::endl;
        // }
        return len * len;
    }
};
// @lc code=end

