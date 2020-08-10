/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (42.86%)
 * Likes:    175
 * Dislikes: 0
 * Total Accepted:    15.5K
 * Total Submissions: 36.1K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或
 * -中选择一个符号添加在前面。
 * 
 * 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 * 
 * 示例 1:
 * 
 * 输入: nums: [1, 1, 1, 1, 1], S: 3
 * 输出: 5
 * 解释: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * 一共有5种方法让最终目标和为3。
 * 
 * 
 * 注意:
 * 
 * 
 * 数组非空，且长度不会超过20。
 * 初始的数组的和不会超过1000。
 * 保证返回的最终结果能被32位整数存下。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays1(vector<int>& nums, int S) {
        return dfs(nums, S, 0);
    }

    // 下面的uint是细节，要不然target数据容易越界
    int dfs(std::vector<int>& nums, uint target, int left) {
        if (left >= nums.size()) {
            if (target == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        int ans = dfs(nums, target - nums[left], left + 1);
        ans += dfs(nums, target + nums[left], left + 1);

        return ans;
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }

        if (S > sum || S < -1 * sum) {
            return 0;
        }

        int result = 0;
        // 因为和最大为1000，所以所有数字都为负最小为-1000，因此可以让每次计算的结果+1000，
        // 这样所有结果就都是正数了
        std::vector<std::vector<int>> dp(len, std::vector<int>(2*sum+2000+1, 0));
        ++dp[0][2000 + nums[0]];
        ++dp[0][2000 - nums[0]];
        for (int i = 1; i < len; ++i) {
            for (int j = 2000 - sum; j <= sum + 2000; ++j) {
                if (dp[i-1][j - nums[i]]) {
                    dp[i][j] += dp[i-1][j - nums[i]];
                }
                if (dp[i-1][j + nums[i]]) {
                    dp[i][j] += dp[i-1][j + nums[i]];
                }
            }
        }
        return dp[len-1][S+2000];
    }
};
// @lc code=end

