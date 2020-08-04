/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.79%)
 * Likes:    377
 * Dislikes: 0
 * Total Accepted:    96.6K
 * Total Submissions: 138.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    void inorder(TreeNode* root, std::vector<int> &result) {
        if (!root) {
            return;
        }
        if (root->left) {
            inorder(root->left, result);
        }
        result.push_back(root->val);
        if (root->right) {
            inorder(root->right, result);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        // inorder(root, result);
        auto rt = root;
        std::stack<TreeNode *> stk;
        while (rt || !stk.empty()) {
            // 一直向左遍历压栈
            while (rt) {
                stk.push(rt);
                rt = rt->left;
            }
            // 访问当前节点
            rt = stk.top();
            stk.pop();
            result.push_back(rt->val);
            // 向右迭代
            rt = rt->right;
        }
        return result;
    }
};
// @lc code=end

