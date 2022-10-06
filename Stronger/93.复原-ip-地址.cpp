/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode.cn/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (57.28%)
 * Likes:    1041
 * Dislikes: 0
 * Total Accepted:    277.8K
 * Total Submissions: 484.7K
 * Testcase Example:  '"25525511135"'
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导
 * 0），整数之间用 '.' 分隔。
 *
 *
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是
 * "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
 *
 *
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP
 * 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s
 * 中的任何数字。你可以按 任何 顺序返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 20
 * s 仅由数字组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        if (s.size() < 4 || s.size() > 12) return result; // 算是剪枝了
        bt(result, path, s, 0);
        return result;
    }

    void bt(vector<string>& result, vector<string>& path, string& input,
            int startIndex) {
        if (startIndex == input.size()) {
            if (path.size() == 4) {
                if (isValid(path)) {
                    result.emplace_back(convert(path));
                    return;
                }
            }
        }

        if (path.size() >= 4) {
            return;
        }

        for (int i = startIndex; i < input.size() && i - startIndex <= 3; ++i) {
            path.emplace_back(input.substr(startIndex, i - startIndex + 1));
            bt(result, path, input, i + 1);
            path.pop_back();
        }
    }

    bool isValid(vector<string>& path) {
        for (auto& item : path) {
            if (item.size() > 1 && item[0] == '0' || item.size() > 3) {
                return false;
            }
            int value = stoi(item);
            if (value > 255) {
                return false;
            }
        }
        return true;
    }

    string convert(vector<string>& path) {
        string result("");
        for (auto& item : path) {
            if (result.empty()) {
                result = item;
            } else {
                result += ("." + item);
            }
        }
        return result;
    }
};
// @lc code=end
