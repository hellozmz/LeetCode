/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.36%)
 * Likes:    1130
 * Dislikes: 0
 * Total Accepted:    356.2K
 * Total Submissions: 590.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 *
 * 注意：解集不能包含重复的组合。 
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 * 示例 2:
 *
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(candidates.size(), false);        // 很重要，默认树枝中没有用过
        sort(candidates.begin(), candidates.end());
        bt(result, path, candidates, target, 0, used);
        // for (auto& vec : result) { sort(vec.begin(), vec.end()); }
        // set<vector<int>> r(result.begin(), result.end());
        // result.assign(r.begin(), r.end());
        return result;
    }

    void bt(vector<vector<int>>& result, vector<int>& path,
            vector<int>& candidates, int target, int startIndex,
            vector<bool>& used) {
        if (target == 0) {
            result.emplace_back(path);
            return;
        }

        for (int i = startIndex;
             i < candidates.size() && target - candidates[i] >= 0; ++i) {
            // used == true，树枝中有使用过
            // used == false，层中有使用过
            if (i > 0 && candidates[i] == candidates[i - 1] &&
                used[i - 1] == false) {
                continue;
            }
            used[i] = true;
            path.push_back(candidates[i]);
            bt(result, path, candidates, target - candidates[i], i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
};
// @lc code=end
