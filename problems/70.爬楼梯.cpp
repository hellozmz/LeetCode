/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 * 斐波那契数列的问题
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)  return n;
        int f1 = 1;
        int f2 = 2;
        int fn = f1+f2;
        for (int i=2; i<n; ++i) {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};
// @lc code=end

