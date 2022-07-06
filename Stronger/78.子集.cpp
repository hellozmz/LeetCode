/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode.cn/problems/subsets/description/
 *
 * algorithms
 * Medium (80.62%)
 * Likes:    1695
 * Dislikes: 0
 * Total Accepted:    474.7K
 * Total Submissions: 588.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * nums 中的所有元素 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets0(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        bt(nums, result, item, 0);
        return result;
    }

    void bt(const vector<int>& nums, std::vector<std::vector<int>> &result, std::vector<int> item, int idx) {
        if (idx == nums.size()) {
            result.emplace_back(item);
            return;
        }
        item.push_back(nums[idx]);
        // 深度递归
        bt(nums, result, item, idx + 1);
        item.pop_back();
        // 跳过当前元素
        bt(nums, result, item, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int len = nums.size();
        std::vector<int> item;
        for (int l = 0; l < (1 << len); ++l) {
            item.clear();
            for (int i = 0; i < len; ++i) {
                if (l & (1 << i)) {
                    item.push_back(nums[i]);
                }
            }
            result.emplace_back(item);
        }
        return result;
    }
};
// @lc code=end

