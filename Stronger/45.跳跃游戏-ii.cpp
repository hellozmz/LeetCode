/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode.cn/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (45.16%)
 * Likes:    1825
 * Dislikes: 0
 * Total Accepted:    407.9K
 * Total Submissions: 903.1K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
 *
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 *
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 *
 * 假设你总是可以到达数组的最后一个位置。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1
 * 0
 *
 *
 */
#include "header.hpp"

// @lc code=start
class Solution {
public:
/**
 * @brief 贪心的方法思路有，但是不够细致，没有想清楚更新步数的方法。
 * 需要在当前已经到达了最远的距离才去更新步数
 * 
 * @param nums 
 * @return int 
 */
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return 0;
        }
        int maxIndex = 0;
        int minStep = 0;
        int curMaxDis = 0;
        for (int i = 0; i < len; ++i) {
            if (i + nums[i] > maxIndex) {
                maxIndex = i + nums[i];
            }
            if (i == curMaxDis) {
                curMaxDis = maxIndex;
                ++minStep;
            }
            if (curMaxDis >= len - 1) {
                return minStep;
            }
        }
        return minStep;
    }
};
// @lc code=end
