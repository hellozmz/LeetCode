/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
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
};
// @lc code=end

