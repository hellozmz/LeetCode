/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (58.94%)
 * Likes:    482
 * Dislikes: 0
 * Total Accepted:    101.5K
 * Total Submissions: 172.1K
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
        if (len == 0 || len == 1) {
            return;
        }
        int i = 0;  // 记录插入数据位置 
        int j = 0;  // 记录遍历到的位置
        while (j < len) {
            if (nums[j] != 0) {
                if (i == j) {
                    ++i;
                    ++j;
                    continue;
                } else {
                    nums[i++] = nums[j++];
                }
            } else {
                ++j;
            }
        }
        while (i < j) {
            nums[i++] = 0;
        }
        return;
    }
};
// @lc code=end

