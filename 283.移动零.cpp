/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 双指针的问题
        int length = nums.size();
        int left = 0, right = 0;
        while (right < length) {
            if (nums[right] != 0) {
                nums[left++] = nums[right];
            }
            ++right;
        }
        while (left < length) {
            nums[left++] = 0;
        }
    }
};
// @lc code=end

