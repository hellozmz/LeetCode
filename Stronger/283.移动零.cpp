/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (64.04%)
 * Likes:    1361
 * Dislikes: 0
 * Total Accepted:    574.9K
 * Total Submissions: 897.8K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 
 * 
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int slow = 0, fast = 0;
        while (fast < len) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast++];
            } else {
                ++fast;
            }
        }
        while (slow < len) {
            nums[slow++] = 0;
        }
    }
};
// @lc code=end

