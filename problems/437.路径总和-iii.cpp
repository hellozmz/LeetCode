/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode-cn.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (53.42%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    18.8K
 * Total Submissions: 35.2K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树，它的每个结点都存放着一个整数值。
 * 
 * 找出路径和等于给定数值的路径总数。
 * 
 * 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 * 
 * 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
 * 
 * 示例：
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * 返回 3。和等于 8 的路径有:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3.  -3 -> 11
 * 
 * 整体分为两种情况：
 * 1.包含当前根结点
 * 2.不包含当前根结点
 * 这两种都需要直接递归，找到递归的返回条件，问题就容易解决
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int rtn = 0;
        if (!root) {
            return 0;
        }
        if (root->val == sum) {
            ++rtn;
        }

        rtn += pathSum(root->left, sum);
        rtn += pathSum(root->right, sum);

        rtn += pathNoRootSum(root->left, sum - root->val);
        rtn += pathNoRootSum(root->right, sum - root->val);

        return rtn;
    }

    int pathNoRootSum(TreeNode* root, int sum) {
        int rtn = 0;
        if (!root) {
            return 0;
        }
        if (root->val == sum) {
            ++rtn;
        }

        rtn += pathNoRootSum(root->left, sum - root->val);
        rtn += pathNoRootSum(root->right, sum - root->val);

        return rtn;
    }
};
// @lc code=end

