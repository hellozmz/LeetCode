/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 *
 * https://leetcode-cn.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (73.65%)
 * Likes:    1133
 * Dislikes: 0
 * Total Accepted:    260.1K
 * Total Submissions: 353K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 * 
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 * [1,2,3],
 * [4,5,6],
 * [7,8,9]
 * 
 * 1 4 7
 * 2 5 8
 * 3 6 9
 * 
 * [7,4,1],
 * [8,5,2],
 * [9,6,3]
 * 
 * [3,8,9],
 * [6,5,4],
 * [1,2,7]
 * 
 * 3 6 9 
2 5 8 
1 4 7 
3 8 9 
6 5 4 
1 2 7 

3 8 9 5 4
6 5 4 5 6
1 2 7 5 7
1 2 3 4 5
5 6 7 8 9


 * 示例 2：
 * 
 * 
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * (i,j)   (row - j,i)
 * [5,1,9,11],
 * [2,4,8,10],
 * [13,3,6,7],
 * [15,14,12,16]
 * 
 * 15,13, ,5
 * ,,,1
 * 
 * [15,13,2,5],
 * [14,3,4,1],
 * [12,6,8,9],
 * [16,7,10,11]
 * 
 * 15 13 2 5 
  '14 4 8 1 
  '12 3 6 9 
  '16 7 10 11 
 * [15,12,14,5],
 * [7,4,8,13],
 * [10,3,6,2],
 * [16,9,1,11]
 * 提示：
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tmp;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp; 
            }
        }

        for (int i = 0; i < n; ++i) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }



    void rotate0(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return;
        }
        int mid = row / 2;
        int mid1 = row % 2 ? mid - 1 : mid;

        int a/*左上*/, b/*右上*/, c/*右下*/, d/*左下*/, tmp;
        for (int i = 0; i <= mid1; ++i) {
            for (int j = 0; j <= mid; ++j) {
                a = matrix[i][j];
                b = matrix[j][row - 1 - i];
                c = matrix[row - 1 - i][row - 1 - j];
                d = matrix[row - 1 - j][i];
                tmp = a;
                a = d;
                d = c;
                c = b;
                b = tmp;
                matrix[i][j] = a;
                matrix[j][row - 1 - i] = b;
                matrix[row - 1 - i][row - 1 - j] = c;
                matrix[row - 1 - j][i] = d;
            }
            print(matrix);
        }
    }

    void print(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (auto &vec : matrix) {
            for (auto &num : vec) {
                std::cout << num << " ";
            }
            std::cout << endl;
        }
    }
};
// @lc code=end

