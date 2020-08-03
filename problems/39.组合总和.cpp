/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (68.04%)
 * Likes:    508
 * Dislikes: 0
 * Total Accepted:    58.6K
 * Total Submissions: 86.2K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    void backtrace(std::vector<std::vector<int>> &result, std::vector<int> &path, int first,
                   vector<int>& candidates, int target, int sum) {
        if (sum > target) {
            return;
        } else if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = first; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            backtrace(result, path, i, candidates, target, sum + candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        backtrace(result, path, 0, candidates, target, 0);
        return result;
    }
};
// @lc code=end

