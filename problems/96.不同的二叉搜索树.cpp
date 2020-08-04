/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (64.39%)
 * Likes:    374
 * Dislikes: 0
 * Total Accepted:    27.1K
 * Total Submissions: 42.1K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */

// @lc code=start
class Solution {
public:
    // 这完全是一道数学题
    int numTrees(int n) {
        std::vector<int> g(n+1, 0);
        g[0] = 1;
        g[1] = 1;
        int result = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                g[i] += g[j] * g[i-j-1];
            }
        }
        return g[n];
    }
};
// @lc code=end

