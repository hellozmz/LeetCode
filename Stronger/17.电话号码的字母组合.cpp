/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (57.82%)
 * Likes:    1980
 * Dislikes: 0
 * Total Accepted:    515.9K
 * Total Submissions: 892.3K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }
        std::unordered_map<char, std::string> mapping{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        std::string tmp("");
        bt(digits, mapping, 0, tmp, result);
        return result;
    }

    void bt(const string &digits, const std::unordered_map<char, std::string> &mapping, int index, std::string& tmp, std::vector<std::string> &result) {
        if (digits.size() == index) {
            result.push_back(tmp);
        } else {
            char num = digits[index];
            // std::cout << "num " << num << std::endl;
            const std::string &letters = mapping.at(num);
            for (const char ch : letters) {
                tmp.push_back(ch);
                bt(digits, mapping, index+1, tmp, result);
                tmp.pop_back();
            }
        }
    }
};
// @lc code=end

