/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 *
 * https://leetcode.cn/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (52.96%)
 * Likes:    697
 * Dislikes: 0
 * Total Accepted:    116.6K
 * Total Submissions: 220.2K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
 * 
 * 题目数据保证答案符合 32 位整数范围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3], target = 4
 * 输出：7
 * 解释：
 * 所有可能的组合为：
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 请注意，顺序不同的序列被视作不同的组合。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [9], target = 3
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * nums 中的所有元素 互不相同
 * 1 
 * 
 * 
 * 
 * 
 * 进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief 区分顺序的时候，需要将动态规划二维遍历顺序变过来
     * 
     * @param nums 
     * @param target 
     * @return int 
     */
    int combinationSum40(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> dp(target + 1, 0);

        // init
        dp[0] = 1;

        // dp
        for (int i = 0; i <= target; ++i) {
            for (int j = 0; j < len; ++j) {
                dp[i] = dp[i];
                int num = nums[j];
                if (i >= num && dp[i] < INT_MAX - dp[i - num]) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }


    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};
// @lc code=end

