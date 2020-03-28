/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (57.98%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 25.1K
 * Testcase Example:  '[5,2,13]'
 *
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
 * Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 * 
 * 例如：
 * 
 * 
 * 输入: 二叉搜索树:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * 输出: 转换为累加树:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 * 
 * 搜索二叉树是有序树，左中右是按照大小排序好的
 * 程序中定义的累加树是左中右依次增大的，反向递归可以解决这个问题
 * 另外为了传递数值，可以使用指针
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
    TreeNode* convertBST(TreeNode* root) {
        if (root) {
            int init_num = 0;
            convert(root, &init_num);
        }
        return root;
    }

    void convert(TreeNode* root, int* sum) {
        if (!root) {
            return;
        }
        convert(root->right, sum);

        root->val += *sum;
        *sum = root->val;

        convert(root->left, sum);
    }
};
// @lc code=end

