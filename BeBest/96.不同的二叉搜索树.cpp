/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (69.96%)
 * Likes:    1502
 * Dislikes: 0
 * Total Accepted:    192.1K
 * Total Submissions: 274.6K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * int numTrees(int n) {
        vector<int>result(n+1,0); //Initializing vector with 0
        result[1]=result[0]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                result[i]+=result[j]*result[i-j-1]; //Calculating C(i) to use for C(i+1) and storing it in result
            }
        }
        return result[n]; //return answer
    }
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // 卡特兰数
        // c0 = 1, c(n+1) = 2(2n + 1)/(n + 2)*c(n)
        if (n <= 1) {
            return n;
        }
        long long c = 1;
        for (int i = 0; i < n; ++i) {
            c = 2 * c * (2 * i + 1) / (i + 2);
            // std::cout << "i = " << i << ", c = " << c << std::endl;
        }
        return (int) c;
    }
};
// @lc code=end

