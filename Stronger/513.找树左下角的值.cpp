/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode.cn/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (74.34%)
 * Likes:    390
 * Dislikes: 0
 * Total Accepted:    144.5K
 * Total Submissions: 194.4K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 * 
 * 假设二叉树中至少有一个节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: root = [2,1,3]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * ⁠
 * 
 * 
 * 输入: [1,2,3,4,null,5,6,null,null,7]
 * 输出: 7
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是 [1,10^4]
 * -2^31  
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxDepth = INT_MIN;
    int result = 0;

public:
/**
 * @brief 这里采用遍历一次，在遍历的过程中，使用一个全局变量去记录树深度
 * 另外可以采用遍历两次的方法，第一次获取深度，第二次层遍历，获取第一个元素（最左）
 * 可以简化成，每次记录下层序遍历的数，然后返回value.back()[0]
 * 
 * @param root 
 * @return int 
 */
    int findBottomLeftValue(TreeNode* root) {
        helper(root, 0);
        return result;
    }

    void helper(TreeNode* root, int d) {
        if (!root->left && !root->right) {
            if (d > maxDepth) {
                maxDepth = d;
                result = root->val;
            }
        }
        // 迭代 + 回溯
        if (root->left) {
            ++d;
            helper(root->left, d);
            --d;
        }
        if (root->right) {
            ++d;
            helper(root->right, d);
            --d;
        }
    }
};
// @lc code=end

