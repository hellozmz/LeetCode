/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (33.72%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    16.3K
 * Total Submissions: 48.4K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 你找到的子数组应是最短的，请输出它的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [2, 6, 4, 8, 10, 9, 15]
 * 输出: 5
 * 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 说明 :
 * 
 * 
 * 输入的数组长度范围在 [1, 10,000]。
 * 输入的数组可能包含重复元素 ，所以升序的意思是<=。
 * 
 * 这道题目非常好，思路很赞，从前向后扫描一遍，找到第一个不满足升序的数字下标
 * 再从后向前扫描一遍，找到最后一个不满足升序的数字下标，求差值即可得出结果
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        if (size < 1) {
            return 0;
        }
        int min_num = nums[size-1];
        int max_num = nums[0];
        // std::vector<char> ordered_flag(size, 1);  // 1代表满足，0代表不满足

        int max_unorder_low_range = -1;
        int max_unorder_high_range = -1;
        for (int i=1; i<size; ++i) {
            if (nums[i] < max_num) {
                // ordered_flag[i] = 0;
                // std::cout << i << std::endl;
                if (max_unorder_low_range == -1) {
                    max_unorder_low_range = i;
                    max_unorder_high_range = i;
                }
                if (i > max_unorder_high_range) {
                    max_unorder_high_range = i;
                }
            } else {
                max_num = nums[i];
            }
        }

        int min_unorder_low_range = -1;
        int min_unorder_high_range = -1;
        for (int i=size-2; i>=0; --i) {
            if (nums[i] > min_num) {
                // ordered_flag[i] = 0;
                // std::cout << i << std::endl;
                if (min_unorder_high_range == -1) {
                    min_unorder_low_range = i;
                    min_unorder_high_range = i;
                }
                if (i < min_unorder_low_range) {
                    min_unorder_low_range = i;
                }
            } else {
                min_num = nums[i];
            }
        }

        int low_range = std::min({max_unorder_low_range, max_unorder_high_range,
                                min_unorder_low_range, min_unorder_high_range});
        int high_range = std::max({max_unorder_low_range, max_unorder_high_range,
                                min_unorder_low_range, min_unorder_high_range});
        if (high_range != low_range) {
            return high_range - low_range + 1;
        }
        return 0;
    }
};
// @lc code=end

