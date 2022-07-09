/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode.cn/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (58.08%)
 * Likes:    1786
 * Dislikes: 0
 * Total Accepted:    502.4K
 * Total Submissions: 864.9K
 * Testcase Example:  
 * '[["1","1","1","1","0"],
 *   ["1","1","0","1","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 
 * grid[i][j] 的值为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    std::vector<std::pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        bool isIs = false;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                bfs(grid, cnt, false, i, j);
            }
        }
        return cnt;
    }

    void bfs(std::vector<std::vector<char>>& grid, int& cnt, bool isIs, int i, int j) {
        if (grid[i][j] != '0') {
            if (!isIs) {
                isIs = true;
                ++cnt;
            }
        } else {
            isIs = false;
            return;
        }
        grid[i][j] = '0';
        // std::cout << "i=" << i << ", j = " << j << ", grid = " << grid[i][j] << ", cnt = " << cnt << std::endl;
        for (auto d : dir) {
            int newi = i + d.first, newj = j + d.second;
            if (newi >= 0 && newi < grid.size() && newj >= 0 && newj < grid[0].size()) {
                bfs(grid, cnt, isIs, newi, newj);
            }
        }
    }
};
// @lc code=end

