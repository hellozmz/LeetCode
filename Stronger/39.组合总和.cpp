/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode.cn/problems/combination-sum/description/
 *
 * algorithms
 * Medium (72.73%)
 * Likes:    2042
 * Dislikes: 0
 * Total Accepted:    540.2K
 * Total Submissions: 742.8K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给你一个 无重复元素 的整数数组 candidates
 * 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的
 * 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
 *
 * candidates 中的 同一个 数字可以 无限制重复被选取
 * 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
 *
 * 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：candidates = [2,3,6,7], target = 7
 * 输出：[[2,2,3],[7]]
 * 解释：
 * 2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
 * 7 也是一个候选， 7 = 7 。
 * 仅有这两种组合。
 *
 * 示例 2：
 *
 *
 * 输入: candidates = [2,3,5], target = 8
 * 输出: [[2,2,2,2],[2,3,3],[3,5]]
 *
 * 示例 3：
 *
 *
 * 输入: candidates = [2], target = 1
 * 输出: []
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * candidate 中的每个元素都 互不相同
 * 1 <= target <= 500
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum0(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        if (candidates.empty()) { return result; }
        std::sort(candidates.begin(), candidates.end());
        vector<int> item;
        bt(candidates, target, result, 0, item);
        return result;
    }

    void bt(const std::vector<int>& candi, int target,
            std::vector<std::vector<int>>& result, int idx,
            std::vector<int>& item) {
        // 当到达输入的长度了，说明所有数据都已经遍历完毕
        if (idx == candi.size()) { return; }
        // 当目标为0，说明得到结果了
        if (target == 0) {
            result.emplace_back(item);
            return;
        }
        // 跳过当前的数据，直接跳到下一个
        bt(candi, target, result, idx + 1, item);
        // 重复的去填充该数据
        if (target - candi[idx] >= 0) {
            item.push_back(candi[idx]);
            bt(candi, target - candi[idx], result, idx, item);
            item.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        btNew(result, path, candidates, target, 0);
        return result;
    }

    void btNew(vector<vector<int>>& result, vector<int>& path,
               vector<int>& candidates, int target, int startIndex) {
        if (target == 0) {
            result.emplace_back(path);
            return;
        }

        if (target < 0) { return; }

        for (int i = startIndex; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            btNew(result, path, candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
};
// @lc code=end
