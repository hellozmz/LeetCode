/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.21%)
 * Likes:    1155
 * Dislikes: 0
 * Total Accepted:    434.3K
 * Total Submissions: 562.6K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2：
 *
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        bt(result, path, 1, n, k);
        return result;
    }

    void bt(vector<vector<int>>& result, vector<int>& path, int begin, int end,
            int k) {
        if (path.size() == k) {
            result.emplace_back(path);
            return;
        }
        // 剪枝
        if (end - (k - path.size()) + 1 < begin) {
            return;
        }

        for (int i = begin; i <= end; ++i) {
            path.push_back(i);
            bt(result, path, i + 1, end, k);
            path.pop_back();
        }
    }
};
// @lc code=end
