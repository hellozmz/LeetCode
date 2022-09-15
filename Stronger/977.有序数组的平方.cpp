/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (68.96%)
 * Likes:    619
 * Dislikes: 0
 * Total Accepted:    394.1K
 * Total Submissions: 571.9K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 10^4
 * -10^4 
 * nums 已按 非递减顺序 排序
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        std::vector<int> result(len);
        int s = 0, e = len - 1;
        int index = e;
        while (s <= e) {
            if (std::abs(nums[s]) < std::abs(nums[e])) {
                result[index--] = nums[e] * nums[e];
                --e;
            } else {
                result[index--] = nums[s] * nums[s];
                ++s;
            }
        }
        return result;
    }

    vector<int> sortedSquares0(vector<int>& nums) {
        int len = nums.size();
        int left = -1, right = len;
        for (int i = 0; i < len; ++i) {
            if (nums[i] < 0) {
                left = i;
            }
        }
        for (int i = len - 1; i >= 0; --i) {
            if (nums[i] >= 0) {
                right = i;
            }
        }
        std::vector<int> result;
        while (left >= 0 && right < len) {
            if (std::abs(nums[left]) < std::abs(nums[right])) {
                result.push_back(nums[left] * nums[left]);
                --left;
            } else {
                result.push_back(nums[right] * nums[right]);
                ++right;
            }
        }
        while (left >= 0) {
            result.push_back(nums[left] * nums[left]);
            --left;
        }
        while (right < len) {
            result.push_back(nums[right] * nums[right]);
            ++right;
        }
        return result;
    }
};
// @lc code=end

