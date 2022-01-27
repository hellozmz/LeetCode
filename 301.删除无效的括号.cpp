/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 *
 * https://leetcode-cn.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (54.78%)
 * Likes:    655
 * Dislikes: 0
 * Total Accepted:    57.3K
 * Total Submissions: 104.4K
 * Testcase Example:  '"()())()"'
 *
 * 给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。
 * 
 * 返回所有可能的结果。答案可以按 任意顺序 返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()())()"
 * 输出：["(())()","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "(a)())()"
 * 输出：["(a())()","(a)()()"]
 * 
 * )(
 * 示例 3：
 * 
 * 
 * 输入：s = ")("
 * 输出：[""]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由小写英文字母以及括号 '(' 和 ')' 组成
 * s 中至多含 20 个括号
 * 
 * class Solution {
public:
    bool isValid(string str) {
        int count = 0;

        for (char c : str) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) {
                    return false;
                }
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> currSet;

        currSet.insert(s);
        while (true) {
            for (auto & str : currSet) {
                if (isValid(str))
                    ans.emplace_back(str);
            }
            if (ans.size() > 0) {
                return ans;
            }
            unordered_set<string> nextSet;
            for (auto & str : currSet) {
                for (int i = 0; i < str.size(); i++) {
                    if (i > 0 && str[i] == str[i - 1]) {
                        continue;
                    }
                    if (str[i] == '(' || str[i] == ')') {
                        nextSet.insert(str.substr(0, i) + str.substr(i + 1, str.size()));
                    }
                }
            }
            currSet = nextSet;
        }
    }
};
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {

    }
};
// @lc code=end

