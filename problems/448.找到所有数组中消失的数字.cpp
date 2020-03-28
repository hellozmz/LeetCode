/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (55.65%)
 * Likes:    264
 * Dislikes: 0
 * Total Accepted:    24.2K
 * Total Submissions: 43.4K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
 * 
 * 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
 * 
 * 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * 
 * 输出:
 * [5,6]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::vector<int> appear_once_time;
        int size = nums.size();
        if (size == 0) {
            return appear_once_time;
        }
        for (int i=0; i <size; ++i) {
            int pos = nums[i] - 1;
            while ((pos >= 0) && (pos < size)) {
                int tmp_pos = nums[pos] - 1;
                nums[pos] = 0;
                pos = tmp_pos;
            }
        }
        for (int i=0; i<size; ++i) {
            // std::cout << nums[i] << ',';
            if (nums[i] != 0) {
                appear_once_time.push_back(i+1);
            }
        }

        return appear_once_time;
    }
};
// @lc code=end

