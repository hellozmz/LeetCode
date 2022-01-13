/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 *
 * https://leetcode-cn.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (55.49%)
 * Likes:    992
 * Dislikes: 0
 * Total Accepted:    135.9K
 * Total Submissions: 244.8K
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
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "3[a]2[bc]"
 * 输出："aaabcbc"
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "3[a2[c]]"
 * 输出："accaccacc"
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "2[abc]3[cd]ef"
 * 输出："abcabccdcdcdef"
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "abc3[cd]xyz"
 * 输出："abccdcdcdxyz"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        int len = s.size();
        if (len == 0) {
            return s;
        }
        std::string result = "";
        std::stack<std::string> stk;
        for (int i = 0; i < len; ++i) {
            std::cout << "char = " << s[i] << std::endl;
            if (s[i] == ']') {
                std::cout << "] = " << s[i] << std::endl;
                std::string str = stk.top();
                stk.pop();
                // stk.pop();      // [, 不存储这个字符了
                // 处理"["
                while (stk.top() != "[") {
                    str = stk.top() + str;
                    stk.pop();
                }
                stk.pop();
                std::cout << "num = " << stk.top() << std::endl;
                int num = std::stoi(stk.top());
                stk.pop();
                std::string tmp_str;
                while (num > 0) {
                    tmp_str += str;
                    --num;
                }
                stk.push(tmp_str);
                std::cout << "stk.top() = " << stk.top() << std::endl;
            } else if (s[i] == '[') {
                std::cout << "[ = " << s[i] << std::endl;
                stk.push("[");
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {        // 是数字
                std::cout << "num = " << s[i] << std::endl;
                std::string num = get_num(s, i);
                stk.push(num);
                continue;
            } else {            // 是字符串
                std::cout << "str = " << s[i] << std::endl;
                std::string str = get_string(s, i);
                stk.push(str);
                continue;
            }
        }

        while (!stk.empty()) {
            std::string top = stk.top();
            result = top + result;
            stk.pop();
        }
        return result;
    }

    std::string get_num(string s, int &i) {
        std::string result;
        for (; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                result += s[i];
            } else {
                --i;
                break;
            }
        }
        
        std::cout << "num = " << result << std::endl;
        return result;
    }

    std::string get_string(string s, int &i) {
        std::string result;
        for (; i < s.size(); ++i) {
            if (s[i] == '[' || s[i] == ']' || (s[i] >= '0' && s[i] <= '9')) {
                --i;
                break;
            }
            result += s[i];
        }
        std::cout << "string = " << result << std::endl;
        return result;
    }
};
// @lc code=end

/**
 * @brief 
 * class Solution {
public:
    string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string getString(vector <string> &v) {
        string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        vector <string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {
                // 获取一个字母并进栈
                stk.push_back(string(1, s[ptr++])); 
            } else {
                ++ptr;
                vector <string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前 sub 对应的字符串应该出现的次数
                int repTime = stoi(stk.back()); 
                stk.pop_back();
                string t, o = getString(sub);
                // 构造字符串
                while (repTime--) t += o; 
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }

        return getString(stk);
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/decode-string/solution/zi-fu-chuan-jie-ma-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
