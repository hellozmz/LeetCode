/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (51.92%)
 * Likes:    1142
 * Dislikes: 0
 * Total Accepted:    108.3K
 * Total Submissions: 208.5K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 
 * [["1","0","1","0","0"],
 *  ["1","0","1","1","1"],
 *  ["1","1","1","1","1"], 
 *  ["1","0","0","1","0"]]
 * 
 * 输出：6
 * 解释：最大矩形如上图所示。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = []
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：matrix = [["1"]]
 * 输出：1
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：matrix = [["0","0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * rows == matrix.length
 * cols == matrix[0].length
 * 1 <= row, cols <= 200
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();

        std::vector<std::vector<int>> left(row, std::vector<int>(col, 0));      // 初始化
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j != 0 ? left[i][j-1] + 1 : 1);
                }
            }
        }

        int result = 0;
        for (int j = 0; j < col; ++j) {
            // todo: mini stack
            std::stack<int> stack1;
            std::vector<int> up(row, 0), down(row, 0);

            for (int i = 0; i < row; ++i) {
                while (!stack1.empty() && left[stack1.top()][j] >= left[i][j]) {
                    stack1.pop();    // 把所有的都吐出去（大于等于的都吐出去，下面统一去加进来一个）
                }
                up[i] = (stack1.empty() ? -1 : stack1.top());
                stack1.push(i);
            }

            stack1 = std::stack<int>();
            for (int i = row - 1; i >= 0; --i) {
                while (!stack1.empty() && left[stack1.top()][j] >= left[i][j]) {
                    stack1.pop();
                }
                down[i] = (stack1.empty() ? row : stack1.top());
                stack1.push(i);
            }

            for (int i = 0; i < row; ++i) {
                result = std::max(result, (down[i] - up[i] - 1) * left[i][j]);
            }
        }

        return result;
    }

    int maximalRectangle00(vector<vector<char>>& matrix) {
        int result = 0;
        int row = matrix.size();
        if (row == 0) {
            return result;
        }
        int col = matrix[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                for (int ei = i; ei < row; ++ei) {
                    for (int ej = j ; ej < col; ++ej) {
                        if (check(matrix, i, j, ei, ej)) {
                            result = std::max((ei - i + 1) * (ej - j + 1), result);
                        }
                    }
                }
            }
        }
        return result;
    }

    bool check(vector<vector<char>>& matrix, int i, int j, int ei, int ej) {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int m = i; m <= ei; ++m) {
            for (int n = j; n <= ej; ++n) {
                if (matrix[m][n] == '0') {
                    return false;
                }
            }
        }
        return true;
    }

    int maximalRectangle_official(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        // 记录了从左到右的连续1的个数，可以看成是84题中的柱状图的高度
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
                }
            }
        }

        // log
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << left[i][j] << " ";
            }
            std::cout << endl;
        }

        int ret = 0;
        for (int j = 0; j < n; j++) { // 对于每一列，使用基于柱状图的方法
            vector<int> up(m, 0), down(m, 0);

            stack<int> stk;
            for (int i = 0; i < m; i++) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }

            // log
            std::cout << "up\n";
            for (int i = 0; i < m; ++i) {
                std::cout << up[i] << " ";
            }
            std::cout << std::endl;

            stk = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            // log
            std::cout << "down\n";
            for (int i = 0; i < m; ++i) {
                std::cout << down[i] << " ";
            }
            std::cout << std::endl;
            for (int i = 0; i < m; i++) {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }

};
// @lc code=end

/**
 * @brief 
 * class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < n; j++) { // 对于每一列，使用基于柱状图的方法
            vector<int> up(m, 0), down(m, 0);

            stack<int> stk;
            for (int i = 0; i < m; i++) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            stk = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; i++) {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/maximal-rectangle/solution/zui-da-ju-xing-by-leetcode-solution-bjlu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */