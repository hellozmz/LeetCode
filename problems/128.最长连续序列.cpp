/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (47.40%)
 * Likes:    228
 * Dislikes: 0
 * Total Accepted:    23.8K
 * Total Submissions: 50.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 
 * 要求算法的时间复杂度为 O(n)。
 * 
 * 示例:
 * 
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> set(nums.begin(), nums.end());
        int max_length = 0;
        for (auto iter = set.begin(); iter != set.end(); ++iter) {
            int len = 1;
            // int cur = nums[i];
            int cur = *iter;
            while (iter != set.end() && cur < INT_MAX - 1 && set.count(++cur) > 0) {
                ++len;
                ++iter;
                // cout << cur - 1 << " ";
            }
            // cout << endl;
            max_length = std::max(len, max_length);
        }
        return max_length;
    }
};
// @lc code=end

