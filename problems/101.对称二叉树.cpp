/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool Symmetric(TreeNode* p, TreeNode* q) {
        if (!p && !q)   return true;
        if (p && q) {
            if (p->val == q->val) {
                return Symmetric(p->left, q->right) && Symmetric(p->right, q->left);
            } else {
                return false;
            }
        } else {
            return false;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return Symmetric(root, root);
    }
};
// @lc code=end

