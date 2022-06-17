/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (49.12%)
 * Likes:    1027
 * Dislikes: 0
 * Total Accepted:    176.7K
 * Total Submissions: 359.6K
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto v : nums) {
            sum += v;
        }
        int diff = sum - target;
        if (diff < 0) {
            return 0;
        }
        if (diff % 2 != 0) {
            return 0;
        }
        int neg = diff / 2;
        int len = nums.size();
        std::vector<std::vector<int>> dp(len + 1, std::vector<int>(neg + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= len; ++i) {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; ++j) {
                dp[i][j] = dp[i-1][j];
                if (num <= j) {
                    dp[i][j] += dp[i-1][j-num];
                }
            }
        }
        for (auto &vec : dp) {
            for (auto &i : vec) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
        return dp[len][neg];
    }

    int findTargetSumWays0(vector<int>& nums, int target) {
        int sum = 0;
        for (auto &num : nums) {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0) {
            return 0;
        }
        if (diff % 2 != 0) {
            return 0;
        }
        int neg = diff / 2;
        int len = nums.size();
        std::vector<std::vector<int>> dp(len + 1, std::vector<int>(neg + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= len; ++i) {
            int num = nums[i - 1];      // 上一个数（两个数组的索引是不相同的）
            for (int j = 0; j <= neg; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j >= num) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-num];
                }
            }
        }
        // for (auto &vec : dp) {
        //     for (auto &i : vec) {
        //         std::cout << i << " ";
        //     }
        //     std::cout << std::endl;
        // }
        return dp[len][neg];
    }
};
// @lc code=end

