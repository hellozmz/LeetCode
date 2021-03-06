/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.23%)
 * Likes:    1748
 * Dislikes: 0
 * Total Accepted:    148.4K
 * Total Submissions: 588.2K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        if (size < 3) {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        for (int first = 0; first < size; ++first) {
            if (first != 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int third = size - 1;
            for (int second = first + 1; second < size; ++second) {
                if (second != first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                while (nums[first] + nums[second] + nums[third] > 0 && third > second) {
                    --third;
                }
                if (second >= third) {
                    break;
                }

                if (nums[first] + nums[second] + nums[third] == 0) {
                    result.push_back({nums[first], nums[second], nums[third]});
                } 
            }
        }
        return result;
    }
};
// @lc code=end
