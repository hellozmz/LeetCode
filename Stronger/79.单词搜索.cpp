/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode.cn/problems/word-search/description/
 *
 * algorithms
 * Medium (46.38%)
 * Likes:    1354
 * Dislikes: 0
 * Total Accepted:    335.4K
 * Total Submissions: 723K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false
 * 。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 
 * 1 
 * board 和 word 仅由大小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 * 
 */

// @lc code=start
class Solution {
public:
    std::vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.length();
        int row = board.size();
        if (row == 0) {
            if (len == 0) {
                return true;
            } else {
                return false;
            }
        }
        int col = board[0].size();
        std::vector<std::vector<char>> visited(row, std::vector<char>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                bool flag = check(board, visited, i, j, 0, len, word);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }

    bool check(const std::vector<std::vector<char>>& board, std::vector<std::vector<char>>& visited, int i, int j, int k, int len, const std::string& word) {
        // [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]  \n "ABCB"
        // [["A","B","C","E"],
        //  ["S","F","C","S"],
        //  ["A","D","E","E"]]
        // 需要优先判断字符是否相同，如果不同需要及时的去返回失败
        if (board[i][j] != word[k]) {
            return false;
        } else if (k == len - 1) {
            return true;
        }
        visited[i][j] = 1;
        bool result = false;
        for (const auto& item : directions) {
            int newi = i + item.first, newj = j + item.second;
            if (newi >=0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool f = check(board, visited, newi, newj, k + 1, len, word);
                    if (f) {
                        result = true;
                        break;
                    }
                }
            }
        }

        visited[i][j] = 0;
        return result;
    }
};
// @lc code=end

