/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

/**
 * @brief 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104

 * 
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief 贪心法
     * 
     * @param nums 
     * @return int 
     */
    int maxSubArray0(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return nums.back();
        }
        int max = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum > 0 && sum + nums[i] > 0) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            max = std::max(max, sum);
        }
        return max;
    }


    /**
     * @brief 动态规划
     * 
     * @param nums 
     * @return int 
     */
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums.back();
        }

        vector<int> dp(len + 1, INT_MIN);

        // init
        dp[0] = nums[0];
        int maxValue = dp[0];
    
        // dp
        for (int i = 1; i < len; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxValue = max(maxValue, dp[i]);
        }

        return maxValue;
    }
};
// @lc code=end

