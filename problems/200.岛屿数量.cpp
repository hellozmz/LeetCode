/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (46.75%)
 * Likes:    347
 * Dislikes: 0
 * Total Accepted:    51.1K
 * Total Submissions: 109.4K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给定一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
        } else {
            return;
        }

        if (i > 0)  dfs(grid, i - 1, j);
        if (i < grid.size() - 1)  dfs(grid, i + 1, j);
        if (j > 0)  dfs(grid, i, j - 1);
        if (j < grid[0].size() - 1)  dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
// @lc code=end
