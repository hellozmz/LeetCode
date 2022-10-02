/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.56%)
 * Likes:    3530
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.8M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
        unordered_map<char, char> mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stack;
        for (auto ch : s) {
            if (mapping.count(ch) == 0) {
                stack.push(ch);
            } else {
                if (stack.empty()) {
                    return false;
                } else if (stack.top() == mapping[ch]) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};
// @lc code=end

