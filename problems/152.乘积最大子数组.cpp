/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (36.73%)
 * Likes:    363
 * Dislikes: 0
 * Total Accepted:    32.2K
 * Total Submissions: 87.5K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct0(vector<int>& nums) {
        int result = nums[0];
        int len = nums.size();
        std::vector<int> max(len, 0);
        std::vector<int> min(len, 0);
        max[0] = nums[0];
        min[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            max[i] = std::max({max[i-1] * nums[i], min[i-1] * nums[i], nums[i]});
            min[i] = std::min({max[i-1] * nums[i], min[i-1] * nums[i], nums[i]});
            result = std::max({max[i], result});
        }
        return result;
    }

    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int max = nums[0];
        int min = nums[0];
        int result = max;
        for (int i = 1; i < len; ++i) {
            int tmp_max = max;
            int tmp_min = min;
            max = std::max({tmp_max * nums[i], tmp_min * nums[i], nums[i]});
            min = std::min({tmp_max * nums[i], tmp_min * nums[i], nums[i]});
            result = std::max({result, max});
        }
        return result;
    }
};
// @lc code=end

