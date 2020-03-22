/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (61.25%)
 * Likes:    424
 * Dislikes: 0
 * Total Accepted:    103.2K
 * Total Submissions: 168.4K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 如果能使用判断相等解决问题，就尽量不要使用<=等符号替代
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // if (nums.size() == 0) {
        //     return 0;
        // }
        int major_num = nums[0];
        int major_count = 1;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] == major_num) {
                ++major_count;
                // std::cout << major_num << " is " << major_count << " times" << std::endl;
            } else {
                --major_count;
                if (major_count == 0) { // Your runtime beats 100 % of cpp submissions
                // if (major_count <= 0) { // Your runtime beats 63.77 % of cpp submissions
                    major_num = nums[i];
                    major_count = 1;
                    // std::cout << "change majot, " << major_num << " is " << major_count << " times" << std::endl;
                }
            }
        }
        return major_num;
    }
};
// @lc code=end

