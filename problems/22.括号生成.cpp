/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.04%)
 * Likes:    715
 * Dislikes: 0
 * Total Accepted:    69.1K
 * Total Submissions: 94.6K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        dfs(result, "", n, 0, 0);
        return result;
    }
    void dfs(std::vector<std::string>& result, std::string path,
             int n, int left_size, int right_size) {
        if (left_size > n || right_size > n || right_size > left_size) {
            return;
        }
        if (left_size == n && right_size == n) {
            result.push_back(path);
        }
        dfs(result, path + "(", n, left_size + 1, right_size);
        dfs(result, path + ")", n, left_size, right_size + 1);
    }
};
// @lc code=end

