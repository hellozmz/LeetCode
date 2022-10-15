/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode.cn/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (43.92%)
 * Likes:    1175
 * Dislikes: 0
 * Total Accepted:    289K
 * Total Submissions: 658K
 * Testcase Example:  '[2,3,2]'
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
 * ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return nums[0];
        }
        int first = robRange(nums, 0, len - 2);
        int second = robRange(nums, 1, len - 1);
        return max(first, second);
    }

    /**
     * @brief rob
     * 
     * @param nums 数组
     * @param begin 起始包含
     * @param end 终止包含
     * @return int rob max
     */
    int robRange(vector<int>& nums, int begin, int end) {
        int len = end - begin + 1;

        // vec
        vector<int> dp(len + 1);

        // init
        dp[0] = 0;
        dp[1] = nums[begin];

        // dp，这里要区分好，下标是对dp有用还是对nums有用。这里使用dp下标
        for (int i = 2; i <= len; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[begin + i - 1]);
        }

        return dp[len];
    }
};
// @lc code=end

