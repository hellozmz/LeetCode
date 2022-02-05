/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (51.14%)
 * Likes:    1119
 * Dislikes: 0
 * Total Accepted:    205.6K
 * Total Submissions: 401.8K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int mid = sum / 2;
        int len = nums.size();
        std::vector<std::vector<bool>> dp(len + 1, std::vector<bool>(mid + 1, false));
        dp[0][0] = 1;
        for (int i = 1; i <= len; ++i) {
            int num = nums[i - 1];
            for (int j = 0; j <= mid; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j >= num) {
                    dp[i][j] = (dp[i][j] || dp[i - 1][j - num]);
                }
                if (dp[i][mid]) {
                    return true;
                }
            }
        }
        // std::cout << std::endl;
        // for (auto &vec : dp) {
        //     for (auto i : vec) {
        //         std::cout << i << " ";
        //     }
        //     std::cout << std::endl;
        // }
        return dp[len][mid];
    }
};
// @lc code=end

