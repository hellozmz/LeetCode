/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (73.68%)
 * Likes:    508
 * Dislikes: 0
 * Total Accepted:    72.1K
 * Total Submissions: 97.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        dfs(result, 0, nums);
        return result;
    }

    void dfs(std::vector<std::vector<int>>& result, int start,
             std::vector<int>& nums) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            // 先交换位置，然后再交换回来，实现全排列的逻辑
            std::swap(nums[i], nums[start]);
            dfs(result, start + 1, nums);
            std::swap(nums[start], nums[i]);
        }
    }
};
// @lc code=end

