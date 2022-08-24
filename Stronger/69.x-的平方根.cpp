/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 *
 * https://leetcode.cn/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.83%)
 * Likes:    1121
 * Dislikes: 0
 * Total Accepted:    605.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '4'
 *
 * 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
 * 
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 * 
 * 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 4
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = 8
 * 输出：2
 * 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
    // 对于数据的范围自己理解的还是不行呀，int/long的范围在哪里，这个是不熟悉的
    // 刚查询了下，int/long都是使用4个字符表示，也就是32位去表示的。那么除去一个符号位，正好满足数据的要求。
    // 使用leetcode显示越界应该是leetcode的数据位数的问题
public:
    bool match(long v, long x) {
        return (v * v <= x && (v + 1) * (v + 1) > x);
    }
    int mySqrt(int x) {
        long left = 0, right = std::min(x, 65536);
        while (left <= right) {
            long mid = (left + right) / 2;
            if (mid * mid > x) {
                right = mid - 1;
            } else if (match(mid, x)) {
                return mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

