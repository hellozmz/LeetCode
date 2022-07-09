/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 *
 * https://leetcode.cn/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (55.18%)
 * Likes:    740
 * Dislikes: 0
 * Total Accepted:    74.2K
 * Total Submissions: 134.5K
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
 * 
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
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int lremove = 0, rremove = 0;
        for (char ch : s) {
            if (ch == '(') {
                ++lremove;
            } else if (ch == ')') {
                if (lremove > 0) {
                    --lremove;
                } else {
                    ++rremove;
                }
            }
        }

        std::vector<std::string> result;
        doRemove(result, s, 0, lremove, rremove);
        return result;
    }

    void doRemove(std::vector<std::string>& result, string s, int start, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (isValid(s)) {
                result.push_back(s);
            }
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            // 重复的元素不需要重复计算，逻辑是一样的
            if (i != start && s[i] == s[i-1]) {
                continue;
            }

            // 提前退出的条件
            if (lremove + rremove > s.size() - i) {
                return;
            }

            if (lremove > 0 && s[i] == '(') {
                doRemove(result, s.substr(0, i) + s.substr(i+1), i, lremove - 1, rremove);
            }

            if (rremove > 0 && s[i] == ')') {
                doRemove(result, s.substr(0, i) + s.substr(i+1), i, lremove, rremove - 1);
            }
        }
    }

    bool isValid(std::string& str) {
        int left = 0, right = 0;
        for (char ch : str) {
            if (ch == '(') {
                ++left;
            } else if (ch == ')') {
                if (left > 0) {
                    --left;
                } else {
                    return false;
                }
            }
        }
        return left == 0;
    }
};

class Solution0 {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int lremove = 0;
        int rremove = 0;

        for (char c : s) {
            if (c == '(') {
                lremove++;
            } else if (c == ')') {
                if (lremove == 0) {
                    rremove++;
                } else {
                    lremove--;
                }
            }
        }
        helper(s, 0, lremove, rremove);
        return res;
    }

    void helper(string str, int start, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (isValid(str)) {
                res.push_back(str);
            }
            return;
        }
        for (int i = start; i < str.size(); i++) {
            if (i != start && str[i] == str[i - 1]) {
                continue;
            }
            // 如果剩余的字符无法满足去掉的数量要求，直接返回
            if (lremove + rremove > str.size() - i) {
                return;
            } 
            // 尝试去掉一个左括号
            if (lremove > 0 && str[i] == '(') {
                helper(str.substr(0, i) + str.substr(i + 1), i, lremove - 1, rremove);
            }
            // 尝试去掉一个右括号
            if (rremove > 0 && str[i] == ')') {
                helper(str.substr(0, i) + str.substr(i + 1), i, lremove, rremove - 1);
            }
        }
    }

    inline bool isValid(const string & str) {
        int cnt = 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                cnt++;
            } else if (str[i] == ')') {
                cnt--;
                if (cnt < 0) {
                    return false;
                }
            }
        }

        return cnt == 0;
    }
};

// @lc code=end

