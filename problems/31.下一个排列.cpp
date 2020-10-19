/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.57%)
 * Likes:    696
 * Dislikes: 0
 * Total Accepted:    94.3K
 * Total Submissions: 272.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void swap(vector<int>& nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

    void reverse(vector<int>& nums, int begin, int end) {
        for (int i = begin; i <= (begin + end) / 2; ++i) {
            swap(nums, i, end - (i - begin));
        }
    }

    void nextPermutation(vector<int>& nums) {
        // [1,3,2]

        int low_index = 0;      // 从后向前看，第一个乱序的索引位置
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                low_index = i;
                break;
            }
        }
        // cout << "low=" << nums[low_index] << endl;
        int high_index = low_index;
        for (int i = nums.size() - 1; i > low_index; --i) {
            if (nums[i] > nums[low_index]) {
                high_index = i;
                break;
            }
        }
        // cout << "high=" << nums[high_index] << endl;

        swap(nums, low_index, high_index);
        // for (auto i : nums) {
        //     cout << i << " ";
        // }
        // cout << endl;
        if (high_index != low_index) {
            reverse(nums, low_index + 1, nums.size() - 1);
        } else {
            reverse(nums, 0, nums.size() - 1);
        }
        
        // for (auto i : nums) {
        //     cout << i << " ";
        // }
        // cout << endl;
        return;
    }
};
// @lc code=end

