/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.13%)
 * Likes:    1206
 * Dislikes: 0
 * Total Accepted:    308.2K
 * Total Submissions: 627.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder0(vector<vector<int>>& matrix) {
        int loop = 0;
        int len = matrix.size();
        vector<int> result(len * len);
        int index = 0;
        while (loop < len) {
            for (int i = loop; i < len - loop - 1; ++i) {
                result[index++] = matrix[loop][i];
            }
            for (int i = loop; i < len - loop - 1; ++i) {
                result[index++] = matrix[i][len - loop - 1];
            }
            for (int i = len - loop - 1; i > loop; --i) {
                result[index++] = matrix[len - loop - 1][i];
            }
            for (int i = len - loop - 1; i > loop; --i) {
                result[index++] = matrix[i][loop];
            }
            ++loop;
        }

        if (len % 2 == 1) {
            result[index] = matrix[len/2][len/2];
        }

        return result;
    }

/**
 * @brief 找好遍历的方法，开闭关系需要对应清楚。
 * 整体思路是：在一个loop的大循环中，执行4个动作，分别是左上向右上，右上向右下，右下向左下，左下向左上
 * 然后是边界问题，就是最后一个元素的问题：
 * 整体来看，都是一圈一圈遍历，当遍历道最后一个元素的时候，是否要在大循环内部做。
 * 如果是长宽都是偶数，不会有这个问题。
 * 如果长宽都是奇数，那最后一个元素需要单独处理
 * 如果长宽中一个是奇数一个是偶数，
 * 
 * @param matrix 
 * @return vector<int> 
 */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> result;
        int row = matrix.size();
        if (row == 0) {
            return result;
        }
        int col = matrix[0].size();
        int hr = row / 2;
        int hc = col / 2;
        int m = 0, n = 0;   // m代表当前遍历的行，n代表当前遍历的列
        while (m < hr && n < hc) {
            // 从左上向右上
            for (int i = n; i < col - n - 1; ++i) {
                result.push_back(matrix[m][i]);
                // cout << result.back() << " ";
            }
            // 右上向右下
            for (int i = m; i < row - m - 1; ++i) {
                result.push_back(matrix[i][col - n - 1]);
                // cout << result.back() << " ";
            }
            // 右下向左下，不能再走到最下了，当发现这一行已经被处理过了，就只能走到上次没走到的地方
            for (int i = col - n - 1; i > n; --i) {
                result.push_back(matrix[row - m - 1][i]);
                // cout << result.back() << " ";
            }
            // 左下向左上
            for (int i = row - m - 1; i > m; --i) {
                result.push_back(matrix[i][n]);
                // cout << result.back() << " ";
            }

            // cout << endl << "m" << m << ",n" << n << endl;
            ++m;
            ++n;
        }
        // cout << "out" << endl;

        if (row < col) {
            // 偶数行的时候，正好可以遍历完毕，当奇数行的时候，需要手动的再遍历下
            if (row % 2 != 0) {
                for (int i = n; i <= col - n - 1; ++i) {
                    result.push_back(matrix[m][i]);
                }
            }
        } else {
            // 偶数的时候，同上面逻辑
            if (col % 2 != 0) {
                for (int i = m; i <= row - m - 1; ++i) {
                    result.push_back(matrix[i][n]);
                }
            }
        }
        // cout << result.back() << " ";
        return result;
    }
};
// @lc code=end

