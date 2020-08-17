/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 *
 * https://leetcode-cn.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (66.51%)
 * Likes:    352
 * Dislikes: 0
 * Total Accepted:    51.4K
 * Total Submissions: 77.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵表示一个图像。
 * 
 * 将图像顺时针旋转 90 度。
 * 
 * 说明：
 * 
 * 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 * 
 * 示例 1:
 * 
 * 给定 matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 给定 matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row < 2) {
            return;
        }
        for (int i = 0; i < row/2; ++i) {
            for (int j = i; j < row-1-i; ++j) {
                int& u = matrix[i][j];
                int& r = matrix[j][row-1 - i];
                int& d = matrix[row-1 - i][row-1 -j];
                int& l = matrix[row-1 - j][i];

                int tmp = matrix[i][j];
                u = l;
                l = d;
                d = r;
                r = tmp;
                
            }
        }

        // for (int ii = 0; ii < row; ++ii) {
        //     for (int jj = 0; jj < row; ++jj) {
        //         std::cout << matrix[ii][jj] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;
    }
};
// @lc code=end

