/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 *
 * https://leetcode.cn/problems/ambiguous-coordinates/description/
 *
 * algorithms
 * Medium (50.56%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 14.8K
 * Testcase Example:  '"(123)"'
 *
 * 我们有一些二维坐标，如 "(1, 3)" 或 "(2,
 * 0.5)"，然后我们移除所有逗号，小数点和空格，得到一个字符串S。返回所有可能的原始字符串到一个列表中。
 * 
 * 原始的坐标表示法不会存在多余的零，所以不会出现类似于"00", "0.0", "0.00", "1.0", "001",
 * "00.01"或一些其他更小的数来表示坐标。此外，一个小数点前至少存在一个数，所以也不会出现“.1”形式的数字。
 * 
 * 最后返回的列表可以是任意顺序的。而且注意返回的两个数字中间（逗号之后）都有一个空格。
 * 
 * 
 * 
 * 
 * 示例 1:
 * 输入: "(123)"
 * 输出: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
 * 
 * 
 * 
 * 示例 2:
 * 输入: "(00011)"
 * 输出:  ["(0.001, 1)", "(0, 0.011)"]
 * 解释: 
 * 0.0, 00, 0001 或 00.01 是不被允许的。
 * 
 * 
 * 
 * 示例 3:
 * 输入: "(0123)"
 * 输出: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)",
 * "(0.12, 3)"]
 * 
 * 
 * 
 * 示例 4:
 * 输入: "(100)"
 * 输出: [(10, 0)]
 * 解释: 
 * 1.0 是不被允许的。
 * 
 * 
 * 
 * 
 * 提示: 
 * 
 * 
 * 4 <= S.length <= 12.
 * S[0] = "(", S[S.length - 1] = ")", 且字符串 S 中的其他元素都是数字。
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int len = s.size();
        vector<string> result;
        string path;
        bt(s, 0, result, path);
        return result;
    }

    void bt(string& s, int index, vector<string>& result, string& path) {
        if (index == s.size()) {
            result.emplace_back(path);
        }

        for (int i = 0; i < s.size(); ++i) {
            path.
            bt(s, i + 1, result, path);
            path.pop_back();
        }
    }
};
// @lc code=end

