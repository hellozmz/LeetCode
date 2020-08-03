/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (52.15%)
 * Likes:    558
 * Dislikes: 0
 * Total Accepted:    72.6K
 * Total Submissions: 139.1K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
private:
    std::vector<std::string> dict = {
        {"abc"},
        {"def"},
        {"ghi"},
        {"jkl"},
        {"mno"},
        {"pqrs"},
        {"tuv"},
        {"wxyz"}
    };

public:
    void backtrace(std::vector<std::string> &result, std::string &path,
                   int first, std::string &digits) {
        if (first == digits.size()) {
            result.push_back(path);
        }

        if (first < digits.size()) {
            for (int j = 0; j < dict[digits[first] - '2'].size(); ++j) {
                path.push_back(dict[digits[first] - '2'][j]);
                backtrace(result, path, first+1, digits);
                path.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }
        for (int i = 0; i < digits.size(); ++i) {
            if (digits[i] < '2' || digits[i] > '9') {
                return result;
            }
        }
        std::string path;
        backtrace(result, path, 0, digits);
        return result;
    }
};
// @lc code=end

