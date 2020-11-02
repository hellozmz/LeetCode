/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (44.42%)
 * Likes:    479
 * Dislikes: 0
 * Total Accepted:    94.3K
 * Total Submissions: 212.3K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续
 * 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int left = 0, right = 0;
        int len = INT_MAX, sum = 0;
        while (right < size) {
            sum += nums[right];
            while (sum >= s) {
                len = min(len, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            ++right;
            // cout << "left=" << left << ", right=" << right << ", len=" << len << ", sum=" << sum << endl;
        }
        return len == INT_MAX ? 0 : len;
    }
};
// @lc code=end


