/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.37%)
 * Likes:    1748
 * Dislikes: 0
 * Total Accepted:    424.2K
 * Total Submissions: 594.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
 * inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        return dfs(preorder, 0, len - 1, inorder, 0, len - 1);
    }

    /**
     * @brief 递归（深度搜索）
     *
     * @param preorder 前序
     * @param pb 前序开始
     * @param pe 前序结束（包括）
     * @param inorder 中序
     * @param ib 中序开始
     * @param ie 中序结束（包括）
     * @return TreeNode* 返回结果
     */
    TreeNode* dfs(vector<int>& preorder, int pb, int pe, vector<int>& inorder,
                  int ib, int ie) {
        if (ib > ie) {
            return nullptr;
        } else if (ib == ie) {
            return new TreeNode(inorder[ib]);
        } else {
            int value = preorder[pb];
            for (int i = ib; i <= ie; ++i) {
                if (value == inorder[i]) {
                    TreeNode* root = new TreeNode(value);
                    int leftLen = i - ib - 1;
                    int rightLen = ie - i - 1;
                    root->left = dfs(preorder, pb + 1, pb + 1 + leftLen,
                                     inorder, ib, i - 1);
                    root->right =
                        dfs(preorder, pe - rightLen, pe, inorder, i + 1, ie);
                    return root;
                }
            }
        }
        return nullptr;
    }
};
// @lc code=end
