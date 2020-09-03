/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (76.12%)
 * Likes:    448
 * Dislikes: 0
 * Total Accepted:    56.3K
 * Total Submissions: 73.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    void backtrace(std::vector<std::vector<int>>& result, std::vector<int>& path,
            std::vector<int>& nums, int first, int size) {
        if (path.size() == size) {
            result.push_back(path);
        }

        // for (int i = 0; i < path.size(); ++i) {
        //     std::cout << path[i] << " ";
        // }
        // std::cout << std::endl;

        for (int i = first; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtrace(result, path, nums, i+1, size);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets0(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int len = nums.size();
        for (int target_len = 0; target_len <= len; ++target_len) { // 数组长度为0～len
            std::vector<int> path;
            backtrace(result, path, nums, 0, target_len);
        }
        return result;
    }

    std::vector<std::vector<int>> result; 
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> path;
        bt(nums, 0, path);
        return result;
    }

    void bt(const std::vector<int>& nums, int start, std::vector<int> path) {
        result.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            bt(nums, i+1, path);
            path.pop_back();
        }
    }
};
// @lc code=end
