/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.47%)
 * Likes:    2738
 * Dislikes: 0
 * Total Accepted:    538.8K
 * Total Submissions: 695.5K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string item;
        bt(result, n, n, item);
        return result;
    }

    void bt(std::vector<std::string>& result, int left, int right, std::string& str) {
        // left 剩余的做括号个数，right 剩余的右括号个数
        if (left == 0 && right == 0) {
            result.push_back(str);
            return;
        }

        if (left > 0) {
            str.push_back('(');
            bt(result, left - 1, right, str);
            str.pop_back();
        }

        if (right > left) {
            str.push_back(')');
            bt(result, left, right - 1, str);
            str.pop_back();
        }
    }
};
// @lc code=end

