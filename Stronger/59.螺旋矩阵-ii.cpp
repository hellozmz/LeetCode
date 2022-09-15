/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (75.58%)
 * Likes:    819
 * Dislikes: 0
 * Total Accepted:    241.2K
 * Total Submissions: 320.2K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int loop = 0;
        int mid = n / 2;
        int startx = 0, starty = 0;
        int count = 1;
        vector<vector<int>> result(n, vector<int>(n));
        while (loop < mid) {
            for (int i = loop; i < n - loop - 1; ++i) {
                result[loop][i] = count++;
            }
            for (int i = loop; i < n - loop - 1; ++i) {
                result[i][n - loop - 1] = count++;
            }
            for (int i = n - loop - 1; i > loop; --i) {
                result[n - loop - 1][i] = count++;
            }
            for (int i = n - loop - 1; i > loop; --i) {
                result[i][loop] = count++;
            }

            ++loop;
        }

        if (n % 2 == 1) {
            result[mid][mid] = count;
        }

        // for (auto v : result) {
        //     for (auto i : v) {
        //         cout << i << ' ';
        //     }
        //     cout << endl;
        // }
        return result;
    }
};
// @lc code=end

