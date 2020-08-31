/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (60.32%)
 * Likes:    251
 * Dislikes: 0
 * Total Accepted:    46.3K
 * Total Submissions: 76.8K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, std::vector<std::string>> container;
        if (strs.empty()) {
            return result;
        }

        for (auto elem : strs) {
            auto tmp = elem;
            std::sort(tmp.begin(), tmp.end());
            if (container.count(tmp) <= 0) {
                std::vector<std::string> t;
                t.push_back(elem);
                container[tmp] = t;
            } else {
                container[tmp].push_back(elem);
            }
        }

        for (auto elem : container) {
            // std::cout << typeid(elem.second).name() << std::endl;
            result.emplace_back(elem.second);
        }

        return result;
    }
};
// @lc code=end

