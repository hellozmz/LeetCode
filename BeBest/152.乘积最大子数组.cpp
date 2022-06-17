/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (42.33%)
 * Likes:    1466
 * Dislikes: 0
 * Total Accepted:    215.6K
 * Total Submissions: 509.2K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
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
 * int maxProduct(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    int currentMax = nums[0];
    int currentMin = nums[0];
    int maxProduct = nums[0];
    
    for(size_t i = 1; i < nums.size(); ++i) {
        //calculate our new possibilities for this round
        int p1 = currentMax * nums[i];
        int p2 = currentMin * nums[i];
        //our currentMax will be either p1 or p2 or nums[i] whichever is bigger
        currentMax = max(nums[i], max(p1, p2));
        //our currentMin will be either p1 or p2 or nums[i] whichever is smaller
        currentMin = min(nums[i], min(p1, p2));
        //our maxProduct will be our currentMax or our maxProduct, whichever is bigger.
        maxProduct = currentMax > maxProduct ? currentMax : maxProduct;
    }
    return maxProduct;
}
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int max = nums[0], min = nums[0], ans = nums[0];
        for (int i = 1; i < len; ++i) {
            int x = max;
            max = std::max(nums[i] * max, std::max(nums[i] * min, nums[i]));
            min = std::min(nums[i] * min, std::min(nums[i] * x, nums[i]));
            ans = std::max(max, ans);
        }
        return ans;
    }

    int maxProduct0(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int max = nums[0], min = nums[0], ans = nums[0];
        for (int i = 1; i < len; ++i) {
            int x = max, n = min;
            max = std::max(max * nums[i], std::max(nums[i], nums[i] * n));
            min = std::min(min * nums[i], std::min(nums[i], nums[i] * x));
            ans = std::max(ans, max);
        }
        return ans;
    }
};
// @lc code=end

