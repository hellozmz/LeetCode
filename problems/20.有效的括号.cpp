/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    std::map<char, char> char_map{
        {')', '('},
        {']', '['},
        {'}', '{'},
    };
    bool isValid(string s) {
        if (s.size() == 0)  return true;
        std::stack<char> st;
        for (int i=0; i<s.size(); ++i) {
            char cur_char = s[i];
            if (char_map.find(cur_char) == char_map.end()) {
                st.push(cur_char);
            } else {
                if (!st.empty() && (st.top() == char_map.at(cur_char))) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.size()==0 ? true : false;
    }
};
// @lc code=end

