/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 *
 * https://leetcode-cn.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (48.17%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 31.7K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 * 
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 * 
 * 示例:
 * 
 * 
 * s = "3[a]2[bc]", 返回 "aaabcbc".
 * s = "3[a2[c]]", 返回 "accaccacc".
 * s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        std::stack<std::string> st;
        int size = s.size();
        if (size == 0) {
            return "";
        }
        for (int i = 0; i < size; ++i) {
            char cur = s[i];
            // std::cout << "do " << cur << std::endl;
            if (cur == '[') {
                st.push(std::string(1, cur));
            } else if (cur <= '9' && cur >= '0') {
                if (!st.empty() &&
                    (st.top()[0] <= '9' && st.top()[0] >= '0')) {
                    std::string top = st.top();
                    st.pop();
                    top += std::string(1, cur);
                    st.push(top);
                } else {
                    st.push(std::string(1, cur));
                }
            } else if (cur <= 'z' && cur >= 'a' || cur <= 'Z' && cur >= 'A') {
                if (!st.empty() &&
                    ((st.top()[0] <= 'z' && st.top()[0] >= 'a') ||
                    (st.top()[0] <= 'Z' && st.top()[0] >= 'A'))) {
                    std::string top = st.top();
                    st.pop();
                    top += std::string(1, cur);
                    st.push(top);
                } else {
                    st.push(std::string(1, cur));
                }
            } else if (cur == ']') {
                std::string str = st.top();
                st.pop();
                st.pop();   // 去掉'['
                int k = std::stoi(st.top());
                st.pop();
                std::string tmp;
                for (int j = 0; j < k; ++j) {
                    tmp += str;
                }
                if (!st.empty() &&
                    ((st.top()[0] <= 'z' && st.top()[0] >= 'a') ||
                    (st.top()[0] <= 'Z' && st.top()[0] >= 'A'))) {
                    std::string top = st.top();
                    st.pop();
                    top += tmp;
                    st.push(top);
                } else {
                    st.push(tmp);
                }
            }
        }
        return st.top();
    }
};
// @lc code=end

