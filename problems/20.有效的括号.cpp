/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0)  return true;
        std::stack<char> st;
        for (int i=0; i<s.size(); ++i) {
            // std::cout << "s[" << i << "]=" << s[i] << endl;
            if (s[i] == '(' ||
                s[i] == '{' ||
                s[i] == '[') {
                st.push(s[i]);
                // std::cout << st.size() << std::endl;
            } else if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    // std::cout << st.top() << endl;
                    st.pop();
                } else {
                    // std::cout << "()" << std::endl;
                    return false;
                }
            } else if (s[i] == '}') {
                if (!st.empty() && st.top() == '{') {
                    // std::cout << st.top() << endl;
                    st.pop();
                } else {
                    // std::cout << "{}" << std::endl;
                    return false;
                }
            } else if (s[i] == ']') {
                if (!st.empty() && st.top() == '[') {
                    // std::cout << st.top() << endl;
                    st.pop();
                } else {
                    // std::cout << "[]" << std::endl;
                    return false;
                }
            }
        }

        // std::cout << "st.size()=" << st.size() << std::endl;
        // while (st.size() != 0) {
        //     std::cout << st.top() << std::endl;
        //     st.pop();
        // }
        return st.size()==0 ? true : false;
    }
};
// @lc code=end

