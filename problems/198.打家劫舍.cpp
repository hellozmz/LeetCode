/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (42.59%)
 * Likes:    617
 * Dislikes: 0
 * Total Accepted:    69.7K
 * Total Submissions: 163.4K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2:
 * 
 * 输入: [2,7,9,3,1]
 * 输出: 12
 * 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int first_value = 0, second_value = 0;  // 前置位的总钱数
        int first_pos = -2, second_pos = -1;
        int money = 0;
        for (int i=0; i<nums.size(); ++i) {
            int tmp_money = 0;
            if (i - first_pos > 1) {
                tmp_money = nums[i] + first_value;
            }
            if (i - second_pos > 1) {
                tmp_money = std::max(nums[i] + second_value, tmp_money);
            }
            money = std::max(tmp_money, money);
            std::cout << money << std::endl;
            first_value = second_value;
            first_pos = second_pos;
            second_value = money;
            second_pos = i;
        }
        return money;
    }
};
// @lc code=end

