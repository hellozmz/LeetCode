/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 *
 * https://leetcode.cn/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (42.38%)
 * Likes:    888
 * Dislikes: 0
 * Total Accepted:    113.8K
 * Total Submissions: 268.6K
 * Testcase Example:  '"1 + 1"'
 *
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
 * 
 * 注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "1 + 1"
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = " 2-1 + 2 "
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(1+(4+5+2)-3)+(6+8)"
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
 * s 表示一个有效的表达式
 * '+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
 * '-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
 * 输入中不存在两个连续的操作符
 * 每个数字和运行的计算将适合于一个有符号的 32位 整数
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<char> op;
        stack<int> nums;
        nums.push(0);
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == ' ') {
                continue;
            } else if (ch == '(' || ch == '+' || ch == '-' || ch == ')') {
                op.push(ch);
            } else {
                int num = 0;
                while (i < s.size() && (ch >= '0' && ch <= '9')) {
                    ch = s[i];
                    num *= 10;
                    num += (ch - '0');
                    ++i;
                }
                nums.push(num);
            }
        }

        int result = 0;
        while (!op.empty()) {
            char ch = op.top();
            op.pop();
            if (ch == '+') {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(a + b);
            } else if (ch == '-') {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b - a);
            } else if (ch == '(') {
                continue;
            } else {

            }
        }

        return nums.top();
    }

    int eval() {

    }
};
// @lc code=end

