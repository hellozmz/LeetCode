/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (40.17%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    33.7K
 * Total Submissions: 84K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 * 
 */

// @lc code=start
class Solution {
public:
    void backtrace(std::vector<std::vector<char>> &board,
                   std::vector<std::vector<int>> &mask, int row, int col,
                   std::string &word, int index, bool &is_exist) {
        if (is_exist) {
            return;
        }
        if (index == word.size()) {
            is_exist = true;
            return;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            is_exist = false;
            return;
        }
        // std::cout << "row=" << row << ", col=" << col << ", index=" << index
        //           << ", mask=" << mask[row][col] << ", char=" << word[index] << std::endl;
        if ((!mask[row][col]) && (board[row][col] == word[index])) {
            mask[row][col] = true;
            // right
            backtrace(board, mask, row, col+1, word, index+1, is_exist);
            // left
            backtrace(board, mask, row, col-1, word, index+1, is_exist);
            // up
            backtrace(board, mask, row-1, col, word, index+1, is_exist);
            // down
            backtrace(board, mask, row+1, col, word, index+1, is_exist);
            mask[row][col] = false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) {
            return true;
        }
        int row = board.size();
        if (row == 0) {
            return false;
        }
        int col = board[0].size();
        if (row * col < word.size()) {
            return false;
        }
        bool is_exist = false;
        std::vector<std::vector<int>> mask(row, std::vector<int>(col, false));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                backtrace(board, mask, i, j, word, 0, is_exist);
                if (is_exist) {
                    return is_exist;
                }
            }
        }
        return is_exist;
    }
};
// @lc code=end

