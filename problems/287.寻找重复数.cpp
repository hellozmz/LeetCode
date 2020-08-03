/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 *
 * https://leetcode-cn.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (62.62%)
 * Likes:    394
 * Dislikes: 0
 * Total Accepted:    33.1K
 * Total Submissions: 52.8K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和
 * n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,4,2,2]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,3,4,2]
 * 输出: 3
 * 
 * 
 * 说明：
 * 
 * 
 * 不能更改原数组（假设数组是只读的）。
 * 只能使用额外的 O(1) 的空间。
 * 时间复杂度小于 O(n^2) 。
 * 数组中只有一个重复的数字，但它可能不止重复出现一次。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int left = 1, right = len - 1;      // 左边界、右边界
        int mid = (left + right) / 2;       // 向下取整的中位数，可以用来与统计个数进行比较
        int cnt = 0;
        while (left < right) {
            cnt = 0;
            mid = (left + right) / 2;
            for (auto num : nums) {
                if (num <= mid) {
                    ++cnt;
                }
            }
            // std::cout << "cnt=" << cnt << std::endl;
            // std::cout << "mid=" << mid << std::endl;

            if (cnt > mid) {        // 说明[left, right]中间有重复的数字
                right = mid;
            } else {
                left = mid + 1;
            }
            // std::cout << "left=" << left << ",right=" << right << std::endl;
        }

        return left;
    }
};
// @lc code=end

