/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode.cn/problems/happy-number/description/
 *
 * algorithms
 * Easy (63.15%)
 * Likes:    1074
 * Dislikes: 0
 * Total Accepted:    305.1K
 * Total Submissions: 483.1K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 * 
 * 「快乐数」 定义为：
 * 
 * 
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为 1，那么这个数就是快乐数。
 * 
 * 
 * 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 19
 * 输出：true
 * 解释：
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 2
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> data;
        int tmp = 0;
        while (n) {
            int num = getSum(n);
            if (num == 1) {
                return true;
            }
            if (data.count(num) > 0) {
                return false;
            }
            data.insert(num);
            n = num;
        }
        return false;
    }

    int getSum(int n) {
        int result = 0;
        while (n > 0) {
            int v = n % 10;
            n = n / 10;
            result += (v * v);
        }
        return result;
    }
};
// @lc code=end

