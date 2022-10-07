/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int result = 1;
        int curdiff = 0;
        int prediff = 0;
        for (int i = 1; i < nums.size(); ++i) {
            curdiff = nums[i] - nums[i - 1];
            // 只要保证不是连续的单调，就是可以的
            // 明明很简单，怎么做的那么复杂呢？
            if (curdiff > 0 && prediff <= 0 || curdiff < 0 && prediff >= 0) {
                ++result;
                prediff = curdiff;
            }
        }
        return result;
    }
};
// @lc code=end
