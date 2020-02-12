/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 * 需要理解递归的思路，maxDepth会返回当前节点的最大深度
 * 下面迭代的每一层也都会如此。
 * 做题就和做事是一样的，划清楚界限，问题就容易了
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
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
// @lc code=end

