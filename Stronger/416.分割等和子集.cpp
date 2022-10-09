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
 * 给你一个 只包含正整数 的 非空 数组 nums
 * 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
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
#include "header.hpp"

// @lc code=start
class Solution {
public:
    bool result = false;
    /**
     * @brief 回溯法(Time Limit Exceeded)，约等于暴力法
     *
     * @param nums
     * @return true
     * @return false
     */
    bool canPartition0(vector<int>& nums) {
        int len = nums.size();
        int all = accumulate(nums.begin(), nums.end(), 0);
        if (all % 2) { return false; }
        int mid = all / 2;
        vector<int> path;
        bt(nums, path, mid, 0, 0);
        return result;
    }

    void bt(vector<int>& nums, vector<int>& path, const int mid, int startIndex,
            int currSum) {
        if (result) { return; }
        // int currSum = accumulate(path.begin(), path.end(), 0);
        if (currSum == mid) {
            result = true;
            // for (auto v : path) {
            //     cout << v << " ";
            // }
            // cout << endl;
            return;
        }
        if (currSum > mid) { return; }

        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            bt(nums, path, mid, i + 1, currSum + nums[i]);
            path.pop_back();
        }
    }

    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) { return true; }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) { return false; }
        int mid = sum / 2;
        vector<vector<int>> dp(len + 1, vector<int>(mid + 1, 0));
        for (int i = 0; i < len; ++i) {
            if (nums[i] > mid) {
                return false;
            } else if (nums[i] == mid) {
                return true;
            }
            // dp[0][nums[i]] = 1;
        }
        // dp[0][nums[0]] = 1;
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= mid; ++j) {
                if (j - nums[i - 1] > 0) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                } else if (j - nums[i - 1] == 0) {
                    dp[i][j] = nums[i - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }

                if (j == mid && dp[i][j]) {
                    return true;
                }
            }
        }
        // for (auto& v : dp) {
        //     for (auto i : v) { cout << i << " "; }
        //     cout << endl;
        // }
        // cout << endl;
        return false;
    }
};
// @lc code=end
