/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (34.07%)
 * Likes:    4134
 * Dislikes: 0
 * Total Accepted:    744.8K
 * Total Submissions: 2.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int len = nums.size();
        if (len < 3) {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums[len - 1] < 0) {
            return result;
        }
        if (nums[0] == 0 && nums[len - 1] == 0) {
            result.push_back({0, 0, 0});
            return result;
        }
        for (int first = 0; first < len - 2; ++first) {
            if (nums[first] > 0) {
                return result;
            }
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int third = len - 1;
            int second = first + 1;
            while (second < third) {
                if (nums[first] + nums[second] + nums[third] == 0) {
                    result.push_back({nums[first], nums[second], nums[third]});
                    while (second < third && nums[second] == nums[second + 1]) {
                        ++second;
                    }
                    ++second;
                    while (second < third && nums[third] == nums[third - 1]) {
                        --third;
                    }
                    --third;
                } else if (nums[first] + nums[second] + nums[third] > 0) {
                    --third;
                } else {
                    ++second;
                }
            }
        }
        return result;
    }
};
// @lc code=end

