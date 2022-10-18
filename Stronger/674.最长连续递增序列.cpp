/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 *
 * https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/
 *
 * algorithms
 * Easy (54.29%)
 * Likes:    335
 * Dislikes: 0
 * Total Accepted:    158.6K
 * Total Submissions: 292.2K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
 * 
 * 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l ，都有 nums[i] < nums[i + 1] ，那么子序列
 * [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,5,4,7]
 * 输出：3
 * 解释：最长连续递增序列是 [1,3,5], 长度为3。
 * 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,2,2,2]
 * 输出：1
 * 解释：最长连续递增序列是 [2], 长度为1。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief 直接根据题意处理的方法
     * 
     * @param nums 
     * @return int 
     */
    int findLengthOfLCIS1(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        int maxLen = 1;
        int left = 0, right = 1;

        while (left < right && right < len) {
            if (nums[right - 1  ] < nums[right]) {
                maxLen = max(maxLen, right - left + 1);
                ++right;
            } else {
                left = right;
                ++right;
            }
        }

        return maxLen;
    }

    /**
     * @brief O(n^2)
     * 
     * @param nums 
     * @return int 
     */
    int findLengthOfLCIS2(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        int maxLen = 1;
        vector<int> dp(len, 1);

        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len - 1; ++j) {
                if (nums[j] < nums[j + 1]) {
                    maxLen = max(maxLen, j + 1 - i + 1);
                } else {
                    break;
                }
            }
        }

        return maxLen;
    }

    /**
     * @brief 
     * 
     * @param nums 
     * @return int 
     */
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        vector<int> dp(len, 1);
        dp[0] = 1;
        int maxLen = dp[0];

        for (int i = 1; i < len; ++i) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = max(dp[i], dp[i - 1] + 1);
                maxLen = max(maxLen, dp[i]);
            }
        }

        return maxLen;
    }
};
// @lc code=end

