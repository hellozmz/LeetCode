/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (78.62%)
 * Likes:    2094
 * Dislikes: 0
 * Total Accepted:    655.2K
 * Total Submissions: 833.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int len = 0;
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        len = nums.size();
        bt(nums, result, 0);
        return result;
    }

    void bt(vector<int>& nums, std::vector<std::vector<int>> &result, int idx) {
        if (len == idx) {
            result.emplace_back(nums);
            return;
        }
        // 保证在数组中，左边的都是准备加入队列的，右边的是等待排序的（包括当前数据）
        for (int i = idx; i < len; ++i) {
            // 不断的去交换两个元素
            std::swap(nums[idx], nums[i]);
            bt(nums, result, idx+1);
            // 再回退回去
            std::swap(nums[idx], nums[i]);
        }
    }
};
// @lc code=end

