/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 *
 * https://leetcode-cn.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (57.05%)
 * Likes:    187
 * Dislikes: 0
 * Total Accepted:    6.8K
 * Total Submissions: 11.9K
 * Testcase Example:  '[3,1,5,8]'
 *
 * 有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 * 
 * 现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的
 * left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
 * 
 * 求所能获得硬币的最大数量。
 * 
 * 说明:
 * 
 * 
 * 你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 * 
 * 示例:
 * 
 * 输入: [3,1,5,8]
 * 输出: 167 
 * 解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
 * coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size + 2, vector<int>(size+2));
        vector<int> helper(size + 2, 1);

        for (int i = 1; i < size + 1; ++i) {
            helper[i] = nums[i-1];
        }

        for (int i = size + 1; i >= 0; --i) {
            for (int j = i + 1; j < size + 2; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    int sum = helper[i] * helper[k] * helper[j];
                    dp[i][j] = std::max(sum + dp[i][k] + dp[k][j], dp[i][j]);
                }
            }
        }

        // for (int i = 0; i < size + 2; ++i) {
        //     for (int j = 0; j < size + 2; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        return dp[0][size+1];
    }
};
// @lc code=end
