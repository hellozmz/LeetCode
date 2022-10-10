/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode.cn/problems/target-sum/description/
 *
 * algorithms
 * Medium (49.09%)
 * Likes:    1395
 * Dislikes: 0
 * Total Accepted:    284.8K
 * Total Submissions: 580.1K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 target 。
 * 
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 
 * 
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 
 * 
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], target = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 0 
 * -1000 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief 回溯法
     * 
     * @param nums 
     * @param target 
     * @return int 
     */
    int findTargetSumWays0(vector<int>& nums, int target) {
        int result = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (((sum - target) & 1) || (abs(target) > sum)) {
            return 0;
        }
        bt(nums, target, 0, 0, result);
        return result;
    }

    void bt(vector<int>& nums, int target, int startIndex, int sum, int& result) {
        if (startIndex >= nums.size()) {
            if (sum == target && startIndex != 0) {
                ++result;
            }
            return;
        }
        // 为什么不需要for循环了呢，因为都被自己手动的罗列出来了，切记
        bt(nums, target, startIndex+1, sum + nums[startIndex], result);
        bt(nums, target, startIndex+1, sum - nums[startIndex], result);
    }

    /**
     * @brief 动态规划
     * 
     * @param nums 
     * @param target 
     * @return int 
     */
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (((sum - target) & 1) || (abs(target) > sum)) {
            return 0;
        }
        int neg = (sum - target) / 2;
        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int>(neg + 1, 0));

        // init
        dp[0][0] = 1;

        // dp
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j <= neg; ++j) {
                int num = nums[i - 1];
                if (j - num >= 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len][neg];
    }
};
// @lc code=end

