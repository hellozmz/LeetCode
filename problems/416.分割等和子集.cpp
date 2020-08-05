/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (44.59%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    16.2K
 * Total Submissions: 36.2K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 注意:
 * 
 * 
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1, 5, 11, 5]
 * 
 * 输出: true
 * 
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 3, 5]
 * 
 * 输出: false
 * 
 * 解释: 数组不能分割成两个元素和相等的子集.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return false;
        }
        int sum = 0;
        int max = 0;
        for (auto elem : nums) {
            sum += elem;
            max = std::max(max, elem);
        }
        if (sum%2 != 0 || max * 2 > sum) {
            // std::cout << "max=" << max << ", sum=" << sum << std::endl;
            return false;
        }
        if (max * 2 == sum) {
            // return true;
        }
        int target = sum / 2;
        std::vector<std::vector<int>> dp(len, std::vector<int>(target+1, 0));

        // 为了后续
        // dp[0][0] = true;

        // todo: 需要压缩
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j <= target; ++j) {
                if (i == 0) {
                    dp[i][nums[i]] = true;
                    continue;
                }
                if (dp[i-1][j]) {
                    dp[i][j] = true;
                }
                if (j-nums[i] >= 0 && dp[i-1][j-nums[i]]) {
                    dp[i][j] = true;
                }
                if (j == target && dp[i][j]) {
                    return true;
                }
                // std::cout << dp[i][j] << " ";
            }
            // std::cout << std::endl;
        }
        return false;
    }
};
// @lc code=end

